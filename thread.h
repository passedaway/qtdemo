#ifndef THREAD_H
#define THREAD_H

#include "porting_os.h"
class Thread
{
public:
    Thread(){_isReady=false;}
    ~Thread();

    //run function
private:
    static void* srun(void *args);
    int nv_run(void); //not vritual function ==> nv
    virtual int run(int iarg, void *parg) = 0;

public:
    int threadCreate(int iarg, void *args);
    int threadExit(void);
    int threadDestroy(void);
    thread_t threadId() {return thread_id;}
    static int sleep(unsigned long ms);

private:
    thread_t thread_id;
    int iarg;
    void *parg;
    bool _isReady;
};

#endif // THREAD_H
