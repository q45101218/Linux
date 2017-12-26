/*************************************************************************
	> File Name: signal.c
	> Author:yangkun 
	> Mail:yangkungetit@163.com 
	> Created Time: Tue 26 Dec 2017 10:48:14 PM CST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<signal.h>

void handler(int sig)
{
    printf("signal:%d\n",sig);
}

//typedef void (*handler)(void);

int main()
{
    signal(SIGINT,handler);
    while(1);
    return 0;
}
