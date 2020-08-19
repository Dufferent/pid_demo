#include "pid.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <math.h>

using namespace std;
#define ABS(x) (x>0)? (x):((-1)*x)


pid::pid(Pid_Type kp,Pid_Type ki,Pid_Type kd,Pid_Type *acquire,Pid_Type *expect)
{
    pid::kp = kp;
    pid::ki = ki;
    pid::kd = kd;

    pid::in = acquire;
    pid::set = expect;
    pid::err = 0;
    pid::last_err = 0;

    pid::sum_err = 0;
    pid::out = 0;
}

Pid_Type pid::pid_cpu(void)
{
    pid::err = *(pid::set) - *(pid::in);//计算误差
    pid::sum_err+=err;                  //累计误差
    pid::out = pid::kp*pid::err + pid::ki*pid::sum_err + pid::kd*(pid::err - pid::last_err);//计算
    pid::last_err = pid::err;
    return pid::out;
}

pid::~pid()
{
}

