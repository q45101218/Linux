/*************************************************************************
	> File Name: wait.c
	> Author:yangkun 
	> Mail:yangkungetit@163.com 
	> Created Time: Tue 28 Nov 2017 01:38:11 PM CST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<wait.h>

int main()
{
    pid_t ret=fork();

    if(ret<0)
    {
        perror("fork");
    }
    else if(ret==0)
    {
        printf("child process:%d is running\n",getpid());
        sleep(3);
        printf("child process has done\n");
    }
    else
    {
        printf("%d:begin to wait child process\n",getpid());
        printf("wait succeed-->pid:%d\n",wait(NULL));
    }
    return 0;
}
