/*************************************************************************
	> File Name: fork.c
	> Author:Yangkun 
	> Mail:yangkungetit@163.com 
	> Created Time: Tue 21 Nov 2017 11:37:52 AM CST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>

int main()
{
    int ret=fork();
    if(ret>0)
    {
        //parent progress return child's pid;
        printf("selfpid:%d,child's pid:%d,parent's pid:%d\n",getpid(),ret,getppid());
        sleep(1);
    }
    else if(ret==0)
    {
        //child progress return 0;
        printf("selfpid:%d,parent's pid:%d\n",getpid(),getppid());
        sleep(1);
    }
    else
    {
        //if return value less than 0,fork is error
        perror("fork");
    }
    return 0;
}
