#include "porting_os.h"
#include <stdio.h>

int porting_socket_init(void)
{
	WSADATA wsaData;

    if( WSAStartup(0x202, &wsaData) != 0 )
	{
		fprintf(stderr, "WSAStartup Error.\n");
		WSACleanup();
		return -1;
	}
	return 0;
}

int porting_socket_deinit(void)
{
	WSACleanup();
	return 0;
}

socket_t porting_socket_create(int domain, int type, int protocol)
{
	return socket(domain, type, protocol);
}

int porting_socket_close(socket_t sock)
{
	return closesocket(sock);
}

int porting_socket_bind(socket_t sock, struct sockaddr *addr, int addrlen )
{
    return bind(sock, (const sockaddr*)addr, addrlen);
}

int porting_socket_listen(socket_t sock,  int backlog)
{
	return listen(sock, backlog);
}

int porting_socket_accept(socket_t sock, struct sockaddr *addr, int *addrlen)
{
	return accept(sock, addr, addrlen);
}


int porting_socket_recvfrom(socket_t sock, void *buf, int len, int flag, struct sockaddr *fromaddr, int *addrlen)
{
    return recvfrom(sock, (char *)buf, len, flag, fromaddr, addrlen);
}

int porting_socket_sendto(socket_t sock, void *buf, int len, int flag, struct sockaddr *toaddr, int addrlen)
{
    return sendto(sock, (const char *)buf, len, flag, toaddr, addrlen);
}

int porting_socket_recv(socket_t sock, void *buf, int len, int flag)
{
    return recv(sock,(char *)buf, len, flag);
}

int porting_socket_send(socket_t sock, void *buf, int len, int flag)
{
    return send(sock, (const char *)buf, len, flag);
}

//thread
int porting_thread_create(thread_t *thread, void*(*entry)(void*), void *arg)
{
#if 0
    //convert entry type: from void*£¨type1)(void *) to void (type2)(void *)
    int thread_retcode =  _beginthread( (void(*)(void *)) entry , 0, arg);
    *thread = thread_retcode;
    return thread_retcode;
#else
    if( !thread )
        return -1;
    *thread = (thread_t)CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)entry, arg, 0, NULL);
#if 0
    printf("createThread: %d\n", *thread);
#endif
    return 0;
#endif
}

int porting_thread_destroy(thread_t *thread)
{
#if 0
    _endthread();
    return 0;
#else
    if( thread )
    {
        TerminateThread((HANDLE)*thread, 0);
       CloseHandle(*thread);
        return 0;
	}
	return 0;
#endif
}

int porting_thread_exit(void)
{
    ExitThread(0);
    return 0;
}

int porting_thread_sleep(unsigned long ms_sleep)
{
    Sleep(ms_sleep);
    return 0;
}
