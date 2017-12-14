/*************************************************************************
	> File Name: service.c
	> Author:yangkun 
	> Mail:yangkungetit@163.com 
	> Created Time: Thu 14 Dec 2017 10:37:44 AM CST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>

void test()
{
    int openfifo=open("./MYFIFO",O_RDONLY | O_NONBLOCK);
    if(openfifo<0)
    {
        perror("open");
        exit(1);
    }
    printf("service has started successfully\n");
    while(1)
    {
        char buf[1024]={0};
        //printf("ok\n");
        ssize_t sizeofread=read(openfifo,buf,sizeof(buf));
        //printf("%d\n",sizeofread);
        if(sizeofread==0)
        {
            //printf("end of fifo\n");
            sleep(1);
        }
        else if(sizeofread<0)
        {
            perror("read");
            sleep(1);
            //exit(1);
        }
        else
        {
            printf("client say:");
            ssize_t sizeofwrite=write(1,buf,sizeof(buf));
            if(sizeofwrite<0)
            {
                perror("write");
                exit(1);
            }
        }
    }
}

int main()
{
    test();
    return 0;
}
