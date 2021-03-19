#pragma once
#ifndef _STYTOOLS_H
#define	_STYTOOLS_H
//  从 Windows 头文件中排除极少使用的信息
#define WIN32_LEAN_AND_MEAN            
// Windows 头文件: 
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
