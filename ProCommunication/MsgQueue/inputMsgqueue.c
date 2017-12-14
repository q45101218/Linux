/*************************************************************************
	> File Name: inputMsgqueue.c
	> Author:yangkun 
	> Mail:yangkungetit@163.com 
	> Created Time: Thu 14 Dec 2017 07:01:08 PM CST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include"getmsgqueue.h"

int main()
{
    int msgid=getmsgque(".",1);
    while(1)
    {
        char buf[1024]={0};
        read(0,buf,sizeof(buf));
        msgsend(msgid,sizeof(buf),buf);
    }
    return 0;
}
