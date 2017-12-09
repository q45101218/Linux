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
    int fd=open("./txt.md",O_WRONLY | O_CREAT,0666);
    close(1);
    printf("file despcrition:%d\n",fd);
    close(fd);
    return 0;
}
