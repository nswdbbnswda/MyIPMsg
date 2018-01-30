#ifndef TMAINWIN_H
#define TMAINWIN_H
#include"TWin.h"

class TMainWin : public TWin
{
protected:
	static TMainWin *mainWin;
	static HICON hMainIcon;
	static HICON hRecvIcon;
	char		*className;
public:
	TMainWin();
	~TMainWin();
	BOOL CreateU8(LPCSTR class_name, LPCSTR title,DWORD,DWORD, HMENU);
};



#endif





