/*************************************************************************
	> File Name: commom.h
	> Author:yangkun 
	> Mail:yangkungetit@163.com 
	> Created Time: Thu 21 Dec 2017 10:23:55 AM CST
 ************************************************************************/

#ifndef _COMMOM_H
#define _COMMOM_H
#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<sys/sem.h>
#include<sys/ipc.h>

#define PATH "./"
#define PRO_ID 1

union semun {
    int              val;    /* Value for SETVAL */
    struct semid_ds *buf;    /* Buffer for IPC_STAT, IPC_SET */
    unsigned short  *array;  /* Array for GETALL, SETALL */
    struct seminfo  *__buf;  /* Buffer for IPC_INFO(Linux-specific) */
};

int create();
int get();
void cancel();

#endif
