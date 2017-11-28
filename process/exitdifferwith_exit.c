/*************************************************************************
	> File Name: exitdifferwith_exit.c
	> Author:yangkun 
	> Mail:yangkungetit@163.com 
	> Created Time: Tue 28 Nov 2017 01:58:33 PM CST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

void test()
{
    printf("hello world");
    sleep(3);
    exit(1);//can't flush stdio stream,insead of releasing resource.
}

void test2()
{
    printf("hello world");
    sleep(3);
    _exit(1);//stdio stream are flushed and closed.
}

int main()
{
    //test(); 
    test2();
    return 0;
}
