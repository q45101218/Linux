/*************************************************************************
	> File Name: tinyhttp.cpp
	> Author:yangkun 
	> Mail:yangkungetit@163.com 
	> Created Time: Fri 19 Jan 2018 11:18:05 AM CST
 ************************************************************************/

#include "tinyhttp.h"

enum ERRNO_TYPE
{
    SUCCESS,
    NOTICE,
    WARNING,
    ERRNO,
    FATAL,
};

class Tinyhttp
{
public:
    Tinyhttp(const char* argv1, const char* argv2)
    {
        _init_service(argv1, argv2);
    }

    ~Tinyhttp()
    {}

    void print_log(char* err, ERRNO_TYPE errtp)
    {
        static char* errmsg[] = 
        {
            "SUCCESS",
            "NOTICE",
            "WARNING",
            "ERRNO",
            "FATAL"
        };
        printf("%s %s\n",err, errmsg[errtp]);
    }

private:
    int _init_service(const char* argv1,const char* argv2)
    {
        int listen_sock = sock(AF_INET, SOCK_STREAM, 0);
        if(sock < 0)
        {
            print_log(strerror(errno), FATAL);
            exit(1);
        }

        struct sockaddr_in service;
        service.sin_family = AF_INET;
        service.sin_port = htons(atoi(argv2));
        service.sin_addr.s_addr = inet_addr(argv1);

        if(!bind(listen_sock, (struct sock_addr*)&service, sizeof(service)))
        {
            printf(strerror(errno), FATAL);
            exit(2);
        }

        if(listen(listen_sock, 10))
    }
};
