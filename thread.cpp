#include "thread.h"

#include <iostream>
using std::cout;
using std::endl;

Thread::~Thread()
{
    threadDestroy();
}

//run function
void* Thread::srun(void *args)
{
	Thread *_this = (Thread*)args;

#if 0
    return (void*)_this->run(_this->iarg, _this->parg);
#else
    //first come to nv_run, for debug, it can just goto the run
    return (void*)_this->nv_run();
#endif
}

 int Thread::nv_run(void)
 {
     //call child run function
     int ret = this->run(iarg, parg);
     //threadExit();//will not return
     return ret;
 }

//public
int Thread::threadCreate(int iarg, void *args)
{
	this->iarg = iarg;
	this->parg = args;
    //set isReady
    _isReady = true;

    return porting_thread_create(&thread_id, srun, this);
}

int Thread::threadExit(void)
{
    porting_thread_exit();
    return 0;
}

int Thread::threadDestroy()
{
    if( _isReady )
        porting_thread_destroy(&thread_id);
	_isReady = false;
    return 0;
}

//public static
int Thread::sleep(unsigned long ms_sleep)
{
    return porting_thread_sleep(ms_sleep);
}
