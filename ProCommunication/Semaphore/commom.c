/*************************************************************************
	> File Name: commom.c
	> Author:yangkun 
	> Mail:yangkungetit@163.com 
	> Created Time: Thu 21 Dec 2017 10:05:31 AM CST
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

int creatsemophore(int num,int flag)
{
    int ret=semget(getkey(),num,flag);
    if(ret==-1)
    {
        perror("semget");
        exit(1);
    }
    return ret;
}

void setvalve(int semid,int index,int value)
{
    union semun _semun;
    _semun.val=value;
    if(-1==semctl(semid,index,SETVAL,_semun))
    {
        perror("semctl");
        exit(1);
    }
    printf("set value to sem successfully\n");
}

int create(int num)
{
    return creatsemophore(num,IPC_CREAT | 0666);
}

int get()
{
    return creatsemophore(0,IPC_CREAT);
}

void cancel(int semid)
{
    if(-1==semctl(semid,1,IPC_RMID))
    {
        perror("semctl");
        exit(1);
    }
    printf("erase successfully\n");
}

void operator(int semid,int index,int op)
{
    struct sembuf sembuf;
    sembuf.sem_num=index;
    sembuf.sem_op=op;
    sembuf.sem_flg=0;
    if(-1==semop(semid,&sembuf,1))
    {
        perror("semop");
        exit(1);
    }
}

void P(int semid,int index)
{
    operator(semid,index,-1);
}

void V(int semid,int index)
{
    operator(semid,index,1);
}


