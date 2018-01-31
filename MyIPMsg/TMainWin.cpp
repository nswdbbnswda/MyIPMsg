#include"TMainWin.h"


HWND  TMainWin::*mainWin = NULL;
HICON TMainWin::hMainIcon = NULL;
HICON TMainWin::hRecvIcon = NULL;

TMainWin::TMainWin()
{
}

TMainWin::~TMainWin()
{
}


//创建窗口
BOOL TMainWin::CreateU8(LPCSTR class_name, LPCSTR title, DWORD , DWORD, HMENU)
{
	className = _strdup(class_name);
	
	DWORD exstyle = WS_EX_OVERLAPPEDWINDOW;
	DWORD style = WS_OVERLAPPEDWINDOW;//第四个参数
	return TWin::CreateU8(className, "MyIPMsg", style, exstyle, 0);

}
