#pragma once
#ifndef _STYTOOLS_H
#define	_STYTOOLS_H
//  �� Windows ͷ�ļ����ų�����ʹ�õ���Ϣ
#define WIN32_LEAN_AND_MEAN            
// Windows ͷ�ļ�: 
#include <Windows.h>
#include <cstdlib>
#include <cstdio>
#include <string>
using namespace std;

/*****************************
Global Functions Declaration
*****************************/
char * St_GetErrorInfo();
char * St_GetErrorInfo(DWORD ErrCode);


#endif // !_STYTOOLS_H
