/*************************************************************************
	> File Name: tcp_client.c
	> Author:yangkun 
	> Mail:yangkungetit@163.com 
	> Created Time: Mon 15 Jan 2018 06:14:53 PM CST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<sys/scoket.h>
#include<arpa/inet.h>
#include<netinet/in.h>

void usage()
{
    printf("./tcp_client [ip] [port]\n");
}

int main(int argc,char* argv[])
{
    if(argc!=3)
    {
        usage();
        exit(1);
    }

    int fd=socket(AF_INET,SOCK_STREAM,0);
    if(fd<0)
    {
        perror("socket");
        exit(2);
    }

    struct sockeaddr_in client;
    client.sin_port=htons(atoi(argv[2]));
    client.sin_family=AF_INET;
    inet_aton(argv[1],&client.sin_addr.s_addr);

    socklen_t len=sizeof(client);
    if(connect(fd,(struct sockeaddr*)&client,len)<0)
    {
        perror("connect");
        exit(3);
    }
    printf("connect service successfully\n");
    char buf[1024];
    while(1)
    {
        ssize_t size=read(1,buf,sizeof(buf)-1);
        if(size<0)
        {
            perror("read");
            exit(4);
        }
        if(size>0)
        {
            char buf[size]=0;
            size=write(fd,buf,sizeof(buf));
            if(size<0)
            {
                perror("write");
                exit(5);
            }
        }
    }
    return 0;
}
