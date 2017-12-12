/*************************************************************************
	> File Name: ParentPipeChild.c
	> Author:yangkun 
	> Mail:yangkungetit@163.com 
	> Created Time: Tue 12 Dec 2017 09:22:57 AM CST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<wait.h>

void test()
{
    int pfd[2];
    int suc=pipe(pfd);
    if(suc!=0)
    {
        perror("pipe");
        exit(1);
    }
    printf("pipe is ok\n");

    int ret=fork();
    if(ret==0)
    {
        close(pfd[0]);
        while(1)
        {
            char bufofchild[1024]={0};
            ssize_t sizeifreadstdin=read(0,bufofchild,sizeof(bufofchild));
            if(sizeifreadstdin==0)
            {
                printf("end of stdin\n");
            }
            else if(sizeifreadstdin<0)
            {
                perror("read");
                exit(1);
            }

            ssize_t sizeofwritepipe=write(pfd[1],bufofchild,sizeof(bufofchild));
            if(sizeofwritepipe<=0)
            {
                perror("write");
                exit(1);
            }
            else
            {
               printf("writing in pipe is ok\n"); 
            }
        }
    }
    else if(ret>0)
    {
        close(pfd[1]);
        int status;
        while(1)
        {
            printf("parent is ok\n");
            char bufofparent[1024];
            ssize_t sizeofreadpipe=read(pfd[0],bufofparent,sizeof(bufofparent));
            if(sizeofreadpipe==0)
            {
                printf("end of pipe\n");
                exit(1);
            }
            else if(sizeofreadpipe<0)
            {
                perror("read");
                exit(1);
            }
            else
            {
                printf("child say:%s",bufofparent);
            }
            int waitret=waitpid(-1,&status,WNOHANG);
            if(waitret>0)
            {
                printf("waiting child is done");
                exit(0);
            }
            if(waitret==-1)
            {
                perror("wait");
                exit(1);
            }
        }
    }
    else
    {
        perror("fork");
        exit(1);
    }
}

int main()
{
    test();
    return 0;
}
