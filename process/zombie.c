/*************************************************************************
	> File Name: zombie.c
	> Author:Yangkun 
	> Mail:yangkungetit@163.com 
	> Created Time: Tue 21 Nov 2017 11:59:44 AM CST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>

int main()
{
    int ret=fork();
    if(ret>0)
    {
        while(1);
    }
    else if(ret==0)
    {
        printf("helloworld\n");
    }
    else
    {
        perror("fork");
    }
    return 0;
}
