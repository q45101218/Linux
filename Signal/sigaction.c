/*************************************************************************
	> File Name: sigaction.c
	> Author:yangkun 
	> Mail:yangkungetit@163.com 
	> Created Time: Fri 29 Dec 2017 08:41:37 PM CST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<signal.h>
void handler(int sig)
{
    printf("%d\n",sig);
}

int main()
{
    struct sigaction newsig;
    struct sigaction oldsig;
    newsig.sa_handler=handler;
    sigemptyset(&newsig.sa_mask);
    newsig.sa_flags=0;
    sigaction(SIGINT,&newsig,&oldsig);
    while(1)
    {}
    return 0;
}
