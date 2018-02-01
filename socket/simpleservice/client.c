/*************************************************************************
	> File Name: client.c
	> Author:yangkun 
	> Mail:yangkungetit@163.com 
	> Created Time: Thu 21 Dec 2017 05:16:06 PM CST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/socket.h>
#include<netinet/ip.h>
#include<netinet/in.h>

void test()
{
    int fd=socket(AF_INET,SOCK_STREAM,0);
    if(fd==-1)
    {
        perror("socket");
        exit(1);
    }
    struct sockaddr_in addr;
    addr.sin_family=AF_INET;
    addr.sin_port=htons(9999);
    inet_pton(AF_INET,"127.0.0.1",&(addr.sin_addr.s_addr));
    if(-1==connect(fd,(struct sockaddr*)&addr,sizeof(addr)))
    {
        perror("connect");
        exit(1);
    }
    printf("successful\n");
    while(1)
    {
        char buf[1024]={0};
        ssize_t size=read(0,buf,sizeof(buf));
    
        if(size==0)
        {
            printf("end of screen\n");
        }
        else if(size<0)
        {
            perror("read");
            exit(1);
        }
        if(0>write(fd,buf,sizeof(buf)))
        {
            perror("write");
            exit(1);
        }
    }
    close(fd);
}

int main()
{
    test();
    return 0;
}

