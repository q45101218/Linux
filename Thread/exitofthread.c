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
    int retval=1;
    pthread_exit(&retval);
}

int main()
{
    pthread_t thread;
    int ret=pthread_create(&thread,NULL,function,NULL);
    if(ret!=0)
    {
        printf("%s",strerror(ret));
    }
    void* retvalp;
    ret=pthread_join(thread,&retvalp);
    if(ret!=0)
    {
        printf("%s",strerror(ret));
    }
    printf("%d\n",*(int*)retvalp);
    return 0;
}
