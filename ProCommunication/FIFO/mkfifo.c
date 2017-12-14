/*************************************************************************
	> File Name: mkfifo.c
	> Author:yangkun 
	> Mail:yangkungetit@163.com 
	> Created Time: Thu 14 Dec 2017 10:27:45 AM CST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>

void test()
{
    umask(0);
    int flag=mkfifo("./MYFIFO",0666);
    if(flag==-1)
    {
        perror("mkfifo");
        exit(1);
    }
    printf("make fifo successfully\n");
}

int main()
{
    test();
    return 0;
}
