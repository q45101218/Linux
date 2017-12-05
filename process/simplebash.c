/*************************************************************************
	> File Name: simplebash.c
	> Author:yangkun 
	> Mail:yangkungetit@163.com 
	> Created Time: Tue 05 Dec 2017 10:18:28 AM CST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<wait.h>

void Resolve(char* buf,char* argv[])
{
    char status=1;
    int index=0;
    int i=0;
    int size=strlen(buf);
    for(index;index<size;index++)
    {
        if((buf[index]!=' ')&&status)
        {
            argv[i]=&buf[index];
            i++;
            status=0;
        }
        if((buf[index]!=' ')&&(buf[index+1]==' '))
        {
            buf[index+1]='\0';
            index++;
            status=1;
        }
    }
}

void test(char* argv[])
{
    int index=0;
    while(argv[index]!=NULL)
    {
        printf("%s   ",argv[index]);
        index++;
    }
}

void Mybash()
{
    while(1)
    {
        char buf[1024]={0};
        char* argv[10]={NULL};
        printf("[root@yangkun]#");
        gets(buf);
        fflush(stdout);
        Resolve(buf,argv);
        //test(argv);
        pid_t ret=fork();
        if(ret==0)
        {
            execv("/usr/bin/ls",argv);
            exit(0);
        }
        else if(ret>0)
        {
            int status;
            pid_t waitval=0;
            do
            {
                waitval=waitpid(-1,&status,WNOHANG);
                if(waitval==-1)
                {
                   printf("wait erro"); 
                }
                else if(waitval>0)
                {
                    if((status&0x7F)!=0)
                    {
                        printf("sig code:%d\n",status&0x7F);
                    }
                }
            }while(waitval==0);
        }
        else
        {
            perror("fork");
        }
    }
}

int main()
{
    Mybash();
    return 0;
}
