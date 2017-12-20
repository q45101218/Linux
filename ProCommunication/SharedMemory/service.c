/*************************************************************************
	> File Name: service.c
	> Author:yangkun 
	> Mail:yangkungetit@163.com 
	> Created Time: Wed 20 Dec 2017 02:48:00 PM CST
 ************************************************************************/

#include"commom.h"

void service()
{
    int shmid=createshm();
    sleep(3);
    destory(shmid);
}
int main()
{
    service();
    return 0;
}
