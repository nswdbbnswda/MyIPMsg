#include "TWin.h"
#include"app.h"

TWin::TWin(TWin *_parent)
{
	hWnd = 0;
	hAccel = NULL;
	rect.left = CW_USEDEFAULT;
	rect.right = CW_USEDEFAULT;
	rect.top = CW_USEDEFAULT;
	rect.bottom = CW_USEDEFAULT;
	orgRect = rect;
	parent = _parent;
	sleepBusy = FALSE;
	isUnicode = TRUE;
	scrollHack = TRUE;
	modalCount = 0;
	//twinId = TApp::GenTWinID();
}

//析构函数
TWin::~TWin()
{
	Destroy();
}



void TWin::Destroy(void)
{
	if (::IsWindow(hWnd))
	{
		::DestroyWindow(hWnd);
		hWnd = 0;
	}
}

//控件事件
BOOL TWin::EvCommand(WORD wNotifyCode, WORD wID, LPARAM hwndCtl)
{
	return	FALSE;
}



BOOL TWin::EvSysCommand(WPARAM uCmdType, POINTS pos)
{
	return	FALSE;
}


//创建事件
BOOL TWin::EvCreate(LPARAM lParam)
{
	return	FALSE;
}


//关闭事件
BOOL TWin::EvClose(void)
{
	return	FALSE;
}


//显示窗口
void TWin::Show(int mode)
{
	::ShowWindow(hWnd, mode);
	::UpdateWindow(hWnd);
}


//测量
BOOL TWin::EvMeasureItem(UINT ctlID, MEASUREITEMSTRUCT *lpMis)
{
	return	FALSE;
}

//绘制控件
BOOL TWin::EvDrawItem(UINT ctlID, DRAWITEMSTRUCT *lpDis)
{
	return	FALSE;
}

//销毁
BOOL TWin::EvDestroy(void)
{
	return	FALSE;
}

BOOL TWin::EvNcDestroy(void)
{
	return	FALSE;
}

//定时器事件
BOOL TWin::EvTimer(WPARAM timerID, TIMERPROC proc)
{
	return	FALSE;
}

//结束查询任务
BOOL TWin::EvQueryEndSession(BOOL nSession, BOOL nLogOut)
{
	return	TRUE;
}

//结束任务
BOOL TWin::EvEndSession(BOOL nSession, BOOL nLogOut)
{
	return	TRUE;
}
//打开查询
BOOL TWin::EvQueryOpen(void)
{
	return	TRUE;
}


//绘图
BOOL TWin::EvPaint(void)
{
	return	FALSE;
}


BOOL TWin::EvNcPaint(HRGN hRgn)
{
	return	FALSE;
}



//尺寸变化
BOOL TWin::EvSize(UINT fwSizeType, WORD nWidth, WORD nHeight)
{
	return	FALSE;
}


//窗口移动
BOOL TWin::EvMove(int xpos, int ypos)
{
	return	FALSE;
}

//显示窗口
BOOL TWin::EvShowWindow(BOOL fShow, int fnStatus)
{
	return	FALSE;
}



//获得最大最小消息
BOOL TWin::EvGetMinMaxInfo(MINMAXINFO *info)
{
	return	FALSE;
}

//设置鼠标
BOOL TWin::EvSetCursor(HWND cursorWnd, WORD nHitTest, WORD wMouseMsg)
{
	return	FALSE;
}

//鼠标移动
BOOL TWin::EvMouseMove(UINT fwKeys, POINTS pos)
{
	return	FALSE;
}


BOOL TWin::EvNcHitTest(POINTS pos, LRESULT *result)
{
	return	FALSE;
}

//托盘消息
BOOL TWin::EvNotify(UINT ctlID, NMHDR *pNmHdr)
{
	return	FALSE;
}

//内容菜单
BOOL TWin::EvContextMenu(HWND childWnd, POINTS pos)
{
	return	FALSE;
}

//快捷键
BOOL TWin::EvHotKey(int hotKey)
{
	return	FALSE;
}



BOOL TWin::EvActivateApp(BOOL fActivate, DWORD dwThreadID)
{
	return	FALSE;
}

//激活
BOOL TWin::EvActivate(BOOL fActivate, DWORD fMinimized, HWND hActiveWnd)
{
	return	FALSE;
}

//窗口焦点改变
BOOL TWin::EvWindowPosChanging(WINDOWPOS *pos)
{
	return	FALSE;
}

BOOL TWin::EvWindowPosChanged(WINDOWPOS *pos)
{
	return	FALSE;
}


BOOL TWin::EvChar(WCHAR code, LPARAM keyData)
{
	return	FALSE;
}


BOOL TWin::EventScrollWrapper(UINT uMsg, int nCode, int nPos, HWND scrollBar)
{
	if (scrollHack) {
		// 32bit対応スクロール変換
		if (nCode == SB_THUMBTRACK || nCode == SB_THUMBPOSITION) {
			SCROLLINFO	si = { sizeof(si), SIF_TRACKPOS };
			if (::GetScrollInfo(hWnd, uMsg == WM_HSCROLL ? SB_HORZ : SB_VERT, &si)) {
				nPos = si.nTrackPos;
			}
		}
	}
	return	EventScroll(uMsg, nCode, nPos, scrollBar);
}

BOOL TWin::EventScroll(UINT uMsg, int nCode, int nPos, HWND scrollBar)
{
	scrollHack = FALSE;
	return	FALSE;
}

BOOL TWin::EventButton(UINT uMsg, int nHitTest, POINTS pos)
{
	return	FALSE;
}

BOOL TWin::EventKey(UINT uMsg, int nVirtKey, LONG lKeyData)
{
	return	FALSE;
}

BOOL TWin::EventMenuLoop(UINT uMsg, BOOL fIsTrackPopupMenu)
{
	return	FALSE;
}

BOOL TWin::EventInitMenu(UINT uMsg, HMENU hMenu, UINT uPos, BOOL fSystemMenu)
{
	return	FALSE;
}




BOOL TWin::EvMenuSelect(UINT uItem, UINT fuFlag, HMENU hMenu)
{
	return	FALSE;
}

BOOL TWin::EvDropFiles(HDROP hDrop)
{
	return	FALSE;
}

BOOL TWin::EventCtlColor(UINT uMsg, HDC hDcCtl, HWND hWndCtl, HBRUSH *result)
{
	return	FALSE;
}

BOOL TWin::EventFocus(UINT uMsg, HWND hFocusWnd)
{
	return	FALSE;
}

BOOL TWin::EventApp(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	return	FALSE;
}

BOOL TWin::EventUser(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	return	FALSE;
}

BOOL TWin::EventSystem(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	return	FALSE;
}



BOOL TWin::SetDlgItemTextU8(int ctlId, const char *buf)
{
	Wstr	wbuf(buf);

	return	::SetDlgItemTextW(hWnd, ctlId, wbuf.s());//设置对话框中控件的文本和标题
}



int TWin::MessageBoxU8(LPCSTR msg, LPCSTR title, UINT style)
{
	Wstr	wmsg(msg);
	Wstr	wtitle(title);


	return	MessageBoxW(wmsg.s(), wtitle.s(), style);
}

int TWin::GetWindowTextU8(char *text, int len)
{
	Wstr	wbuf(len);

	wbuf[0] = 0;
	if (::GetWindowTextW(hWnd, wbuf.Buf(), len) < 0) return -1;

	return	WtoU8(wbuf.s(), text, len);
}

BOOL TWin::SetWindowTextU8(const char *text)
{
	Wstr	wbuf(text);

	return	::SetWindowTextW(hWnd, wbuf.s());
}



int TWin::GetWindowTextLengthU8(void)
{
	int		len = ::GetWindowTextLengthW(hWnd);
	Wstr	wbuf(len + 1);

	if (::GetWindowTextW(hWnd, wbuf.Buf(), len + 1) <= 0) return 0;

	return	WtoU8(wbuf.s(), NULL, 0);
}


//BOOL TWin::SetForceForegroundWindow(void)
//{
//	DWORD	foreId, targId, svTmOut;
//
//	if (IsWinVista()) {
//		TSwitchToThisWindow(hWnd, TRUE);
//	}
//
//	foreId = ::GetWindowThreadProcessId(::GetForegroundWindow(), NULL);
//	targId = ::GetWindowThreadProcessId(hWnd, NULL);
//	if (foreId != targId)
//		::AttachThreadInput(targId, foreId, TRUE);
//	::SystemParametersInfo(SPI_GETFOREGROUNDLOCKTIMEOUT, 0, (void *)&svTmOut, 0);
//	::SystemParametersInfo(SPI_SETFOREGROUNDLOCKTIMEOUT, 0, 0, 0);
//	BOOL	ret = ::SetForegroundWindow(hWnd);
//	::SystemParametersInfo(SPI_SETFOREGROUNDLOCKTIMEOUT, 0, (void *)(DWORD_PTR)svTmOut, 0);
//	if (foreId != targId)
//		::AttachThreadInput(targId, foreId, FALSE);
//
//	return	ret;
//}








//创建窗口
BOOL TWin::CreateW(const WCHAR *className, const WCHAR *title, DWORD style, DWORD exStyle,
	HMENU hMenu)
{
	if (className == NULL) {
		className = TApp::GetApp()->GetDefaultClassW();
	}

	TApp::GetApp()->AddWin(this);
	if ((hWnd = ::CreateWindowExW(exStyle, className, title, style,
		rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top,
		parent ? parent->hWnd : NULL, hMenu, TApp::GetInstance(), NULL)) == NULL)
		return	TApp::GetApp()->DelWin(this), FALSE;
	else
		return	TRUE;
}



//显示窗口
BOOL TWin::ShowWindow(int mode)
{
	return	::ShowWindow(hWnd, mode);
}


//向指定窗口投递消息
BOOL TWin::PostMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	return	::PostMessage(hWnd, uMsg, wParam, lParam);
}


//向指定窗口投递消息
BOOL TWin::PostMessageW(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	return	::PostMessageW(hWnd, uMsg, wParam, lParam);
}



//向指定窗口发送消息
LRESULT TWin::SendMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	return	::SendMessage(hWnd, uMsg, wParam, lParam);
}


//向指定窗口发送消息
LRESULT TWin::SendMessageW(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	return	::SendMessageW(hWnd, uMsg, wParam, lParam);
}


//把消息发送给指定的对话框中的控件
LRESULT TWin::SendDlgItemMessage(int idCtl, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	return	::SendDlgItemMessage(hWnd, idCtl, uMsg, wParam, lParam);
}


LRESULT TWin::SendDlgItemMessageW(int idCtl, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	return	::SendDlgItemMessageW(hWnd, idCtl, uMsg, wParam, lParam);
}



LRESULT TWin::DefWindowProc(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	return	isUnicode ? ::DefWindowProcW(hWnd, uMsg, wParam, lParam) :
		::DefWindowProcA(hWnd, uMsg, wParam, lParam);
}


BOOL TWin::PreProcMsg(MSG *msg)
{
	if (hAccel)
		return	::TranslateAccelerator(hWnd, hAccel, msg);

	return	FALSE;
}




//窗口处理函数
LRESULT TWin::WinProc(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	return LRESULT();
}



BOOL TWin::Idle(void)
{
	MSG		msg;

	if (::PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
	{
		if (TApp::GetApp()->PreProcMsg(&msg))
			return	TRUE;

		::TranslateMessage(&msg);
		::DispatchMessage(&msg);
		return	TRUE;
	}

	return	FALSE;
}

//把窗口设置成前台并激活该窗口,键盘输入转向该窗口
BOOL TWin::SetForegroundWindow(void)
{
	return	::SetForegroundWindow(hWnd);
}

//将指定的窗口设置到Z序的顶部。如果窗口为顶层窗口，则该窗口被激活；如果窗口为子窗口，则相应的顶级父窗口被激活。
BOOL TWin::BringWindowToTop(void)
{
	return	::BringWindowToTop(hWnd);
}


//该函数允许/禁止指定的窗口或控件接受鼠标和键盘的输入，当输入被禁止时，窗口不响应鼠标和按键的输入,输入允许时，窗口接受所有的输入
BOOL TWin::EnableWindow(BOOL is_enable)
{
	return	::EnableWindow(hWnd, is_enable);
}


//该函数可以获得指定窗口的可视状态，即显示或者隐藏
BOOL TWin::IsWindowVisible(void)
{
	return	::IsWindowVisible(hWnd);
}


//确定某个按钮控件是否有选中标志，或者三态按钮控制是否为灰色的、选中的、或两者都不是。
UINT TWin::IsDlgButtonChecked(int ctlId)
{
	return	::IsDlgButtonChecked(hWnd, ctlId);
}


int TWin::MessageBox(LPCSTR msg, LPCSTR title, UINT style)
{
	modalCount++;
	int ret = ::MessageBox(hWnd, msg, title, style);
	modalCount--;

	return	ret;
}

int TWin::MessageBoxW(LPCWSTR msg, LPCWSTR title, UINT style)
{
	modalCount++;
	int ret = ::MessageBoxW(hWnd, msg, title, style);
	modalCount--;

	return	ret;
}


//改变按钮控制的选中状态
BOOL TWin::CheckDlgButton(int ctlId, UINT check)
{
	return	::CheckDlgButton(hWnd, ctlId, check);
}


//获得指定窗口中的控件句柄
HWND TWin::GetDlgItem(int ctlId)
{
	return	::GetDlgItem(hWnd, ctlId);
}

//设置对话框中控件的文本和标题
BOOL TWin::SetDlgItemTextW(int ctlId, const WCHAR *buf)
{
	return	::SetDlgItemTextW(hWnd, ctlId, buf);
}

//设置对话框中控件的文本和标题
BOOL TWin::SetDlgItemText(int ctlId, LPCSTR buf)
{
	return	::SetDlgItemText(hWnd, ctlId, buf);
}


//检索指定控件的文本
int TWin::GetDlgItemInt(int ctlId, BOOL *err, BOOL sign)
{
	return	(int)::GetDlgItemInt(hWnd, ctlId, err, sign);
}

//设置对话框文本
BOOL TWin::SetDlgItemInt(int ctlId, int val, BOOL sign)
{
	return	::SetDlgItemInt(hWnd, ctlId, val, sign);
}


//获得与对话框中的控件相关的标题或文本
UINT TWin::GetDlgItemText(int ctlId, LPSTR buf, int len)
{
	return	::GetDlgItemText(hWnd, ctlId, buf, len);
}

//获得与对话框中的控件相关的标题或文本
UINT TWin::GetDlgItemTextW(int ctlId, WCHAR *buf, int len)
{
	return	::GetDlgItemTextW(hWnd, ctlId, buf, len);
}



//移动窗口到指定位置
BOOL TWin::MoveWindow(int x, int y, int cx, int cy, int bRepaint)
{
	return	::MoveWindow(hWnd, x, y, cx, cy, bRepaint);
}

BOOL TWin::FitMoveWindow(int x, int y)
{
	RECT	rc;
	GetWindowRect(&rc);
	int		cx = rc.right - rc.left;
	int		cy = rc.bottom - rc.top;

	int	start_x = ::GetSystemMetrics(SM_XVIRTUALSCREEN);
	int	start_y = ::GetSystemMetrics(SM_YVIRTUALSCREEN);
	int	end_x = start_x + ::GetSystemMetrics(SM_CXVIRTUALSCREEN);
	int	end_y = start_y + ::GetSystemMetrics(SM_CYVIRTUALSCREEN);

	if (x + cx > end_x) x = end_x - cx;
	if (x < start_x)    x = start_x;
	if (y + cy > end_y) y = end_y - cy;
	if (y < start_y)    y = start_y;

	return	SetWindowPos(NULL, x, y, 0, 0, SWP_NOSIZE | SWP_NOREDRAW | SWP_NOZORDER);
}



//挂起线程
BOOL TWin::Sleep(UINT mSec)
{
	if (mSec == 0 || sleepBusy)
		return	TRUE;

	if (!::SetTimer(hWnd, TLIB_SLEEPTIMER, mSec, 0))
		return	FALSE;
	sleepBusy = TRUE;

	MSG		msg;
	while (::GetMessage(&msg, 0, 0, 0))
	{
		if (msg.hwnd == hWnd && msg.wParam == TLIB_SLEEPTIMER)
		{
			::KillTimer(hWnd, TLIB_SLEEPTIMER);
			break;
		}
		if (TApp::GetApp()->PreProcMsg(&msg))
			continue;

		::TranslateMessage(&msg);
		::DispatchMessage(&msg);
	}
	sleepBusy = FALSE;
	return	TRUE;
}



UINT TWin::GetDlgItemTextU8(int ctlId, char *buf, int len)
{
	Wstr	wbuf(len);

	*buf = 0;
	GetDlgItemTextW(ctlId, wbuf.Buf(), len);

	return	WtoU8(wbuf.s(), buf, len);
}



//设置窗口焦点
BOOL TWin::SetWindowPos(HWND hInsAfter, int x, int y, int cx, int cy, UINT fuFlags)
{
	return	::SetWindowPos(hWnd, hInsAfter, x, y, cx, cy, fuFlags);
}


//获得窗口矩形
BOOL TWin::GetWindowRect(RECT *_rect)
{
	return	::GetWindowRect(hWnd, _rect ? _rect : &rect);
}


//获得客户区矩形
BOOL TWin::GetClientRect(RECT *rc)
{
	return	::GetClientRect(hWnd, rc);
}


//激活一个窗口(到顶层)
HWND TWin::SetActiveWindow(void)
{
	return	::SetActiveWindow(hWnd);
}


//获取控件当前内容
int TWin::GetWindowText(LPSTR text, int size)
{
	return	::GetWindowText(hWnd, text, size);
}

//设置控件内容
BOOL TWin::SetWindowText(LPCSTR text)
{
	return	::SetWindowText(hWnd, text);
}

//获得窗口内容
int TWin::GetWindowTextW(WCHAR *text, int size)
{
	return	::GetWindowTextW(hWnd, text, size);
}


//设置窗口内容
BOOL TWin::SetWindowTextW(const WCHAR *text)
{
	return	::SetWindowTextW(hWnd, text);
}


//获得内容长度
int TWin::GetWindowTextLengthW(void)
{
	return	::GetWindowTextLengthW(hWnd);
}



//获得窗口中内容长度
//int TWin::GetWindowTextLengthU8(void)
//{
//	int		len = ::GetWindowTextLengthW(hWnd);
//	Wstr	wbuf(len + 1);
//
//	if (::GetWindowTextW(hWnd, wbuf.Buf(), len + 1) <= 0) return 0;
//
//	return	WtoU8(wbuf.s(), NULL, 0);
//}





//BOOL TWin::SetWindowTextU8(const char *text)
//{
//	Wstr	wbuf(text);
//	return	::SetWindowTextW(hWnd, wbuf.s());
//}


//向指定的窗体更新区域添加一个矩形，然后窗口客户区域的这一部分将被重新绘制
BOOL TWin::InvalidateRect(const RECT *rc, BOOL fErase)
{
	return	::InvalidateRect(hWnd, rc, fErase);
}

//获得在额外窗口内存中指定偏移位地址的32位度整型值
LONG_PTR TWin::GetWindowLong(int index)
{
	return	::GetWindowLong(hWnd, index);
}


LONG_PTR TWin::SetWindowLong(int index, LONG_PTR val)
{
	return	::SetWindowLong(hWnd, index, val);
}

//获得指定窗口结构的信息
WORD TWin::GetWindowWord(int index)
{
	return	::GetWindowWord(hWnd, index);
}


//设置指定窗口结构的信息
WORD TWin::SetWindowWord(int index, WORD val)
{
	return	::SetWindowWord(hWnd, index, val);
}



BOOL TWin::CreateU8(LPCSTR className, LPCSTR title, DWORD style, DWORD exStyle, HMENU hMenu)
{
	Wstr	className_w(className, BY_UTF8);
	Wstr	title_w(title, BY_UTF8);

	return	CreateW(className_w.s(), title_w.s(), style, exStyle, hMenu);//执行完这一句就产生任务栏图标    
}


BOOL TWin::Create(LPCSTR className, LPCSTR title, DWORD style, DWORD exStyle, HMENU hMenu)
{
	Wstr	className_w(className, BY_MBCS);
	Wstr	title_w(title, BY_MBCS);

	return	CreateW(className_w.s(), title_w.s(), style, exStyle, hMenu);
}