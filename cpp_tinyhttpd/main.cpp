/*************************************************************************
	> File Name: main.cpp
	> Author:yangkun 
	> Mail:yangkungetit@163.com 
	> Created Time: Fri 19 Jan 2018 11:19:19 AM CST
 ************************************************************************/
#include "tinyhttp.h"
#include "tinyhttp.cpp"
static void Usage(const char* argv)
{
    printf("Usage page:\t%s [local_ip] [local_port]\n",argv);
}

int main(int argc, char* argv[])
{
    if(argc != 3)
    {
        Usage(argv[0]);
    }

    string s1(argv[1]);
    string s2(argv[2]);
    Tinyhttp th(s1, s2);
    th.start();
    cout << "ready for accept" << endl;
    return 0;
}
