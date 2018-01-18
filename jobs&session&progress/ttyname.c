/*************************************************************************
	> File Name: ttyname.c
	> Author:yangkun 
	> Mail:yangkungetit@160.com 
	> Created Time: Thu 18 Jan 2018 05:08:52 PM CST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
    printf("fd:0->%s\n",ttyname(0));
    printf("fd:1->%s\n",ttyname(1));
    printf("fd:2->%s\n",ttyname(2));
    return 0;
}
