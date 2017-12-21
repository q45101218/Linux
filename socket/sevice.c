/*************************************************************************
	> File Name: socket.c
	> Author:yangkun 
	> Mail:yangkungetit@163.com 
	> Created Time: Thu 21 Dec 2017 03:48:25 PM CST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<netinet/ip.h>

//struct sockaddr_in {
//    sa_family_t    sin_family; /* address family: AF_INET */
//    in_port_t      sin_port;   /* port in network byte order */
//    struct in_addr sin_addr;   /* internet address */
//};

void test()
{
    int lfd=socket(AF_INET,SOCK_STREAM,0);
    if(lfd==-1)
    {
        perror("socket");
        exit(1);
    }
    struct sockaddr_in sersockaddr;
    sersockaddr.sin_family=AF_INET;
    sersockaddr.sin_port=htons(9999);
    sersockaddr.sin_addr.s_addr=htonl(INADDR_ANY);
    if(-1==bind(lfd,(struct sockaddr*)&sersockaddr,sizeof(sersockaddr)))
    {
        perror("bind");
        exit(1);
    }
    printf("bind is successful\n");
    if(listen(lfd,10)==-1)
    {
        perror("listen");
        exit(1);
    }
    printf("convert a passive socket\n");
    while(1)
    {
        int nfd=accept(lfd,NULL,NULL);
        if(-1!=nfd)
        {
            printf("new file description:%d\n",nfd);
        }
        while(1)
        {
            char buf[1024]={0};
            ssize_t size=read(nfd,buf,sizeof(buf));
            if(size==0)
            {
                printf("end of client\n");
                sleep(1);
            }
            else if (size<0)
            {
                perror("read");
                exit(1);
            }
            ssize_t sz=write(1,buf,sizeof(buf));
            if(sz<0)
            {
                perror("write");
                exit(1);
            }
        }
    }
    printf("socket of file:%d\n",lfd);
}

int main()
{
    test();
    return 0;
}
