#include "tcpclient.h"

#include <stdio.h>
TcpClient::~TcpClient()
{
#if 0
    printf("~TcpClient\n");
    fflush(stdout);
#endif
    isRun = false;
}

int TcpClient::start(void)
{
#if 1
    printf("start\n");
    fflush(stdout);
#endif
    isRun = true;
    threadCreate();
    return 0;
}

int TcpClient::stop(void)
{
    isRun = false;
    threadDestroy();
    return 0;
}

#include <time.h>
//implement run
int TcpClient::run()
{
    while(isRun)
    {
        printf("Run %d : ip= %d, port=%d path=%s %d\n", 
				threadId(), ip, port, path, time(NULL));
        fflush(stdout);
        sleep(500);
        cur_bytes += 100;

        //todo socket start
    }
    return 0;
}
