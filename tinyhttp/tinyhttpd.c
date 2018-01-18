/*************************************************************************
	> File Name: tinyhttpd.c
	> Author:yangkun 
	> Mail:yangkungetit@163.com 
	> Created Time: Thu 18 Jan 2018 08:12:27 AM CST
 ************************************************************************/

void printf_log(char* msg, int level)
{
#ifdef _STDOUT_
    const char* const level_msg[] = 
    {
        "SUCCESS",
        "NOTICE",
        "WARNING",
        "ERROR",
        "FATAL",
    };
    printf("[%S][%s]\n", msg, level_msg[level%5]);
#else

#endif
}

int startup(const char* ip, int port)
{
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock < 0)
    {
        print_log(strerror(errno,FATAL));
        exit(2);
    }

    int opt = 1;
    setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    struct sockaddr_in local;
    local.sin_family = AF_INET;
    local.sin_port = htons(port);
    local.sin_addr.s_addr = inet_addr(ip);
    if(bind(sock, (struct sockaddr*)&local, sizeof(local)) < 0)
    {
        print_log(strerror(errno),FATAL);
        exit(2);
    }

    if(listen(sock, 10) < 0)
    {
        print_log(strerror(errno),FATAL);
        exit(2);
    }
}

static int get_line(int sock, char line[], int size)
{
    char c= '\0';
    int len = 0;

    while( c != '\n' && len < size-1 )
    {
        int ret = recv(sock, &c, 1, 0);
        if(r > 0)
        {
            if(c == '\r')
            {
                ret = recv(sock, &c ,1 MSG_PEEK);
                if(ret > 0)
                {
                    if(c == '\n')
                    {
                        recv(sock, &c 1, 0);
                    }
                    else 
                    {
                        c = '\n';
                    }
                }
            }
            line[len++] = c;
        }
        else
        {
            c = '\n';
        }
    }
    line[len] = '\0';
    return len;
}

void* handler_request(void* arg)
{
    int sock = (int)arg;
#ifdef _DEBUG_
    char line[1024];
    do{
        int ret = get_line(sock, line, sizeof(line));
        if(ret > 0)
        {
            printf("%s", line);
        }
        else
        {
            printf("request done.\n");
            break;
        }
    }while(1)
#endif
}
