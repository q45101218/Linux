/*************************************************************************
	> File Name: getmsgqueue.h
	> Author:yangkun 
	> Mail:yangkungetit@163.com 
	> Created Time: Thu 14 Dec 2017 02:18:54 PM CST
 ************************************************************************/

#ifndef _GETMSGQUEUE_H
#define _GETMSGQUEUE_H
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<sys/msg.h>

int creatmsgqueue();//const char* path,const int pro_id);

int getmsgque();//const char* path,const int pro_id);

void msgsend();

void msgreceive();

void msgdestory();

#endif
