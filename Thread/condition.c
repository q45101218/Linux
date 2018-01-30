/*************************************************************************
	> File Name: condition.c
	> Author:yangkun 
	> Mail:yangkungetit@163.com 
	> Created Time: Tue 30 Jan 2018 09:45:27 PM CST
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

pthread_cond_t con = PTHREAD_COND_INITIALIZER;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* entrance1(void* arg)
{
    while(1)
    {
        printf("throw ball\n");
        pthread_cond_signal(&con);
        sleep(1);
    }
    return NULL;
}

void* entrance2(void* arg)
{
    while(1)
    {
        pthread_cond_wait(&con, &mutex);
        printf("button\n");
        usleep(1000);
    }
}

int main()
{
    pthread_t tid1;
    pthread_t tid2;

    pthread_create(&tid1, NULL, entrance1, NULL);
    pthread_create(&tid2, NULL, entrance2, NULL);

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&con);
    return 0;
}
