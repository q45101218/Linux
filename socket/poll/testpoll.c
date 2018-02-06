/*************************************************************************
	> File Name: testpoll.c
	> Author:yangkun 
	> Mail:yangkungetit@163.com 
	> Created Time: Mon 05 Feb 2018 12:35:17 AM CST
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <poll.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
int main()
{
    struct pollfd poll_fd[2];
    poll_fd[0].fd = 0;
    poll_fd[1].fd = 1;
    poll_fd[0].events = POLLIN;
    poll_fd[1].events = POLLOUT;
    printf("%d,%d\n",POLLIN, POLLOUT);
    printf("%d,%d\n",poll_fd[0].revents, poll_fd[1].revents);
    while(1)
    {
        int ret = poll(poll_fd, 2, -1);
        if(ret < 0)
        {
            perror("poll");
            continue;
        }
        else
        {
            if(poll_fd[0].revents == POLLIN)
            {
                printf("%d\n",poll_fd[0].revents);
                char buf[1024] = {0};
                read(0, buf, sizeof(buf));
                printf("%s",buf);
            }
            if(poll_fd[1].revents == POLLOUT)
            {
                int fd = open("./log", O_CREAT | O_RDWR| O_APPEND);
                char msg[1024] = {0};
                read(1, msg, sizeof(msg));
                write(fd, msg, 3);
            }
        }
    }
}
