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

    Tinyhttp(string argv1 = "8080", string argv2 = "0")
    :listen_sock(_init_service(argv1, argv2))
    {
        cout << listen_sock << endl;
    }

    ~Tinyhttp()
    {}

    int start()
    {
        sockaddr_in client;
        socklen_t len;
        while(1)
        {
            int new_sock = accept(listen_sock, (struct sockaddr*)&client, &len);
            if( new_sock < 0 )
            {
                print_log(strerror(errno), NOTICE);
                continue;
            }
            
            cout << "client :" << " "<< "["<< inet_ntoa(client.sin_addr) << "]" \
            << " " << "[" << ntohs(client.sin_port) << "]  " << "get line\n";
            char buf[1024];
            ssize_t size = read(new_sock, buf, 1024);
            buf[size] = 0;
            write( 1, buf, strlen(buf));
        }
    }

    void print_log(char* err, int errtp)
    {
        static string errmsg[] = 
        {
            "SUCCESS",
            "NOTICE",
            "WARNING",
            "ERRNO",
            "FATAL"
        };
        cout << err << "\t" << errmsg[errtp] << endl;
    }

    int _init_service(string& argv1, string& argv2)
    {
        int listen_sock = socket(AF_INET, SOCK_STREAM, 0);
        if(listen_sock < 0)
        {
            print_log(strerror(errno), FATAL);
            exit(1);
        }

        struct sockaddr_in service;
        service.sin_family = AF_INET;
        service.sin_port = htons(atoi(argv2.c_str()));
        service.sin_addr.s_addr = inet_addr(argv1.c_str());
        socklen_t len = sizeof(service);

        if(bind(listen_sock, (struct sockaddr*)&service, len))
        {
            printf(strerror(errno), FATAL);
            exit(2);
        }

        if(listen(listen_sock, 10))
        {
            print_log(strerror(errno), FATAL);
            exit(3);
        }
        cout<<listen_sock<<"======"<<endl;
        return listen_sock;
    }

public:
    int listen_sock;
};
