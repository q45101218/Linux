/*************************************************************************
	> File Name: thread.c
	> Author:yangkun 
	> Mail:yangkungetit@163.com 
	> Created Time: Tue 02 Jan 2018 02:40:29 PM CST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>

void* handler(void* parameter)
{
    printf("handler%lu\n",pthread_self());
    sleep(3);
}

int main()
{
    pthread_t thread1;
    pthread_t thread2;
    printf("main:%lu\n",pthread_self());
    int ret1=pthread_create(&thread1,NULL,handler,NULL);
    int ret2=pthread_create(&thread2,NULL,handler,NULL);
    if(ret1!=0)
    {
        printf("%s",strerror(ret1));
        exit(1);
    }
    if(ret2!=0)
    {
        printf("%s",strerror(ret2));
        exit(1);
    }
    if((ret1=pthread_join(thread1,NULL))!=0)
    {
        printf("%s",strerror(ret1));
    }
    if((ret2=pthread_join(thread2,NULL))!=0)
    {
        printf("%s",strerror(ret2));
    }
    printf("main:%lu\n",pthread_self());
    return 0;
}
