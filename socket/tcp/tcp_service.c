/*************************************************************************
	> File Name: tcp_service.c
	> Author:yangkun 
	> Mail:yangkungetit@163.com 
	> Created Time: Sun 14 Jan 2018 11:11:39 PM CST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
void usage()
{
    printf("./tcp_service [ip] [port]\n");
}

int main(int argc,char* argv[])
{
    if(argc!=3)
    {
        usage();
        exit(1);
    }

    int listenfd=socket(AF_INET,SOCK_STREAM,0);
    if(listenfd<0)
    {
        perror("socket");
        exit(2);
    }

    struct sockaddr_in service;
    service.sin_family=AF_INET;
    service.sin_port=htons(atoi(argv[2]));
    service.sin_addr.s_addr=inet_addr(argv[1]);

    if(bind(listenfd,(struct sockaddr*)&(service),sizeof(service))!=0)
    {
        perror("bind");
        exit(3);
    }
    
    if(listen(listenfd,10)!=0)
    {
        perror("listen");
        exit(4);
    }

    printf("%d\n",listenfd);

    struct sockaddr_in client;
    socklen_t len=sizeof(client);
    while(1)
    {
        int socketfd=accept(listenfd,(struct sockaddr*)&client,&len);
        if(socketfd==-1)
        {
            perror("accept");
            continue;
        }
        char buf[1024];
        printf("ip[%s] port[%d]\n",inet_ntoa(client.sin_addr),ntohs(client.sin_port));
        while(1)
        {
            ssize_t size=read(socketfd,buf,sizeof(buf));
            if(size==0)
            {
                printf("client exit\n");
                break;
            }
            else if(size<0)
            {
                perror("read");
                exit(6);
            }
            else
            {
                buf[size]=0;
                printf("client:%s",buf);
            }
        }
        close(socketfd);
    }
    close(listenfd);
    return 0;
}
