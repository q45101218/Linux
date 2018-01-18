/*************************************************************************
	> File Name: cgi.c
	> Author:yangkun 
	> Mail:yangkungetit@163.com 
	> Created Time: Thu 18 Jan 2018 03:46:41 PM CST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
    char* method = NULL;
    char* query_string = NULL;
    char* string_arg = NULL;
    int content_len = -1;
    char buf[1024];
    if((method = getenv("METHOD")))
    {
        if(strcasecmp(method, "GET") == 0)
        {
            if((query_string = getenv("QUERY_STRING")))
            {
                string_arg = query_string;
            }
        }
        else
        {
            if(getenv("CONTENT_LEN"))
            {
                content_len = atoi(getenv("CONTENT_LEN"));
                int i = 0;
                for(;i < content_len; i++)
                {
                    read(0, &buf[i], 1);
                }
                buf[i] = '\0';
            }
        }
    }

    argv;
    return 0;
}
