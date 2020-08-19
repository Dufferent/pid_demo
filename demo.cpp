#include "pid.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <math.h>

using namespace std;

int main()
{
    Pid_Type set = -457.584;
    Pid_Type Y=0,X=0;
    pid my_pid(0.3,0.3,0,&Y,&set);
    while(1)
    {
        Y=2*X+3;
        X = my_pid.pid_cpu();
        printf("Y=%0.3lf\tset=%0.3lf\n",Y,set);
        usleep(1000*10);
    }
}