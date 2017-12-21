/*************************************************************************
	> File Name: client.c
	> Author:yangkun 
	> Mail:yangkungetit@163.com 
	> Created Time: Wed 20 Dec 2017 02:59:28 PM CST
 ************************************************************************/

#include"commom.h"

void client()
{
    char* buf=connection(getshmid());
    while(1)
    {
        ssize_t size=write(1,buf,strlen(buf));
    }
}

int main()
{
    client();
    return 0;
}
