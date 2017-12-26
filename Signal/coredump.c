/*************************************************************************
	> File Name: coredump.c
	> Author:yangkun 
	> Mail:yangkungetit@163.com 
	> Created Time: Tue 26 Dec 2017 07:17:59 PM CST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
    printf("%d\n",getpid());
    while(1);
    return 0;
}
