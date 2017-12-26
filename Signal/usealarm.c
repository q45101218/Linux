/*************************************************************************
	> File Name: usealarm.c
	> Author:yangkun 
	> Mail:yangkungetit@163.com 
	> Created Time: Tue 26 Dec 2017 10:30:28 PM CST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
    alarm(1);
    int count=0;
    while(1)
    {
        count++;
    }
    return 0;
}
