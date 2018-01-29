#include"tmisc.h"


Condition::Condition(void)
{
	//static BOOL once = InitGlobalEvents();
	isInit = FALSE;
}


Condition::~Condition(void)
{
	//UnInitialize();
}


//BOOL Condition::InitGlobalEvents()
//{
//	gEvents = new Event[MaxThreads];	// �ץ����K�ˤޤǽ�Ť��ʤ�
//	gEventMap = 0xffffffff;
//
//	// ��ǰ�˶������äƤ����������餯ʮ�֤����룩
//	for (int i = 0; i < 10; i++) gEvents[i].hEvent = ::CreateEvent(0, FALSE, FALSE, NULL);
//
//	return	TRUE;
//}











//BOOL Condition::InitGlobalEvents()
//{
//	gEvents = new Event[MaxThreads];	// �ץ����K�ˤޤǽ�Ť��ʤ�
//	gEventMap = 0xffffffff;
//
//	// ��ǰ�˶������äƤ����������餯ʮ�֤����룩
//	for (int i = 0; i < 10; i++) gEvents[i].hEvent = ::CreateEvent(0, FALSE, FALSE, NULL);
//
//	return	TRUE;
//}

BOOL Condition::Initialize()
{
	if (!isInit) {
		::InitializeCriticalSection(&cs);
		waitBits = 0;
		isInit = TRUE;
	}
	return	TRUE;
}

void Condition::UnInitialize(void)
{
	if (isInit) {
		::DeleteCriticalSection(&cs);
		isInit = FALSE;
	}
}



//BOOL Condition::Wait(DWORD timeout)
//{
//	 //�ο��̶Ȥοդ��_ʼλ���{��
//	// �����_�ʴ_�J�ϡ�INIT_EVENT <-> WAIT_EVENT �� CAS �ǣ�
//	u_int	idx = get_ntz(_InterlockedExchangeAdd(&gEventMap, 0));
//	u_int	self_bit = 0;
//	if (idx >= MaxThreads) idx = 0;
//
//	int	count = 0;
//	while (count < MaxThreads) {
//		if (InterlockedCompareExchange(&gEvents[idx].kind, WAIT_EVENT, INIT_EVENT) == INIT_EVENT) {
//			self_bit = 1 << idx;
//			_InterlockedAnd(&gEventMap, ~self_bit);
//			break;
//		}
//		if (++idx == MaxThreads) idx = 0;
//		count++;
//	}
//	if (count >= MaxThreads) {	// ͨ���Ϥ��ꤨ�ʤ�
//		MessageBox(0, "Detect too many wait threads", "TLib", MB_OK);
//		return	FALSE;
//	}
//	Event	&event = gEvents[idx];
//
//	if (event.hEvent == NULL) {
//		event.hEvent = ::CreateEvent(0, FALSE, FALSE, NULL);
//	}
//	waitBits |= self_bit;
//
//	UnLock();
//
//	DWORD	status = ::WaitForSingleObject(event.hEvent, timeout);
//
//	Lock();
//	waitBits &= ~self_bit;
//	InterlockedExchange(&event.kind, INIT_EVENT);
//	_InterlockedOr(&gEventMap, self_bit);
//
//	return	status == WAIT_TIMEOUT ? FALSE : TRUE;
//}

//void Condition::Notify(void)	// �F״�Ǥϡ��ߤäƤ��륹��å�ȫ�T���𤳤�
//{
//	if (waitBits) {
//		u_int	bits = waitBits;
//		while (bits) {
//			int		idx = get_ntz(bits);
//			Event	&event = gEvents[idx];
//
//			if (event.kind == WAIT_EVENT) {
//				::SetEvent(event.hEvent);
//				event.kind = DONE_EVENT;	// INIT <-> WAIT�g����Ǥ� CAS�ϟo��
//			}
//			bits &= ~(1 << idx);
//		}
//	}
//}


//WCHAR *wcsdupNew(const WCHAR *_s, int max_len)
//{
//	int		len = int((max_len == -1) ? wcslen(_s) : wcsnlen(_s, max_len));
//	WCHAR	*s = new WCHAR[len + 1];
//	memcpy(s, _s, len * sizeof(WCHAR));
//	s[len] = 0;
//	return	s;
//}