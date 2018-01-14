/*************************************************************************
	> File Name: tcp_client.c
	> Author:yangkun 
	> Mail:yangkungetit@163.com 
	> Created Time: Sun 14 Jan 2018 11:16:32 PM CST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>

void usage()
{
    printf("./tcp_client [ip] [port]\n");
}

int main(int argc,char* argv)
{
    if(argc!=3)
    {
        usage();
        exit(1);
    }

    return 0;
}
