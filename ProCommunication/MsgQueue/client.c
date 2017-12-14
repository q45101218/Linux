/*************************************************************************
	> File Name: client.c
	> Author:yangkun 
	> Mail:yangkungetit@163.com 
	> Created Time: Thu 14 Dec 2017 05:34:38 PM CST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include"getmsgqueue.h"

void test()
{
    int msgid=getmsgque(".",1);
    while(1)
    {
        char buf[1024]={0};
        msgreceive(msgid,buf);
        printf("service:%s",buf);
    }
}

int main()
{
    test();
    return 0;
}
