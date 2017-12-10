/*************************************************************************
	> File Name: echofile.c
	> Author:yangkun 
	> Mail:yangkungetit@163.com 
	> Created Time: Sun 10 Dec 2017 07:40:27 PM CST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<string.h>

int main()
{
    //you will look two different phenomenon while you switch each section
    //in first kind of option,and second comparative,we find write() hasn't buffer,so direct output at screen.
    //according to fork(),buffer was duplicated to child's processing,so the value can be output twice.


    char buf1[]="printf-->hello world";
    char buf2[]="fwrite-->hello world";
    char buf3[]="write-->hello world";

    //char buf1[]="printf-->hello world\n";
    //char buf2[]="fwrite-->hello world\n";
    //char buf3[]="write-->hello world\n";

    printf("%s",buf1);

    fwrite(buf2,strlen(buf2),1,stdout);

    write(1,buf3,strlen(buf3));

    fork();

    return 0;
}
