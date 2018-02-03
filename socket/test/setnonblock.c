/*************************************************************************
	> File Name: setnonblock.c
	> Author:yangkun 
	> Mail:yangkungetit@163.com 
	> Created Time: Sat 03 Feb 2018 11:29:25 PM CST
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

void setnonblock(int fd)
{
    int mod = fcntl(fd, F_GETFD);
    if(mod == -1)
    {
        perror("fcntl");
        return;
    }

    fcntl(fd, F_SETFL, mod | O_NONBLOCK);
    //if(fcntl(fd, F_SETFL, mod | O_NONBLOCK) == -1)
    //{
    //    perror("fcntl");
    //    return;
    //}
    printf("successful\n");
}

int main()
{
    setnonblock(0);
    char buf[1024] = {0};
    while(1)
    {
        ssize_t size = read(0, buf, 1024);
        if(0 > size)
        {
            perror("read");
            sleep(1);
            continue;
        }
        printf("%s",buf);
    }
    return 0;
}
