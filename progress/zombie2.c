/*************************************************************************
	> File Name: zombie2.c
	> Author:Yangkun 
	> Mail:yangkungetit@163.com 
	> Created Time: Tue 21 Nov 2017 12:04:59 PM CST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>

int main()
{
    int ret=fork();
    if(ret>0)
    {
        sleep(10);
    }
    else if(ret==0)
    {
        printf("child\n");
    }
    else
    {
        perror("fork");
    }
    return 0;
}
