/*************************************************************************

	> File Name: threaddata.c
	> Author:yangkun 
	> Mail:yangkungetit@163.com 
	> Created Time: Sun 28 Jan 2018 09:09:25 PM CST
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

int g_val = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* entrance(void* arg)
{
    int i = 0;
    for(; i < 5000; i++)
    {
        pthread_mutex_lock(&mutex);
        g_val++;
        pthread_mutex_unlock(&mutex);
        usleep(1000);
    }
}

int main()
{
    //pthread_mutex_init(&mutex, NULL);

    pthread_t tid1;
    pthread_t tid2;

    int ret1 = pthread_create(&tid1, NULL, entrance, NULL);
    if( ret1 != 0 )
    {
        printf("%s\n",strerror(ret1));
        exit(1);
    }

    int ret2 = pthread_create(&tid2, NULL, entrance, NULL);
    if( ret2 != 0 )
    {
        printf("%s\n",strerror(ret2));
    }

    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);

    pthread_mutex_destroy(&mutex);

    //if(pthread_detach(tid1) != 0)
    //{
    //    printf("pthread_detach\n");
    //}

    //if(pthread_detach(tid2) != 0)
    //{
    //    printf("pthread_detach\n");
    //}

    printf("%d\n",g_val);
    return 0;
}
