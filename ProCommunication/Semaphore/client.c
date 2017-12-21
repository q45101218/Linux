/*************************************************************************
	> File Name: client.c
	> Author:yangkun 
	> Mail:yangkungetit@163.com 
	> Created Time: Thu 21 Dec 2017 11:03:13 AM CST
 ************************************************************************/

#include"commom.h"

void test()
{
    int semid=get();
    char buf[]="BBB";
    while(1)
    {
        write(1,buf,sizeof(buf));
        sleep(1);
    }
}

int main()
{
    test();
    return 0;
}
