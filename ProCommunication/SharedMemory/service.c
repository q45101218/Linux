/*************************************************************************
	> File Name: service.c
	> Author:yangkun 
	> Mail:yangkungetit@163.com 
	> Created Time: Wed 20 Dec 2017 02:48:00 PM CST
 ************************************************************************/

#include"commom.h"

void service()
{
    char* buf=connection(createshm(1024));
    while(1)
    {
        char tmp[1024]={0};
        ssize_t size=read(0,tmp,sizeof(tmp));
        if(size==0)
        {
            printf("end of screen\n");
            eixt(1);
        }
        else if(size<0)
        {
            perror("read");
            exit(1);
        }
        
        printf("%s",buf);
    }
    //destory(shmid);
}
int main()
{
    service();
    return 0;
}
