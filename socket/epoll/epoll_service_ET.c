/*************************************************************************
	> File Name: epoll_service_ET.c
	> Author:yangkun 
	> Mail:yangkungetit@163.com 
	> Created Time: Fri 09 Feb 2018 11:51:44 PM CST
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/epoll.h>
#include <errno.h>
void usage(char* argv)
{
    printf("Usage\t:\t%s [ ip ] [ port ]");
    exit(1);
}

int startup(char* argv1, char* argv2)
{
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock < 0)
    {
        perror("socket");
        exit(2);
    }

    struct sockaddr_in service;
    service.sin_family = AF_INET;
    service.sin_port = htons(atoi(argv2));
    inet_aton(argv1, &service.sin_addr);

    if(0 > bind(sock, (struct sockaddr*)&service, sizeof(service)))
    {
        perror("bind");
        exit(3);
    }

    if(listen(sock, 10) < 0)
    {
        perror("listen");
        exit(4);
    }

    return sock;
}

void setnonblock(int fd)
{
    int mod = fcntl(fd, F_GETFL);
    if(mod < 0)
    {
        perror("fcntl");
        exit(6);
    }
    if(fcntl(fd, F_SETFL, mod | O_NONBLOCK) < 0)
    {
        perror("fcntl");
        exit(7);
    }
}

ssize_t ReadForFd(int fd, char buf[])
{
    ssize_t size = 0;
    size_t total_size = 0;
    while(1)
    {
        size = read(fd, buf + total_size, 1024);
        total_size += size;
        if( size < 1024 || errno == EAGAIN )
        {
            break;
        }
    }
    return total_size;
}

int main(int argc, char* argv[])
{
    if( argc != 3 )
    {
        usage(argv[1]);
    }

    int sock = startup(argv[1], argv[2]);
    printf("%d\n", sock);
    
    int efd = epoll_create(10);
    if(efd < 0)
    {
        perror("epoll_create");
        exit(5);
    }
    setnonblock(sock);

    struct epoll_event evn;
    evn.data.fd = sock;
    evn.events = EPOLLIN | EPOLLET;

    if( epoll_ctl(efd, EPOLL_CTL_ADD, sock, &evn) < 0)
    {
        perror("epoll_ctl");
        exit(8);
    }

    struct epoll_event evns[10];
    while(1)
    {
        int ret = epoll_wait(efd, evns, 10, -1);
        if( ret <= 0 )
        {
            perror("epoll_wait");
            continue;
        }
        int index = 0;
        for(; index < ret; index++)
        {
            if( evns[index].events == EPOLLIN )
            {
                if( evns[index].data.fd == sock )
                {
                    struct sockaddr_in client;
                    socklen_t len = sizeof(client);
                    int sfd = accept(sock, (struct sockaddr*)&client, &len);
                    if( sfd < 0 )
                    {
                        perror("accept");
                        continue;
                    }
                    struct epoll_event ev;
                    ev.data.fd = sfd;
                    ev.events = EPOLLIN | EPOLLET;
                    if( epoll_ctl(efd, EPOLL_CTL_ADD, sfd, &ev) < 0)
                    {
                        perror("epoll_ctl");
                        continue;
                    }
                }
                else
                {
                    char buf[1024];
                    ssize_t sz = ReadForFd(evns[index].data.fd, buf);
                    if( sz < 0 )
                    {
                        perror("read");
                        continue;
                    }
                    else if( sz == 0 )
                    {
                        if( epoll_ctl(efd, EPOLL_CTL_DEL, evns[index].data.fd, NULL) < 0)
                        {
                            perror("epoll_ctl");
                            exit(9);
                        }
                        close(evns[index].data.fd);
                        printf("client off line\n");
                    }
                    else
                    {
                        printf("%s", buf);
                    }
                }
            }
        }
    }
    return 0;
}
