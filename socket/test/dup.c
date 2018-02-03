/*************************************************************************
	> File Name: dup.c
	> Author:yangkun 
	> Mail:yangkungetit@163.com 
	> Created Time: Sun 04 Feb 2018 02:23:21 AM CST
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/fcntl.h>
int main()
{
    int fd = open("./log", O_CREAT | O_RDWR);
    if(fd < 0)
    {
        perror("open"),exit(1);
    }

    //close(1);

    int ret = dup2(fd, 1);
    if(ret == -1)
    {
        perror("dup2"),exit(2);
    }

    int i = 0;
    for(; i < 10; i++)
    {
        printf("hello world\n");
    }
    close(fd);

    printf("end\n");
    return 0;
}
