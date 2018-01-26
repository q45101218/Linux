/*************************************************************************
	> File Name: exitofthread.c
	> Author:yangkun 
	> Mail:yangkungetit@163.com 
	> Created Time: Wed 03 Jan 2018 02:28:34 PM CST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>

void* function(void* parameter)
{
    void* retval = malloc(sizeof(int));
    *(int*)retval = 5;
    pthread_exit(retval);
}

int main()
{
    pthread_t thread;
    int ret=pthread_create(&thread,NULL,function,NULL);
    if(ret!=0)
    {
        printf("%s\n",strerror(ret));
    }

    void* retval = NULL;
    ret=pthread_join(thread, &retval);
    if(ret!=0)
    {
        printf("%s",strerror(ret));
    }
    printf("%d\n",*(int*)retval);
    return 0;
}
