/*************************************************************************
	> File Name: simulateassert.c
	> Author:yangkun 
	> Mail:yangkungetit@163.com 
	> Created Time: Tue 26 Dec 2017 08:53:55 PM CST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

void Assert(int* ptr)
{
    if(ptr==0)
    {
        abort();
    }
}

int main()
{
    int* ptr=NULL;
    Assert(ptr);
    return 0;
}
