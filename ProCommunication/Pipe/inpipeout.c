/*************************************************************************
	> File Name: pipe.c
	> Author:yangkun 
	> Mail:yangkungetit@163.com 
	> Created Time: Mon 11 Dec 2017 10:13:14 PM CST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<string.h>

void test1()
{
    int pfd[2];
    int ret=pipe(pfd);
    if(ret=0)
    {
        perror("pipe");
        exit(1);
    }
    printf("pipe is opened\n");
    
    while(1)
    {
        char buf[1024]={0};
        ssize_t sizeofreadstdin=read(0,buf,sizeof(buf));
        if(sizeofreadstdin==0)
        {
            printf("end of stdin\n");
            exit(1);
        }
        else if(sizeofreadstdin<0)
        {
            perror("read");
            exit(1);
        }
        else
        {
            ssize_t sizeofwritepipe=write(pfd[1],buf,sizeof(buf));
            if(sizeofwritepipe<=0)
            {
                perror("write");
                exit(1);
            }
            else
            {
                char bufofpipe[1024];
                ssize_t sizeofreadpipe=read(pfd[0],bufofpipe,sizeof(bufofpipe));
                if(sizeofreadpipe==0)
                {
                    printf("read end of pipe\n");
                    exit(1);
                }
                else if(sizeofreadpipe<0)
                {
                    perror("read");
                    exit(1);
                }
                else
                {
                    printf("%s",bufofpipe);
                    ssize_t sizeofwritestdout=write(1,bufofpipe,sizeof(bufofpipe));
                }
            }
        }
    }
}


int main()
{
    test1();
    return 0;
}
