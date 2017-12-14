/*************************************************************************
	> File Name: common.c
	> Author:yangkun 
	> Mail:yangkungetit@163.com 
	> Created Time: Thu 14 Dec 2017 03:07:41 PM CST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include"getmsgqueue.h"
typedef struct msgbuf
{
    long mtype;
    char mtext[1024];
}
msgbuf;

int getmsg(const char* path,const int pro_id,int flag)
{
    key_t key=ftok(path,pro_id);
    int ret=msgget(key,IPC_CREAT);
    if(ret==-1)
    {
        perror("msgget");
        exit(1);
    }
    return ret;
}

int creatmsgqueue(const char* path,const int pro_id)
{
    return getmsg(path,pro_id,IPC_CREAT | 0666);
}

int getmsgque(const char* path,const int pro_id)
{
    return getmsg(path,pro_id,IPC_CREAT);
}

void msgdestroy(const char* path,const int pro_id)
{
    int msg_id=getmsg(path,pro_id,IPC_CREAT);
    int ret=msgctl(msg_id,IPC_RMID,NULL);
    if(ret<0)
    {
        perror("msgctl");
        exit(1);
    }
    printf("remove MsgQueue successfully\n");
}

void msgsend(const int msgid,size_t size,char* buf)
{
    msgbuf mb;
    strcpy(mb.mtext,buf);
    //int sz=strlen(mb.mtext);
    //printf("%d\n",sz);
    //printf("%c  1\n",mb.mtext[sz-1]);
    mb.mtype=size;
    int ret=msgsnd(msgid,(void*)&mb,sizeof(mb.mtext),0);
    if(ret==-1)
    {
        perror("msgsend");
        exit(1);
    }
    printf("send information successfully\n");
}

void msgreceive(const int msgid,char* buf)
{
    msgbuf mb;
    ssize_t ret=msgrcv(msgid,(void*)&mb,sizeof(mb.mtext),1,0);
    if(ret<0)
    {
        perror("msgrcv");
        exit(1);
    }
    strcpy(buf,mb.mtext);
}

