#ifndef TLIBMISC_H
#define TLIBMISC_H
#include<Windows.h>


#include "tlib.h"

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <intrin.h>

//DWORD TWinVersion = ::GetVersion();
//
HINSTANCE defaultStrInstance;
//Condition::Event	*Condition::gEvents = NULL;
//volatile LONG		Condition::gEventMap = 0;




class Condition {
protected:
	enum Kind { INIT_EVENT = 0, WAIT_EVENT, DONE_EVENT };

   struct Event {
		HANDLE	hEvent;
		u_int	kind;
		Event() { hEvent = 0; kind = INIT_EVENT; }
	};
	static Event			*gEvents;
	static volatile LONG	gEventMap;
	//static BOOL				InitGlobalEvents();
	static const int		MaxThreads = 32;

	BOOL			isInit;
	CRITICAL_SECTION cs;
	u_int			waitBits;

public:
	Condition(void);
	~Condition();

	BOOL Initialize(void);
	void UnInitialize(void);

	void Lock(void) { ::EnterCriticalSection(&cs); }
	void UnLock(void) { ::LeaveCriticalSection(&cs); }

	int  IsWait() { return waitBits ? TRUE : FALSE; }

	//BOOL Wait(DWORD timeout = INFINITE);
	//void Notify(void);
};





inline int get_ntz(u_int val) {
	u_long	ret = 0;
	_BitScanForward(&ret, val);
	return	ret;
}



char *strdupNew(const char *_s, int max_len = -1);
//WCHAR *wcsdupNew(const WCHAR *_s, int max_len = -1);

int strcpyz(char *dest, const char *src);
int wcscpyz(WCHAR *dest, const WCHAR *src);
int strncpyz(char *dest, const char *src, int num);
int strncatz(char *dest, const char *src, int num);
const char *wcsnchr(const char *src, char ch, int num);
int wcsncpyz(WCHAR *dest, const WCHAR *src, int num);
int wcsncatz(WCHAR *dest, const WCHAR *src, int num);
const WCHAR *wcsnchr(const WCHAR *src, WCHAR ch, int num);



#endif TLIBMISC_H