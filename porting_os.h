#ifndef PORTING_OS_H
#define PORTING_OS_H

#define OS_WINDOWS

#ifdef OS_WINDOWS

//socket

#include <winsock2.h>
#include <mstcpip.h>
#include <ws2tcpip.h>


//thread
#include <windows.h>
#include <process.h>
#include <conio.h>

typedef SOCKET socket_t;
typedef HANDLE thread_t;

#pragma comment(lib, "ws2_32.lib")
#endif

int porting_socket_init(void);
int porting_socket_deinit(void);

socket_t porting_socket_create(int domain, int type, int protocol);
int porting_socket_close(socket_t sock);
int porting_socket_bind(socket_t sock, struct socketaddr *, int addrlen );
int porting_socket_listen(socket_t sock,  int backlog);
int porting_socket_accept(socket_t sock, struct sockaddr *, int *addrlen);

int porting_socket_recvfrom(socket_t sock, void *buf, int len, int flag, struct sockaddr *fromaddr, int *addrlen);
int porting_socket_sendto(socket_t sock, void *buf, int len, int flag, struct sockaddr *toaddr, int addrlen);
int porting_socket_recv(socket_t sock, void *buf, int len, int flag);
int porting_socket_send(socket_t sock, void *buf, int len, int flag);

//thread
int porting_thread_create(thread_t *thread, void*(*entry)(void*), void *arg);
int porting_thread_destroy(thread_t *thread);
int porting_thread_sleep(unsigned long ms_sleep);
int porting_thread_exit(void);

#endif // PORTING_OS_H
