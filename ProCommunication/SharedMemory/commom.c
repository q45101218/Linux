/*************************************************************************
	> File Name: commom.c
	> Author:yangkun 
	> Mail:yangkungetit@163.com 
	> Created Time: Wed 20 Dec 2017 02:27:34 PM CST
 ************************************************************************/

#include"commom.h"

key_t getkey()
{
    key_t key=ftok(PATH,PRO_ID);
    if(key==-1)
    {
        perror("ftok");
        exit(1);
    }
    return key;
}

int getshm(key_t key,int flag,int size)
{
    int ret=shmget(key,size,flag);
    if(ret==-1)
    {
        perror("shmget");
        exit(1);
    }
    return ret;
}

int createshm(int size)
{
    return getshm(getkey(),IPC_CREAT | IPC_EXCL | 0666,size);
}

int getshmid()
{
    return getshm(getkey(),IPC_CREAT,0);
}

void destory(int id)
{
    int ret=shmctl(id,IPC_RMID,NULL);
    if(ret==-1)
    {
        perror("shmctl");
        exit(1);
    }
    printf("successful\n");
}

char* connection(int shmid)
{
    char* ptr=(char*)shmat(shmid,NULL,0);
    if(*(int*)ptr==-1)
    {
        perror("shmat");
        exit(1);
    }
    return ptr;
}

void disconnection(void* ptr)
{
    int ret=shmdt(ptr);
    if(ret==-1)
    {
        perror("shmdt");
        exit(1);
    }
    printf("disconnecte successfully\n");
}
