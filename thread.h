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
    virtual int run(void) = 0;

public:
    int threadCreate(void);
    int threadExit(void);
    int threadDestroy(void);
    thread_t threadId() {return thread_id;}
    static int sleep(unsigned long ms);

private:
    thread_t thread_id;
    bool _isReady;
};

#endif // THREAD_H
