/*************************************************************************
	> File Name: check2.c
	> Author:yangkun 
	> Mail:yangkungetit@163.com 
	> Created Time: Fri 02 Feb 2018 02:07:04 AM CST
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main()
{
    struct sockaddr_in addr1;
    struct sockaddr_in addr2;

    addr1.sin_addr.s_addr = 0;
    addr2.sin_addr.s_addr = 0xffffffff;

    char* p1 = inet_ntoa(addr1.sin_addr);
    printf("p1 : %s\n",p1);
    char* p2 = inet_ntoa(addr2.sin_addr);
    printf("p2 : %s\n",p2);
    printf("p1 : %s\n",p1);
    printf("p2 : %s\n",p2);
    return 0;
}
