/*************************************************************************
	> File Name: createsgmid.c
	> Author:yangkun 
	> Mail:yangkungetit@163.com 
	> Created Time: Wed 20 Dec 2017 01:56:08 PM CST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#define PATH "."
#define PRO_ID 1

int test()
{
    key_t key=ftok(PATH,PRO_ID);
    if(key==-1)
    {
        perror("ftok");
        exit(1);
    }
    int ret=shmget(key,1024,IPC_CREAT);
    if(ret==-1)
    {
        perror("shmget");
        exit(1);
    }
    printf("no errno,and that create shared memory is successful\n");
    return ret;
}

void destory(int id)
{
    shmctl(id,IPC_RMID,NULL);
    printf("destory shared memory successfully\n");
}

int main()
{
    int id=test();
    sleep(4);
    destory(id);
    return 0;
}
