#pragma once
#include"hashtable.h"
#include"tlib.h"
#include"tapi32u8.h"


//窗体类基类
class TWin : public THashObj {
protected:
	TRect			rect;
		TRect			orgRect;
		HACCEL			hAccel;
		TWin			*parent;
		BOOL			sleepBusy;	// for TWin::Sleep() only
		BOOL			isUnicode;
		BOOL			scrollHack;	// need 32bit scroll hack, if EventScroll is overridden
public:
		TWin(TWin *_parent = NULL);
		virtual	~TWin();
	
		HWND			hWnd;
		DWORD			modalCount;
		DWORD			twinId;
		virtual void	Show(int mode = SW_SHOWDEFAULT);//显示窗口
	    virtual BOOL	Create(LPCSTR className = NULL, LPCSTR title = "",//创建窗口
        DWORD style = (WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN),
			DWORD exStyle = 0, HMENU hMenu = NULL);
		virtual BOOL	CreateU8(LPCSTR className = NULL, LPCSTR title = "",
			DWORD style = (WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN),
			DWORD exStyle = 0, HMENU hMenu = NULL);
	    virtual BOOL	CreateW(const WCHAR *className = NULL, const WCHAR *title = L"",
		DWORD style = (WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN),
		DWORD exStyle = 0, HMENU hMenu = NULL);
	     virtual	void	Destroy(void);
	
	     virtual BOOL	EvCommand(WORD wNotifyCode, WORD wID, LPARAM hwndCtl);
         virtual BOOL	EvSysCommand(WPARAM uCmdType, POINTS pos);
         virtual BOOL	EvCreate(LPARAM lParam);
	     virtual BOOL	EvClose(void);
	     virtual BOOL	EvDestroy(void);
	     virtual BOOL	EvNcDestroy(void);
	     virtual BOOL	EvQueryEndSession(BOOL nSession, BOOL nLogOut);
	     virtual BOOL	EvEndSession(BOOL nSession, BOOL nLogOut);
	     virtual BOOL	EvQueryOpen(void);
	     virtual BOOL	EvPaint(void);
	     virtual BOOL	EvNcPaint(HRGN hRgn);
	     virtual BOOL	EvSize(UINT fwSizeType, WORD nWidth, WORD nHeight);
	     virtual BOOL	EvMove(int xpos, int ypos);
	     virtual BOOL	EvShowWindow(BOOL fShow, int fnStatus);
	     virtual BOOL	EvGetMinMaxInfo(MINMAXINFO *info);
	     virtual BOOL	EvTimer(WPARAM timerID, TIMERPROC proc);
	     virtual BOOL	EvSetCursor(HWND cursorWnd, WORD nHitTest, WORD wMouseMsg);
	     virtual BOOL	EvMouseMove(UINT fwKeys, POINTS pos);
	     virtual BOOL	EvNcHitTest(POINTS pos, LRESULT *result);
	     virtual BOOL	EvMeasureItem(UINT ctlID, MEASUREITEMSTRUCT *lpMis);
	     virtual BOOL	EvDrawItem(UINT ctlID, DRAWITEMSTRUCT *lpDis);
     	 virtual BOOL	EvMenuSelect(UINT uItem, UINT fuFlag, HMENU hMenu);
	     virtual BOOL	EvDropFiles(HDROP hDrop);
	     virtual BOOL	EvNotify(UINT ctlID, NMHDR *pNmHdr);
     	 virtual BOOL	EvContextMenu(HWND childWnd, POINTS pos);
	     virtual BOOL	EvHotKey(int hotKey);
	     virtual BOOL	EvActivateApp(BOOL fActivate, DWORD dwThreadID);
		 virtual BOOL	EvActivate(BOOL fActivate, DWORD fMinimized, HWND hActiveWnd);
		 virtual BOOL	EvChar(WCHAR code, LPARAM keyData);
     	 virtual BOOL	EvWindowPosChanged(WINDOWPOS *pos);
	     virtual BOOL	EvWindowPosChanging(WINDOWPOS *pos);
	
	     virtual BOOL	EventButton(UINT uMsg, int nHitTest, POINTS pos);
	     virtual BOOL	EventKey(UINT uMsg, int nVirtKey, LONG lKeyData);
	     virtual BOOL	EventMenuLoop(UINT uMsg, BOOL fIsTrackPopupMenu);
	     virtual BOOL	EventInitMenu(UINT uMsg, HMENU hMenu, UINT uPos, BOOL fSystemMenu);
	     virtual BOOL	EventCtlColor(UINT uMsg, HDC hDcCtl, HWND hWndCtl, HBRUSH *result);
	     virtual BOOL	EventFocus(UINT uMsg, HWND focusWnd);
	     virtual BOOL	EventScrollWrapper(UINT uMsg, int nScrollCode, int nPos, HWND hScroll);
	     virtual BOOL	EventScroll(UINT uMsg, int nScrollCode, int nPos, HWND hScroll);
	     virtual BOOL	EventApp(UINT uMsg, WPARAM wParam, LPARAM lParam);
	     virtual BOOL	EventUser(UINT uMsg, WPARAM wParam, LPARAM lParam);
	     virtual BOOL	EventSystem(UINT uMsg, WPARAM wParam, LPARAM lParam);
	
	     virtual UINT	GetDlgItemText(int ctlId, LPSTR buf, int len);
         virtual UINT	GetDlgItemTextW(int ctlId, WCHAR *buf, int len);
	     virtual UINT	GetDlgItemTextU8(int ctlId, char *buf, int len);
	     virtual BOOL	SetDlgItemText(int ctlId, LPCSTR buf);
	     virtual BOOL	SetDlgItemTextW(int ctlId, const WCHAR *buf);
	     virtual BOOL	SetDlgItemTextU8(int ctlId, const char *buf);
	     virtual int	GetDlgItemInt(int ctlId, BOOL *err = NULL, BOOL sign = TRUE);
	     virtual BOOL	SetDlgItemInt(int ctlId, int val, BOOL sign = TRUE);
	     virtual HWND	GetDlgItem(int ctlId);
	     virtual BOOL	CheckDlgButton(int ctlId, UINT check);
		 virtual UINT	IsDlgButtonChecked(int ctlId);
	     virtual BOOL	IsWindowVisible(void);
	     virtual BOOL	EnableWindow(BOOL is_enable);
	
	     virtual	int		MessageBox(LPCSTR msg, LPCSTR title = "msg", UINT style = MB_OK);
	     virtual	int		MessageBoxW(LPCWSTR msg, LPCWSTR title = L"msg", UINT style = MB_OK);
	     virtual	int		MessageBoxU8(LPCSTR msg, LPCSTR title = "msg", UINT style = MB_OK);
	     virtual BOOL	BringWindowToTop(void);
	     virtual BOOL	SetForegroundWindow(void);
	    // virtual BOOL	SetForceForegroundWindow(void);
	     virtual BOOL	ShowWindow(int mode);
	     virtual BOOL	PostMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);
	     virtual BOOL	PostMessageW(UINT uMsg, WPARAM wParam, LPARAM lParam);
	     virtual LRESULT	SendMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);
	     virtual LRESULT	SendMessageW(UINT uMsg, WPARAM wParam, LPARAM lParam);
	     virtual LRESULT	SendDlgItemMessage(int ctlId, UINT uMsg, WPARAM wParam, LPARAM lParam);
	     virtual LRESULT	SendDlgItemMessageW(int ctlId, UINT uMsg, WPARAM wParam, LPARAM lParam);
	     virtual BOOL	GetWindowRect(RECT *_rect = NULL);//获得窗口矩形
	     virtual BOOL	GetClientRect(RECT *rc);
	     virtual BOOL	SetWindowPos(HWND hInsAfter, int x, int y, int cx, int cy, UINT fuFlags);//设置窗口到指定点
	     virtual HWND	SetActiveWindow(void);//激活窗口
         virtual int    GetWindowText(LPSTR text, int size);//获取控件当前内容
	     virtual BOOL	SetWindowText(LPCSTR text);//设置控件内容
	     virtual BOOL	GetWindowTextW(WCHAR *text, int size);
	     virtual BOOL	GetWindowTextU8(char *text, int size);
	     virtual BOOL	SetWindowTextW(const WCHAR *text);
	     virtual BOOL	SetWindowTextU8(const char *text);
		 virtual int	GetWindowTextLengthW(void);
	     virtual int	GetWindowTextLengthU8(void);
	     virtual BOOL	InvalidateRect(const RECT *rc, BOOL fErase);
	     virtual LONG_PTR SetWindowLong(int index, LONG_PTR val);
	     virtual WORD	SetWindowWord(int index, WORD val);
	     virtual LONG_PTR GetWindowLong(int index);
	     virtual WORD	GetWindowWord(int index);
	     virtual TWin	*GetParent(void) { return parent; };
	     virtual void	SetParent(TWin *_parent) { parent = _parent; };
	     virtual BOOL	MoveWindow(int x, int y, int cx, int cy, int bRepaint);
	     virtual BOOL	FitMoveWindow(int x, int y);
	     virtual BOOL	Sleep(UINT mSec);
	     virtual BOOL	Idle(void);
	     virtual TWin	*Parent() { return parent; }
		 virtual	BOOL	PreProcMsg(MSG *msg);
	     virtual	LRESULT	WinProc(UINT uMsg, WPARAM wParam, LPARAM lParam);
	     virtual	LRESULT	DefWindowProc(UINT uMsg, WPARAM wParam, LPARAM lParam);
};



//窗体哈希表
class TWinHashTbl : public THashTbl {
protected:
	virtual BOOL	IsSameVal(THashObj *obj, const void *val) {
		return ((TWin *)obj)->hWnd == *(HWND *)val;
	}
public:
	TWinHashTbl(int _hashNum) : THashTbl(_hashNum) {}
	virtual ~TWinHashTbl() {}
	u_int	MakeHashId(HWND hWnd) { return DWORD_RDC(hWnd) * 0xf3f77d13; }
};

