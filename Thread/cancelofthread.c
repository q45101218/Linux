/*************************************************************************
	> File Name: cancelofthread.c
	> Author:yangkun 
	> Mail:yangkungetit@163.com 
	> Created Time: Sat 27 Jan 2018 12:15:24 AM CST
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <errno.h>

void* entriance(void* arg)
{
    while(1)
    {
        //;
        //printf("thread\n"),sleep(1);
    }
    return NULL;
}

int main()
{
    pthread_t tid;
    pthread_create(&tid, NULL, entriance, NULL);

    sleep(3);
    void* ret;
    
    //if(0 != (errno = ))
    //{
    //    printf("%s\n",strerror(errno));
    //    exit(1);
    //}
    pthread_cancel(tid);
    pthread_join(tid, &ret);

    if( ret == PTHREAD_CANCELED )
    {
        printf("success\n");
    }
    else
    {
        printf("fail\n");
    }

    return 0;
}
