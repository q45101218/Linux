/*************************************************************************
	> File Name: mesqueue.c
	> Author:yangkun 
	> Mail:yangkungetit@163.com 
	> Created Time: Thu 21 Dec 2017 01:57:48 PM CST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<mqueue.h>

void test()
{
    mqd_t ret=mq_open("/mequeue",O_CREAT,S_IRUSR|S_IWUSR,NULL);
    if(ret==-1)
    {
        perror("mq_open");
        exit(1);
    }
    printf("open mesqueue successfully\n");
    sleep(1);
    mq_unlink("/mequeue");
    mq_unlink("/me");
    if(-1==mq_close(ret))
    {
        perror("mq_close"),exit(1);
    }
    printf("easy way\n");
}

int main()
{
    test();
    return 0;
}
