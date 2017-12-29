/*************************************************************************
	> File Name: waitchild.c
	> Author:yangkun 
	> Mail:yangkungetit@163.com 
	> Created Time: Fri 29 Dec 2017 08:52:23 PM CST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<signal.h>
void handler(int sig)
{
    pid_t pid;
    while((pid=waitpid(-1,NULL,WNOHANG))>0)
    {
        printf("success:");
        printf("pid:%d\n",pid);
    }
    printf("pid:%d\n",getpid());
}

int main()
{
    signal(SIGCHLD,handler);
    int index;
    for(index=0;index<10;index++)
    {
        int ret=fork();
        if(ret==0)
        {
            printf("%d:pid-->%d\n",index,getpid());
            exit(1);
        }
        else if(ret<0)
        {
            perror("fork");
            exit(2);
        }
    }
    while(1)
    {
        sleep(1);
    }
}
