/*************************************************************************
	> File Name: service.c
	> Author:yangkun 
	> Mail:yangkungetit@163.com 
	> Created Time: Thu 14 Dec 2017 04:02:07 PM CST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include"getmsgqueue.h"

#define PATH "."
#define PRO_ID 1

void test()
{
    int msgid=creatmsgqueue(PATH,PRO_ID);
    while(1)
    {
        char buf[1024]={0};
        ssize_t sizeofread=read(0,buf,sizeof(buf));
        if(sizeofread==0)
        {
            printf("end of screen\n");
        }
        else if(sizeofread<0)
        {
            perror("read");
            exit(1);
        }
        else
        {
            msgsend(msgid,sizeof(buf),buf);
        }
    }
    msgdestroy(PATH,PRO_ID);
}

int main()
{
    test();
    return 0;
}
