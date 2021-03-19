#pragma once
#ifndef _STYSOCKET_H
#define _STYSOCKET_H
#pragma comment(lib,"ws2_32.lib")  //link Ws2_32.lib
#include <WinSock2.h>
#include <WS2tcpip.h>
#include "StyTools.h"
/*****************************
 Global Functions Declaration
*****************************/
bool St_Socket_Init();
bool St_Socket_CleanUp();
extern bool isInited;

/*****************************
 Local Variables Declaration
*****************************/


/*****************************
		Class Declaration
*****************************/
class St_Socket
{
private:
	SOCKET m_sock = INVALID_SOCKET;
public:
	int connectWithHostName(string hostname,string port);
	int connectWithIP(string ipAddress,int port);
	int sendMsg(void* msg,int msglen);
	int recvMsg();
	/*标志获取状态
	FSUCCESSFUL,	一切正常
	FRAW,			类刚初始化时的状态
	FINITFAILED,	套接字库初始化失败
	FCSFAILED,		创建套接字失败
	FGHFAILED,		域名解析失败
	FCONFAILED,		连接失败
	FSENDFAILED,	发送失败
	FRECVFAILED,	接收失败
	*/
	enum { FSUCCESSFUL, FRAW, FINITFAILED, FCSFAILED, FGHFAILED, FCONFAILED, FSENDFAILED, FRECVFAILED } iGetFlag = FRAW;
};
#endif // ! _STYSOCKET_H