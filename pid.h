#ifndef __PID_H
#define __PID_H

typedef double Pid_Type;


class pid
{
private:
    /* data */
    Pid_Type  kp;
    Pid_Type  ki;
    Pid_Type  kd;
    Pid_Type *in;
    Pid_Type *set;
    Pid_Type  out;

    Pid_Type  err;
    Pid_Type  last_err;
    Pid_Type  sum_err;

public:
     pid(Pid_Type kp,Pid_Type ki,Pid_Type kd,Pid_Type *acquire,Pid_Type *expect);//构造函数
    ~pid();//析构函数
    Pid_Type pid_cpu(void);
};



#endif


