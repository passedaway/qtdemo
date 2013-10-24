#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include "porting_os.h"
#include "thread.h"
class Thread;

class TcpClient : public Thread
{
public:
    TcpClient(int ip, int port, const char *path)
        :ip(ip), port(port), path(path), isRun(false)
    {
        cur_bytes = 0;
        last_bytes = 0;
    }

    ~TcpClient();

    int start(void);
    int stop(void);

    double rate(void)
    {
        return (double)(cur_bytes - last_bytes);
    }

    long get_all(void){
        return cur_bytes;
    }

private:
    int run(void);

private:
    double speed;
    long last_bytes, cur_bytes;
    unsigned int ip;
    unsigned short port;
    const char *path;
    socket_t client_fd;
    bool isRun;
};

#endif // TCPCLIENT_H
