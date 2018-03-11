/*************************************************************************
	> File Name: pthreadpool.h
	> Author:yangkun 
	> Mail:yangkungetit@163.com 
	> Created Time: 2018年03月10日 星期六 16时16分03秒
 ************************************************************************/

#ifndef _PTHREADPOOL_H
#define _PTHREADPOOL_H

#include "condition.h"

typedef task
{
    void* (*run) (void* argv); //回调函数
    void* argv;
    struct task* next;
}task;

typedef struct threadpool
{
    condition_t ready;
    task* first;
    task* last;
    int count; //当前线程数
    int hang; //当前空闲线程数
    int maxthread; //允许最大线程数
    int quit; //线程退出标记
}threadpool;

//创建线程并且初始化
void threadpoll_init(threadpool* tp, int count);
//向线程池分配任务
void threadpool_add_task(threadpool* tp, void* (*run) (void* argv), void* argv);
//销毁线程池
void threadpool_destory(threadpool* tp);
#endif
