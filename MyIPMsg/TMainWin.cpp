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


//�������ڲ��Ѵ��ڼ��뵽��ϣ����
BOOL TMainWin::CreateU8(LPCSTR class_name, LPCSTR title, DWORD , DWORD, HMENU)
{
	className = _strdup(class_name);
	
	DWORD exstyle = WS_EX_OVERLAPPEDWINDOW;
	DWORD style = WS_OVERLAPPEDWINDOW;//���ĸ�����
	return TWin::CreateU8(className, "Hello,World", style, exstyle, 0);


}
