/*************************************************************************
	> File Name: commom.h
	> Author:yangkun 
	> Mail:yangkungetit@163.com 
	> Created Time: Wed 20 Dec 2017 02:24:27 PM CST
 ************************************************************************/

#ifndef _COMMOM_H
#define _COMMOM_H
#include<stdlib.h>
#include<stdio.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/shm.h>

#define PATH "."
#define PRO_ID 1

key_t getkey();
int getshm();
int createshm();
int getshmid();
void destory();
#endif
