/*************************************************************************
	> File Name: sevice.c
	> Author:yangkun 
	> Mail:yangkungetit@163.com 
	> Created Time: Thu 21 Dec 2017 10:33:22 AM CST
 ************************************************************************/

#include"commom.h"

void test()
{
    int semid=create(1);
    //int ret=fork();
    int val;
    setvalve(semid,0,1);
    val=semctl(semid,0,GETVAL);
    printf("%d\n",val);
    P(semid,0);
    val=semctl(semid,0,GETVAL);
    printf("%d\n",val);
    val=semctl(semid,0,GETVAL);
    printf("%d\n",val);
    V(semid,0);
    P(semid,0);
   // if(ret==0)
   // {
   //     while(1)
   //     {
   //         write(1,"a",1);
   //         usleep(1000*100);
   //         write(1,"a",1);
   //         usleep(1000*100);
   //     }
   // }
   // else if(ret<0)
   // {
   //     perror("fork");
   //     exit(1);
   // }
   // else
   // {
   //     while(1)
   //     {
   //         write(1,"b",1);
   //         usleep(1000*100);
   //         write(1,"b",1);
   //         usleep(1000*100);
   //     }
   // }
    cancel(semid);
}

int main()
{
    test();
    return 0;
}
