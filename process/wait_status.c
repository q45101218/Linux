/*************************************************************************
	> File Name: wait_status.c
	> Author:yangkun 
	> Mail:yangkungetit@163.com 
	> Created Time: Tue 05 Dec 2017 08:49:15 AM CST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<wait.h>

int main()
{
    pid_t ret=fork();
    int status;
    if(ret>0)
    {
        printf("wait child pid\n");
        
        int waitreturnval=wait(&status);
        if(waitreturnval>0 && (status&0x7F)==0)
        {
            printf("child pid done with on erro,exit code:%d\n",(status>>8)&0xFF);
        }
        else if(waitreturnval>0)
        {
            printf("erro exit,erro signal:%d\n",(status&0x7F));
        }
    }
    else if(ret==0)
    {
        sleep(10);
        exit(1);
    }
    else
    {
        perror("fork");
    }
    return 0;
}

