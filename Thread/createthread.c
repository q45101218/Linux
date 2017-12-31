/*************************************************************************
	> File Name: createthread.c
	> Author:yangkun 
	> Mail:yangkungetit@163.com 
	> Created Time: Sun 31 Dec 2017 07:40:22 PM CST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>
#include<sys/types.h>
void* newthread(void* para)
{
    while(1)
    {
        printf("new thread,%0x\n",pthread_self());
        sleep(1);
    }
}

int main()
{
    pthread_t threadid;
    int ret;
    if(0!=(ret=pthread_create(&threadid,NULL,newthread,NULL)))
    {
        printf("%s\n",strerror(ret));
    }
    while(1)
    {
        printf("main thread's new thread is %0x\n",threadid);
        sleep(1);
    } 
    return 0;
}
