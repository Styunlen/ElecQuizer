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
	/*��־��ȡ״̬
	FSUCCESSFUL,	һ������
	FRAW,			��ճ�ʼ��ʱ��״̬
	FINITFAILED,	�׽��ֿ��ʼ��ʧ��
	FCSFAILED,		�����׽���ʧ��
	FGHFAILED,		��������ʧ��
	FCONFAILED,		����ʧ��
	FSENDFAILED,	����ʧ��
	FRECVFAILED,	����ʧ��
	*/
	enum { FSUCCESSFUL, FRAW, FINITFAILED, FCSFAILED, FGHFAILED, FCONFAILED, FSENDFAILED, FRECVFAILED } iGetFlag = FRAW;
};
#endif // ! _STYSOCKET_H