/*************************************************************************
	> File Name: detachthread.c
	> Author:yangkun 
	> Mail:yangkungetit@163.com 
	> Created Time: Sun 28 Jan 2018 05:40:36 PM CST
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
void* entrance(void* arg)
{
    pthread_detach(pthread_self());
    printf("thread 2\n");
    sleep(1);
    //exit(0);
    return NULL;
}

int main()
{
    pthread_t tid;
    int ret = pthread_create(&tid, NULL, entrance, NULL);
    if(ret != 0)
    {
        printf("%s",strerror(ret));
        exit(1);
    }

    sleep(3);

    ret = pthread_join(tid, NULL);
    if(ret == 0)
    {
        printf("success\n");
    }
    else
    {
        printf("%d\n",ret);
        printf("%s\n",strerror(ret));
    }

    return 0;
}

//int main()
//{
//    pthread_t tid;
//    int ret = pthread_create(&tid, NULL, entrance, NULL);
//
//    if(ret != 0)
//    {
//        perror("thread_create");
//        exit(1);
//    }
//
//    pthread_detach(tid);
//    
//    sleep(5);
//
//    printf("thread 1 exit\n");
//
//    return 0;
//}
