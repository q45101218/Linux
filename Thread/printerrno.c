/*************************************************************************
	> File Name: printerrno.c
	> Author:yangkun 
	> Mail:yangkungetit@163.com 
	> Created Time: Sun 28 Jan 2018 06:56:05 PM CST
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i = 0;
    for( ; i<256; i++)
    {
        printf("%03d   %s\n",i,strerror(i));
    }
    return 0;
}
