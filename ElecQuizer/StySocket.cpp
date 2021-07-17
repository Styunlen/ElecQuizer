#include "StySocket.h"
/********************
   Global Variables
********************/

/********************
   Local Variables
********************/
bool isInited = false;

/********************
  Global Functions
********************/
bool St_Socket_Init() {
	if(isInited == false)
	{
		WSADATA wsaData;
		int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);//用于检测函数状态
		if (iResult != 0) {
			return false;
		}
		isInited = true;
	}
	return true;
}

bool St_Socket_CleanUp() {
	if(isInited == true)
	{
		int iResult = WSACleanup();
		if (iResult != 0) {
			return false;
		}
		isInited = false;
	}
	return true;
}

/********************
   Class Functions
********************/

int St_Socket::connectWithHostName(string hostname,string port)
{
	struct addrinfo *result = NULL, hints;
	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;
	int iResult;
	//套接字连接信息
	iResult = getaddrinfo(hostname.c_str(), port.c_str(), &hints, &result);
	if (iResult != 0) {
		string logstr = "域名解析失败 : ";
		logstr += iResult;
		logstr += " \n";
		//pwin->call_function("DebugLog", logstr);
		iGetFlag = FGHFAILED;
		freeaddrinfo(result);
		return -1;
	}

	m_sock = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
	if (m_sock == INVALID_SOCKET) {
		string logstr = "创建套接字失败 : ";
		logstr += St_GetErrorInfo(WSAGetLastError());
		logstr += " \n";
		//pwin->call_function("DebugLog", logstr);
		iGetFlag = FCSFAILED;
		freeaddrinfo(result);
		return -2;
	}

	iResult = connect(m_sock, result->ai_addr, (int)result->ai_addrlen);
	if (iResult == SOCKET_ERROR) {
		string logstr = "连接失败 : ";
		logstr += St_GetErrorInfo(WSAGetLastError());
		logstr += " \n";
		//pwin->call_function("DebugLog", logstr);
		closesocket(m_sock);
		iGetFlag = FCONFAILED;
		freeaddrinfo(result);
		return -3;
	}
	freeaddrinfo(result);
	return 0;
}

int St_Socket::connectWithIP(string ipAddress,int port)
{
	return false;
}

int St_Socket::sendMsg(void* msg,int msglen)
{
	if (m_sock == INVALID_SOCKET)
		return -1;
	int iResult = ::send(m_sock, (char*)msg, msglen, 0);
	if (iResult == SOCKET_ERROR) {
		string logstr = "发送失败! ";
		logstr += St_GetErrorInfo(WSAGetLastError());
		logstr += " \n";
		closesocket(m_sock);
		iGetFlag = FSENDFAILED;
		return -2;
	}
	else
	{
		string logstr = "发送成功! ";
		logstr += iResult;
		logstr += " \n";
	}
	return 0;
}

int St_Socket::recvMsg()
{
	return 0;
}
