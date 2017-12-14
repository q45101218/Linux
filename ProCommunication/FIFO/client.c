/*************************************************************************
	> File Name: client.c
	> Author:yangkun 
	> Mail:yangkungetit@163.com 
	> Created Time: Thu 14 Dec 2017 10:56:40 AM CST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
void test()
{
    int openfd=open("./MYFIFO",O_WRONLY | O_NONBLOCK);
    if(openfd<0)
    {
        perror("open");
        exit(1);
    }
    printf("open client successfully\n");
    while(1)
    {
        char buf[1024]={0};
        ssize_t sizeofread=read(0,buf,sizeof(buf));
        if(sizeofread==0)
        {
            printf("end of screen\n");
            exit(1);
        }
        else if(sizeofread<0)
        {
            perror("read");
            exit(1);
        }
        else
        {
            ssize_t sizeofwrite=write(openfd,buf,sizeof(buf));
            if(sizeofwrite<0)
            {
                perror("write");
                //exit(1);
                sleep(1);
            }
            printf("send successfully\n");
        }
    }
}

int main()
{
    test();
    return 0;
}
