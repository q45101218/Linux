/*************************************************************************
	> File Name: poll_service.c
	> Author:yangkun 
	> Mail:yangkungetit@163.com 
	> Created Time: Tue 06 Feb 2018 07:16:51 PM CST
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <poll.h>

int startup()
{
    int waitfd = socket(AF_INET, SOCK_STREAM, 0);
    if(waitfd == -1)
    {
        perror("sock");
        exit(1);
    }
    struct sockaddr_in service;
    service.sin_family = AF_INET;
    service.sin_port = htons(8080);
    service.sin_addr.s_addr = inet_addr("0");
    if( bind(waitfd, (struct sockaddr*)&service, sizeof(service)))
    {
        perror("bind");
        exit(2);
    }
    if( listen(waitfd, 10))
    {
        perror("listen");
        exit(3);
    }

    return waitfd;
}

void init(struct pollfd* p, int size)
{
    int i = 0;
    for(; i < size; i++)
    {
        p[i].fd = -1;
        p[i].events = 0;
        p[i].revents = 0;
    }
}

void add(struct pollfd* p, int size, int fd)
{
    int i = 0;
    for( ; i < size; i++)
    {
        if(p[i].fd == -1)
        {
            p[i].fd = fd;
            p[i].events = POLLIN;
            break;
        }
    }
}

int main()
{
    int sockfd = startup();
    printf("%d\n",sockfd);

    struct pollfd pfd[10];
    init(pfd, sizeof(pfd)/sizeof(pfd[0]));
    add(pfd, sizeof(pfd)/sizeof(pfd[0]), sockfd);
    while(1)
    {
        int ret = poll(pfd, sizeof(pfd)/sizeof(pfd[0]), -1);
        if(ret < 0)
        {
            perror("poll");
            continue;
        }
        else if(ret == 0)
        {
            continue;
        }
        else
        {
            int i = 0;
            for(; i < sizeof(pfd)/sizeof(pfd[0]); i++)
            {
                if(pfd[i].fd == -1 | pfd[i].revents != POLLIN)
                {
                    continue;
                }
                else
                {
                    if(pfd[i].fd == sockfd)
                    {
                        struct sockaddr_in client;
                        socklen_t len = sizeof(client);
                        int confd = accept(sockfd, (struct sockaddr*)&client, &len);
                        if(confd == -1)
                        {
                            perror("accept");
                            continue;
                        }
                        else
                        {
                            add(pfd, sizeof(pfd)/sizeof(pfd[0]), confd);
                            printf("client get line\n");
                        }
                    }
                    else
                    {
                        char buf[1024] = {0};
                        ssize_t sz = read(pfd[i].fd, buf, sizeof(buf));
                        if(sz == 0)
                        {
                            close(pfd[i].fd);
                            pfd[i].fd = -1;
                            printf("client quit\n");
                        }
                        else if(sz < 0)
                        {
                            perror("read");
                            continue;
                        }
                        else
                        {
                            printf("client say#:%s", buf);
                        }
                    }
                }
            }
        }
    }
    return 0;
}
