/*************************************************************************
	> File Name: condition.h
	> Author:yangkun 
	> Mail:yangkungetit@163.com 
	> Created Time: 2018年03月10日 星期六 17时02分44秒
 ************************************************************************/

#ifndef _CONDITION_H
#define _CONDITION_H

#include <pthread.h>
typedef struct condition
{
    pthread_mutex_t mutex;
    pthread_cond_t cond;
}condition;

void condition_init(condition* cond);
void condition_lock(condition* cond);
void condition_unlock(condition* cond);
void condition_wait(condition* cond);
void condition_signal(condition* cond);
void condition_broadcast(condition* cond);
void condition_destory(condition* cond);
#endif
