/*************************************************************************
	> File Name: sigset.c
	> Author:yangkun 
	> Mail:yangkungetit@163.com 
	> Created Time: Wed 27 Dec 2017 08:46:37 AM CST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<signal.h>
void print(sigset_t p)
{
    int i=0;
    while(i<32)
    {
        if(sigismember(&p,i))
        {
            printf("%d ",1);
        }
        else
        {
            printf("%d ",0);
        }
        i++;
        //sleep(1);
    }
    printf("\n");
}

int main()
{
    sigset_t s,p;
    sigemptyset(&s);
    sigemptyset(&p);
    sigaddset(&s,SIGINT);
    sigprocmask(SIG_BLOCK,&s,NULL);
    while(1)
    {
        sigpending(&p);
        print(p);
        sleep(1);
    }
    return 0;
}
