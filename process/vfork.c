/*************************************************************************
	> File Name: vfork.c
	> Author:yangkun 
	> Mail:yangkungetit@163.com 
	> Created Time: Tue 28 Nov 2017 11:50:29 AM CST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>


int main()
{
   pid_t ret=vfork();
    if(ret>0)
    {
        sleep(3);
        printf("self_pid:%d-->my child_pid:%d\n",getpid(),ret);
    }
    else if(ret==0)
    {
        printf("self_pid:%d\n",getpid());
        exit(1);//calling the function it was registered,stdio&iostream are flushed and closed,file created are removed.
        //_exit();//terminates the calling process immediately
    }
    else
    {
        perror("vfork");
    }

    return 0;
}
