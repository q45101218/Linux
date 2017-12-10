/*************************************************************************
	> File Name: filetostdout.c
	> Author:yangkun 
	> Mail:yangkungetit@163.com 
	> Created Time: Sun 10 Dec 2017 07:07:05 PM CST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main()
{
    int fd=open("./txt.md",O_RDONLY);
    if(fd<0)
    {
        perror("open");
        exit(1);
    }

    char buf[1024]={0};
    ssize_t size=read(fd,buf,sizeof(buf)-1);
    if(size<0)
    {
        perror("read");
        exit(2);
    }

    write(1,buf,sizeof(buf));
    close(1);
    return 0;
}
