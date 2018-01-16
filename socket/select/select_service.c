/*************************************************************************
	> File Name: select_service.c
	> Author:yangkun 
	> Mail:yangkungetit@163.com 
	> Created Time: Tue 16 Jan 2018 12:37:13 PM CST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<sys/select.h>
#include<netinet/ip.h>
static int sfd[sizeof(fd_set)*8]={-1};

int startup(char** const argv)
{
    int fd=socket(AF_INET,SOCK_STREAM,0);
    if(fd<0)
    {
        perror("socket");
        exit(1);
    }
    struct sockaddr_in service;
    
    service.sin_family=AF_INET;
    service.sin_port=htons(atoi(argv[2]));
    inet_aton(argv[1],&service.sin_addr);
    socklen_t len=sizeof(service);
    if(bind(fd,(struct sockaddr*)&service,len))
    {
        perror("bind"),exit(2);
    }

    if(listen(fd,10))
    {
        perror("listen"),exit(3);
    }

    return fd;
}

int main(int argc,char* argv[])
{
    int listenfd=startup(argv);
    sfd[0]=listenfd;
    fd_set fs;
    int fdmax=sizeof(fd_set)*8;
    while(1)
    {
        FD_ZERO(&fs);
        int i=1;
        for(;i<(fdmax);i++)
        {
            if(sfd[i]==-1)
            {
                break;
            }
            FD_SET(sfd[i],&fs);
        }
        if(select(fdmax+1,&fs,NULL,NULL,NULL)<0)
        {
            perror("select"),exit(5);
        }
        else
        {
            if(FD_ISSET(listenfd,&fs))
            {
                struct sockaddr_in client;
                socklen_t len=sizeof(client);
                int sockfd=accept(listenfd,(struct sockaddr*)&client,&len);
                if(sockfd<0)
                {
                    perror("accept");
                    exit(6);
                }
                else
                {
                    printf("client %s:%d get line\n",inet_ntoa(client.sin_addr),ntohs(client.sin_port));
                }
            }
        }
    }
    return 0;
}
