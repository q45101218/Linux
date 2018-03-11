/*************************************************************************
	> File Name: threadpool.c
	> Author:yangkun 
	> Mail:yangkungetit@163.com 
	> Created Time: 2018年03月11日 星期日 21时13分01秒
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "threadpool.h"

void threadpool_init(threadpool* pool, int num)
{
    condition_init(&pool->ready);
    pool->first = NULL;
    pool->last = NULL;
    pool->conut = 0;
    pool->hang = 0;
    pool->maxthread = num;
    pool->quit = 0;
}

void* rout(void* argv)
{
    threadpool* pool =  
}
