/*************************************************************************
	> File Name: threadjoin.c
	> Author:yangkun 
	> Mail:yangkungetit@163.com 
	> Created Time: Sun 28 Jan 2018 10:27:53 PM CST
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

void* entrance(void* arg)
{
    sleep(3);
}

int main()
{
    pthread_t tid;

    int ret = pthread_create(&tid, NULL, entrance, NULL);
    if(ret != 0)
    {
        printf("%s\n",strerror(ret));
        exit(1);
    }

    ret = pthread_join(tid, NULL);

    if(ret != 0)
    {
        printf("%s\n",strerror(ret));
    }
    return 0;
}
