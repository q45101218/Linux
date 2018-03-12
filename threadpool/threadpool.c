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
#include "condition.h"

void threadpool_init(threadpool* pool, int num)
{
    condition_init(&pool->ready);
    pool->first = NULL;
    pool->last = NULL;
    pool->count = 0;
    pool->hang = 0;
    pool->maxthread = num;
    pool->quit = 0;
}

void* rout(void* argv)
{
    threadpool* pool = (pthreadpool*)argv;
    printf("%d thread is beigining\n", thread_self());
    while(1)
    {
        condition_lock(&pool->ready);
        pool->hang++;
        while(pool->first == NULL && pool->quit == 0)
        {
            printf("%d thread is waiting\n", pthread_self());
        }
        pool->hang--;
        if(pool->first != NULL)
        {
            task* p = pool->first;
            pool->first = p->next;

            condition_unlock(&pool->ready);
            p->run(p->argv);
            condition_lock(&pool->ready);
            free(p);
        }
        if(pool->quit == 1 && pool->first == NULL)
        {
            pool->count--;
            if(pool->count == 0)
            {
                condition_signal(&pool->ready);
            }
            condition_unlock(&pool->ready);
            break;
        }
        condition_unlock(&pool->ready);
    }
    printf("%d thread has exited\n", pthread_self());
}

void threadpool_add_mZask(threadpool* p, void* (*run)(argv), void* argv)
{
    task* p = (task*)malloc(sizeof(task));
    memset(p, 0x00, sizeof(task));
    p->run = run;
    p->argv = argv;
    p->next = NULL;

    condition_lock(&pool->ready);
    if(pool->first == NULL)
    {
        pool->first = p;
    }
    else
    {
        pool->last->next = p;
    }
    pool->last = p;

    if(pool->hang > 0)
    {
        condition_signal(&pool->ready);
    }
    else if(pool->count < pool->maxthread)
    {
        pool->count++;
        pthread_t tid;
        pthread_create(&tid, NULL, rout, (void*)pool);
    }
    condition_unlock(&pool->ready);
}

void threadpool_destory(threadpool* pool)
{
    if(pool->quit == 1)
        return;
    condition_lock(&pool->ready);
    pool->quit = 1;
    if(pool->hang > 0)
    {
        condition_broadcast(&pool->ready);
    }
    while(pool->count > 0)
    {
        condition_wait(&pool->ready);
    }
    condition_unlock(&pool->ready);
    condition_destory(&pool->ready);
}
