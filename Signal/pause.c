/*************************************************************************
	> File Name: pause.c
	> Author:yangkun 
	> Mail:yangkungetit@163.com 
	> Created Time: Thu 28 Dec 2017 09:41:55 PM CST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
    alarm(3);
    pause();
    printf("after pause\n");
    return 0;
}
