/*************************************************************************
	> File Name: tinyhttpd.h
	> Author:yangkun 
	> Mail:yangkungetit@163.com 
	> Created Time: Thu 18 Jan 2018 07:44:49 AM CST
 ************************************************************************/

#ifndef _TINYHTTPD_H
#define _TINYHTTPD_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <errno.h>
#include <string.h>

#define SUCCESS 0
#define NOTICE  1
#define WARNING 2
#define ERROR   3
#define FATAL   4
#define SIZE    1024
int startup(const char* ip, int port);
void print_log(const char* msg, int level);
void* handler_request(void* arg);
#endif
