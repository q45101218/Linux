/*************************************************************************
	> File Name: waitpid.c
	> Author:yangkun 
	> Mail:yangkungetit@163.com 
	> Created Time: Tue 05 Dec 2017 09:39:07 AM CST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<wait.h>

int main()
{
    int ret=fork();
    if(ret>0)
    {
        int status;
        int waitvalue;
        while(waitvalue==0)
        {
            waitvalue=waitpid(-1,&status,WNOHANG);
            if(waitvalue>0)
            {
                printf("wait successful\n");
                if((status&0x7F)==0)
                {
                    printf("no erro,exit information:%d\n",(status>>8)&0xFF);
                }
                else 
                {
                    printf("erro exit,sig code:%d\n",status&0x7F);
                }
                exit(0);
            }
            else if(waitvalue==0)
            {
                sleep(1);
                printf("child is running and parent is waiting for it's child\n");
            }
            else
            {
                printf("wait erro\n");
            }
        }
    }
    else if(ret==0)
    {
        sleep(10);
        exit(5);
    }
    else
    {
        perror("fork");
        exit(3);
    }
    return 0;
}
