/*************************************************************************
	> File Name: check.c
	> Author:yangkun 
	> Mail:yangkungetit@163.com 
	> Created Time: Fri 02 Feb 2018 01:12:24 AM CST
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

void* thread1(void* arg)
{
    void* p = malloc(sizeof(char*));
    void** p1 = &p;
    p = inet_ntoa(((struct sockaddr_in*)arg)->sin_addr);
    printf("thread1 : %s , %0x , %0x\n",(char*)p, &(*(char*)p), *(char**)p1);
    return p;
}

void* thread2(void* arg)
{
    char* p;
    p = inet_ntoa(((struct sockaddr_in*)arg)->sin_addr);
    char** p1 = &p;
    printf("thread2 : %s , %0x, %0x\n", p, &(*(char*)p), *p1);
    return NULL;
}

int main()
{
    pthread_t tid1,tid2;
    struct sockaddr_in addr1;
    struct sockaddr_in addr2;

    addr1.sin_addr.s_addr = 0;
    addr2.sin_addr.s_addr = 0xffffffff;
    pthread_create(&tid1, NULL, thread1, &addr1);
    sleep(1);
    pthread_create(&tid2, NULL, thread2, &addr2);

    void* p = NULL;
    void** p1 = &p;
    pthread_join(tid1, &p);
    pthread_join(tid2, NULL);

    printf("%s , %0x, %0x\n",p ,&(*(char*)p), *p1);
    return 0;
}
