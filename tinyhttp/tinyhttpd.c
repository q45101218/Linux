/*************************************************************************
	> File Name: tinyhttpd.c
	> Author:yangkun 
	> Mail:yangkungetit@163.com 
	> Created Time: Thu 18 Jan 2018 08:12:27 AM CST
 ************************************************************************/
#include "tinyhttpd.h"
void print_log(const char* msg, int level)
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
        print_log(strerror(errno), FATAL);
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
        if(ret > 0)
        {
            if(c == '\r')
            {
                ret = recv(sock, &c , 1, MSG_PEEK);
                if(ret > 0)
                {
                    if(c == '\n')
                    {
                        recv(sock, &c, 1, 0);
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

static void echo_string()
{}

static int echo_www(int sock, char* path,int size)
{
    int fd = open(path, O_RDONLY);
    if(fd < 0)
    {
        echo_string(sock);
        print_log(strerror(errno), FATAL);
        return 8;
    }

    const char* echo_line = "HTTP/1.0 200 OK\r\n";
    send(sock, echo_line, strlen(echo_line), 0);
    const char* null_line = "\r\n";
    send(sock, null_line, strlen(echo_line), 0);
    if(sendfile(sock, fd, NULL, size) < 0)
    {
        echo_string(sock);
        print_log(strerror(errno), FATAL);
        return 9;
    }

    close(fd);
    return 0;
}

void drop_header(int sock)
{
    char line[1024];
    int ret = -1;
    do{
       ret = get_line(sock, line, sizeof(line));
    }while(ret>0 && strcmp(line, "\n"));
}

void* handler_request(void* arg)
{
    int sock = *(int*)arg;
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
    }while(1);

#ifndef _DEBUG_
    char buf[SIZE];
    int ret = 0;
    char method[SIZE/10];
    char url[SIZE];
    int i = 0,j = 0;
    int cgi = 0;
    char* query_string = NULL;
    if(get_line(sock, buf, sizeof(buf) <= 0))
    {
        echo_string(sock);
        ret = 5;
        goto end;
    }
    while( !isspace(buf[j]) && i < sizeof(method)-1 && j < sizeof(buf))
    {
        method[i]=buf[j];
        i++;
        j++;
    }

    method[i]=0;

    if(strcasecmp(method, "GET") && strcasecmp(method, "POST"))
    {
        echo_string(sock);
        ret = 6;
        goto end;
    }

    if(strcasecmp(method, "POST") == 0)
    {
        cgi = 1;
    }

    while(isspace(buf[j]) && j < sizeof(buf))
    {
        j++;
    }
    i = 0;
    while(!isspace(buf[j]) && j < sizeof(buf) && i < sizeof(url)-1)
    {
        url[i] = buf[j];
        i++;
        j++;
    }
    url[i] = 0;

    printf("method: %s, url: %s\n", method, url);
    query_string = url;
    while(*query_string != '\0')
    {
        if(*query_string == '?')
        {
            *query_string = '\0';
            query_string++;
            cgi = 1;
            break;
        }
        query_string++;
    }

    sprintf(path, "wwwroot/%s", url);
    if(url[strlen(path)-1] == '/')
    {
        strcat(path, "index.html");
    }

    struct stat st;
    if(stat(path, &st) != 0)
    {
        echo_string(sock);
        ret = 7;
        goto end;
    }
    else
    {
        if(S_ISDIR(st.st_mode))
        {
            strcat(path, "/index.html");
        }
        else if((S_IXUSR & st.st_mode) || (st.st_mode & S_IXGRP) || (st.st_mode & S_IXOTH))
        {
            cgi = 1;
        }
        else
        {

        }
        if(cgi)
        {
            
        }
        else
        {
            drop_header(scok);
            echo_www(sock, path, st.st_size);
            printf("well done\n");
        }
    }

end:
    close(sock);
    return (void*)ret;
}
#endif

