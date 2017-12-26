/*************************************************************************
	> File Name: kill.c
	> Author:yangkun 
	> Mail:yangkungetit@163.com 
	> Created Time: Tue 26 Dec 2017 08:13:01 PM CST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>


//different with kill() and raise(),kill() can send signal to pid,but raise() only send signal to self.
int main()
{
    while(1)
    {
        sleep(5);
        //kill(getpid(),SIGKILL);
        //kill(getpid(),SIGSTOP);
        raise(SIGKILL);
    }
    return 0;
}
