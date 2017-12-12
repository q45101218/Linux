/*************************************************************************
	> File Name: pipeonlyonefd.c
	> Author:yangkun 
	> Mail:yangkungetit@163.com 
	> Created Time: Tue 12 Dec 2017 10:10:08 AM CST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>

void test()
{
    int pfd[2];
    //int ret=pipe(pfd);
    int ret=pipe2(pfd,O_NONBLOCK);
    if(ret!=0)
    {
        perror("pipe");
        exit(1);
    }
    printf("pipe is ready\n");
    char buf[1024];
    close(pfd[1]);
    while(1)
    {
        if(-1==read(pfd[0],buf,1024))
        {
            perror("read");
            exit(1);
        }
    }
}

void test2()
{
    int pfd[2];
    //int ret=pipe(pfd);
    int ret=pipe2(pfd,O_NONBLOCK);
    if(ret!=0)
    {
        perror("pipe");
        exit(1);
    }
    printf("pipe is ready\n");
    //close(pfd[0]);
    char buf[1024];
    while(1)
    {
        if(-1==write(pfd[1],buf,1024))
        {
            perror("write");
            exit(1);
        }
    }
}

int main()
{
    test2();
    return 0;
}
