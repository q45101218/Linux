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

void usage()
{
    printf("./tcp_service [ip] [port]\n");
}

int main(int argc,char* argv)
{
    if(argc!=3)
    {
        usage();
        exit(1);
    }

    int socketfd=socket(AF_INET,SOCK_STREAM,0);
    if(socketfd<0)
    {
        perror("socket");
        exit(2);
    }

    return 0;
}
