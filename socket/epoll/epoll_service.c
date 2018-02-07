/*************************************************************************
	> File Name: epoll_service.c
	> Author:yangkun 
	> Mail:yangkungetit@163.com 
	> Created Time: Thu 08 Feb 2018 01:05:02 AM CST
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/epoll.h>

int startup()
{
    int sockfd = socket( AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0)
    {
        perror("socket");
        exit(1);
    }

    struct sockaddr_in service;
    service.sin_family = AF_INET;
    service.sin_port = htons(8080);
    inet_aton("0", &(service.sin_addr));

    if( 0 > bind(sockfd, (struct sockaddr*)&service, sizeof(service)))
    {
        perror("bind");
        exit(2);
    }

    if( 0 > listen(sockfd, 10))
    {
        perror("listen");
        exit(3);
    }
    return sockfd;
}

int main()
{
    int waitfd = startup();
    printf("%d\n",waitfd);
    int efd = epoll_create(10);
    if( efd < 0 )
    {
        perror("epoll_create");
        exit(4);
    }

    struct epoll_event event;
    event.events = EPOLLIN;
    event.data.fd = waitfd;
    if(epoll_ctl(efd, EPOLL_CTL_ADD, waitfd, &event) < 0)
    {
        perror("epoll_ctl");
        exit(5);
    }
    struct epoll_event events[10];
    while(1)
    {
        int size = epoll_wait(efd, events, sizeof(events)/sizeof(events[0]), -1);
        if(size < 0)
        {
            perror("epoll_wait");
            continue;
        }
        int index = 0;
        for( ; index < size; index++)
        {
            if( events[index].events == EPOLLIN )
            {
                if( events[index].data.fd == waitfd )
                {
                    struct sockaddr client;
                    socklen_t len = sizeof(client);
                    int afd = accept(waitfd, (struct sockaddr*)&client, &len);
                    if(afd < 0)
                    {
                        perror("accept");
                        continue;
                    }
                    struct epoll_event ev;
                    ev.data.fd = afd;
                    ev.events = EPOLLIN;
                    if( epoll_ctl(efd, EPOLL_CTL_ADD, afd, &ev) < 0)
                    {
                        perror("epoll_ctl");
                        close(afd);
                        continue;
                    }
                    printf("client get line\n");
                }
                else
                {
                    char buf[1024] = {0};
                    ssize_t sz = read(events[index].data.fd, buf, sizeof(buf));
                    if( sz < 0 )
                    {
                        perror("read");
                        break;
                    }
                    else if( sz == 0 )
                    {
                        if(epoll_ctl(efd, EPOLL_CTL_DEL, events[index].data.fd, NULL) < 0)
                        {
                            perror("epoll_ctl");
                            exit(6);
                        }
                        close(events[index].data.fd);
                        printf("client line off\n");
                    }
                    else
                    {
                        printf("%s",buf);
                    }
                }
            }
        }
    }
    return 0;
}
