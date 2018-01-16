/*************************************************************************
	> File Name: select_client.c
	> Author:yangkun 
	> Mail:yangkungetit@163.com 
	> Created Time: Tue 16 Jan 2018 06:18:21 PM CST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<netinet/ip.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>

int main(int argc,char* argv[])
{
    int sockfd=socket(AF_INET,SOCK_STREAM,0);
    if(sockfd<0)
    {
        perror("socket"),exit(1);
    }

    struct sockaddr_in client;
    client.sin_family=AF_INET;
    client.sin_port=htons(atoi(argv[2]));
    client.sin_addr.s_addr=inet_addr(argv[1]);
    if(0>connect(sockfd,(struct sockaddr*)&client,sizeof(client)))
    {
        perror("connect"),exit(2);
    }
    char buf[1024];
    while(1)
    {
        ssize_t size=read(0,buf,sizeof(buf)-1);
        if(size==0)
        {
            printf("bad\n"),exit(3);
        }
        else if(size<0)
        {
            perror("read"),exit(4);
        }
        else
        {
            buf[size]=0;
            size=write(sockfd,buf,sizeof(buf)-1);
            if(size<0)
            {
                perror("write"),exit(5);
            }
            if(size==0)
            {
                printf("buf are full\n"),exit(6);
            }
        }
    }
    close(sockfd);
    return 0;
}
