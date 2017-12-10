/*************************************************************************
	> File Name: sysopenfile.c
	> Author:yangkun 
	> Mail:yangkungetit@163.com 
	> Created Time: Sat 09 Dec 2017 09:33:12 PM CST
 ************************************************************************/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
    close(1);
    int fd=open("./txt.md",O_WRONLY | O_CREAT,0666);
    if(fd<0)
    {
        perror("open");
        exit(1);
    }

    printf("file despcrition:%d\n",fd);
    ssize_t size=write(1,"hello world\n",12);
    if(size<0)
    {
        perror("write");
        close(fd);
        exit(1);
    }
    close(fd);
    return 0;
}
