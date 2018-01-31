#include "TWin.h"
#include"app.h"
#include<stdlib.h>
#include"resource.h"
TWin::TWin(TWin *_parent)
{
	hWnd = 0;
	hAccel = NULL;
	rect.left = 450;
	rect.right = 1000;//宽度
	rect.top = 55;//矩形到上边界距离为130
	rect.bottom = 630;//窗口高度
	orgRect = rect;
	parent = _parent;
	sleepBusy = FALSE;
	isUnicode = TRUE;
	scrollHack = TRUE;
	modalCount = 0;
	twinId = TApp::GenTWinID();
}

//析构函数
TWin::~TWin()
{
	Destroy();
}


//销毁窗口
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

//销毁窗口
BOOL TWin::EvDestroy(void)
{
	PostQuitMessage(0);
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
	HDC         hdc;
	HDC         hdcBuf;//缓存DC
	PAINTSTRUCT ps;
	RECT        rect;
	hdc = GetDC(hWnd);//获得设备上下文
	hdcBuf = CreateCompatibleDC(hdc);//缓存DC
	HBITMAP hBmp;//位图
	hBmp = LoadBitmap(TApp::GetInstance(), MAKEINTRESOURCE(IDB_BITMAP1));//获得位图句柄
	SelectObject(hdcBuf, hBmp);//把位图选入DC
	BitBlt(hdc, 0, 0, 535, 535, hdcBuf, 0, 0, SRCCOPY);
	ReleaseDC(hWnd, hdc);
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

//激活窗口
BOOL TWin::EvActivate(BOOL fActivate, DWORD fMinimized, HWND hActiveWnd)
{
	return	FALSE;
}

//窗口焦点改变
BOOL TWin::EvWindowPosChanging(WINDOWPOS *pos)
{
	return	FALSE;
}

//窗口焦点被改变
BOOL TWin::EvWindowPosChanged(WINDOWPOS *pos)
{
	return	FALSE;
}

//字符事件
BOOL TWin::EvChar(WCHAR code, LPARAM keyData)
{
	return	FALSE;
}


//滚动条事件
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

//按钮事件
BOOL TWin::EventButton(UINT uMsg, int nHitTest, POINTS pos)
{
	return	FALSE;
}

//热键事件
BOOL TWin::EventKey(UINT uMsg, int nVirtKey, LONG lKeyData)
{
	return	FALSE;
}

BOOL TWin::EventMenuLoop(UINT uMsg, BOOL fIsTrackPopupMenu)
{
	return	FALSE;
}

//初始化菜单
BOOL TWin::EventInitMenu(UINT uMsg, HMENU hMenu, UINT uPos, BOOL fSystemMenu)
{
	return	FALSE;
}



//菜单被选中
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

//焦点变化事件
BOOL TWin::EventFocus(UINT uMsg, HWND hFocusWnd)
{
	return	FALSE;
}

//app事件
BOOL TWin::EventApp(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	return	FALSE;
}

//用户事件
BOOL TWin::EventUser(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
return	FALSE;
}

//系统事件
BOOL TWin::EventSystem(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	return	FALSE;
}


//设置子控件文字内容
BOOL TWin::SetDlgItemTextU8(int ctlId, const char *buf)
{
	Wstr	wbuf(buf);

	return	::SetDlgItemTextW(hWnd, ctlId, wbuf.s());//设置对话框中控件的文本和标题
}


//消息弹窗UTF8格式
int TWin::MessageBoxU8(LPCSTR msg, LPCSTR title, UINT style)
{
	Wstr	wmsg(msg);
	Wstr	wtitle(title);


	return	MessageBoxW(wmsg.s(), wtitle.s(), style);
}
//获得窗口上的内容并且返回UTF-8格式
int TWin::GetWindowTextU8(char *text, int len)
{
	Wstr	wbuf(len);

	wbuf[0] = 0;
	if (::GetWindowTextW(hWnd, wbuf.Buf(), len) < 0) return -1;

	return	WtoU8(wbuf.s(), text, len);
}
//设置窗口上的文字内容
BOOL TWin::SetWindowTextU8(const char *text)
{
	Wstr	wbuf(text);

	return	::SetWindowTextW(hWnd, wbuf.s());
}


//获得窗口文字内容的长度
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
		rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top, parent ? parent->hWnd : NULL, hMenu, TApp::GetInstance(), NULL)) == NULL)
		return TApp::GetApp()->DelWin(this), FALSE;
	else
	{
		this->Show(1);//显示窗口
	}
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

//向控件窗口发送消息
LRESULT TWin::SendDlgItemMessageW(int idCtl, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	return	::SendDlgItemMessageW(hWnd, idCtl, uMsg, wParam, lParam);
}


//对不感冒消息进行默认处理
LRESULT TWin::DefWindowProc(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	return	isUnicode ? ::DefWindowProcW(hWnd, uMsg, wParam, lParam) :
		::DefWindowProcA(hWnd, uMsg, wParam, lParam);
}

//消息预处理
BOOL TWin::PreProcMsg(MSG *msg)
{
	if (hAccel)
		return	::TranslateAccelerator(hWnd, hAccel, msg);

	return	FALSE;
}


//窗口处理函数
LRESULT TWin::WinProc(UINT uMsg, WPARAM wParam, LPARAM lParam)
{  

	switch (uMsg)
	{
	case WM_LBUTTONDOWN:
		MessageBox("L", "Tip!", 0);
		break;
	case WM_DESTROY:
		EvDestroy();//关闭窗口
		break;
	case WM_CREATE:
		EvCreate(lParam);
		break;
	case WM_PAINT:
		EvPaint();
		break;
	case WM_RBUTTONDOWN:

		 break;
	}
	
	return DefWindowProc(uMsg, wParam, lParam);
	//BOOL	done = FALSE;
	//LRESULT	result = 0;

	//switch (uMsg)
	//{
	//case WM_CREATE:

	//	GetWindowRect(&orgRect);
	//	done = EvCreate(lParam);// TWin的WM_CREATE消息交由EvCreate函数进行处理
	//	break;

	//case WM_CLOSE:
	//	done = EvClose();
	//	break;

	//case WM_COMMAND:
	//	done = EvCommand(HIWORD(wParam), LOWORD(wParam), lParam);
	//	break;

	//case WM_SYSCOMMAND:
	//	done = EvSysCommand(wParam, MAKEPOINTS(lParam));
	//	break;

	//case WM_TIMER://?会主动触发，即使用户不进行任何动作
	//	done = EvTimer(wParam, (TIMERPROC)lParam);
	//	break;

	//case WM_DESTROY://关闭窗口的时候会响应这里
	//	done = EvDestroy();
	//	break;

	//case WM_NCDESTROY://双击会响应
	//	if (!::IsIconic(hWnd)) GetWindowRect(&rect);
	//	if (!EvNcDestroy())	// hWndを0にする前に呼び出す
	//		DefWindowProc(uMsg, wParam, lParam);
	//	done = TRUE;
	//	TApp::GetApp()->DelWin(this);
	//	hWnd = 0;
	//	break;

	//case WM_QUERYENDSESSION:
	//	result = EvQueryEndSession((BOOL)wParam, (BOOL)lParam);
	//	done = TRUE;
	//	break;

	//case WM_ENDSESSION:
	//	done = EvEndSession((BOOL)wParam, (BOOL)lParam);
	//	break;

	//case WM_QUERYOPEN:
	//	result = EvQueryOpen();
	//	done = TRUE;
	//	break;

	//case WM_PAINT://会响应
	//	done = EvPaint();
	//	break;

	//case WM_NCPAINT://会响应
	//	done = EvNcPaint((HRGN)wParam);
	//	break;

	//case WM_SIZE://会响应
	//	done = EvSize((UINT)wParam, LOWORD(lParam), HIWORD(lParam));
	//	break;

	//case WM_MOVE://会响应
	//	done = EvMove(LOWORD(lParam), HIWORD(lParam));
	//	break;

	//case WM_SHOWWINDOW:
	//	done = EvShowWindow((BOOL)wParam, (int)lParam);
	//	break;

	//case WM_GETMINMAXINFO://会响应
	//	done = EvGetMinMaxInfo((MINMAXINFO *)lParam);
	//	break;

	//case WM_SETCURSOR://鼠标出现在窗口上面的时候就会响应
	//	result = done = EvSetCursor((HWND)wParam, LOWORD(lParam), HIWORD(lParam));
	//	break;

	//case WM_MOUSEMOVE://只要鼠标出现在右下角那个图标上就会进行响应
	//	done = EvMouseMove((UINT)wParam, MAKEPOINTS(lParam));// WM_MOUSEMOVE消息交由EvMouseMove处理
	//	break;

	//case WM_NCHITTEST:
	//	done = EvNcHitTest(MAKEPOINTS(lParam), &result);
	//	break;

	//case WM_MEASUREITEM:
	//	result = done = EvMeasureItem((UINT)wParam, (LPMEASUREITEMSTRUCT)lParam);
	//	break;

	//case WM_DRAWITEM:
	//	result = done = EvDrawItem((UINT)wParam, (LPDRAWITEMSTRUCT)lParam);
	//	break;

	//case WM_NOTIFY://双击右下角的图标的时候进行响应
	//	result = done = EvNotify((UINT)wParam, (LPNMHDR)lParam);
	//	break;

	//case WM_CONTEXTMENU:
	//	result = done = EvContextMenu((HWND)wParam, MAKEPOINTS(lParam));
	//	break;

	//case WM_HOTKEY://热键
	//	result = done = EvHotKey((int)wParam);
	//	break;

	//case WM_ACTIVATEAPP://双击右下角图标会响应
	//	done = EvActivateApp((BOOL)wParam, (DWORD)lParam);
	//	break;

	//case WM_ACTIVATE://双击右下角图标会进行事件的响应
	//	EvActivate(LOWORD(wParam), HIWORD(wParam), (HWND)lParam);
	//	break;

	//case WM_DROPFILES:
	//	done = EvDropFiles((HDROP)wParam);
	//	break;

	//case WM_CHAR:
	//	done = EvChar((WCHAR)wParam, lParam);
	//	break;

	//case WM_WINDOWPOSCHANGING://直接响应
	//	done = EvWindowPosChanging((WINDOWPOS *)lParam);
	//	break;

	//case WM_WINDOWPOSCHANGED://直接响应
	//	done = EvWindowPosChanged((WINDOWPOS *)lParam);
	//	break;
	//	//case语句没有后面没有写break,程序会一直执行下去，以下的各个case 语句执行的都是done = EventButton这句
	//case WM_LBUTTONUP:
	//case WM_RBUTTONUP:
	//case WM_NCLBUTTONUP:
	//case WM_NCRBUTTONUP:
	//case WM_LBUTTONDOWN:
	//case WM_RBUTTONDOWN:
	//case WM_NCLBUTTONDOWN:
	//case WM_NCRBUTTONDOWN:
	//case WM_LBUTTONDBLCLK:
	//case WM_RBUTTONDBLCLK:
	//case WM_NCLBUTTONDBLCLK:
	//case WM_NCRBUTTONDBLCLK:
	//	done = EventButton(uMsg, (int)wParam, MAKEPOINTS(lParam));//按钮事件
	//	break;


	//case WM_KEYUP:

	//case WM_KEYDOWN://键盘按下事件
	//	done = EventKey(uMsg, (int)wParam, (LONG)lParam);
	//	break;

	//case WM_HSCROLL:
	//case WM_VSCROLL:
	//	done = EventScrollWrapper(uMsg, LOWORD(wParam), HIWORD(wParam), (HWND)lParam);
	//	break;

	//case WM_ENTERMENULOOP:
	//case WM_EXITMENULOOP:
	//	done = EventMenuLoop(uMsg, (BOOL)wParam);
	//	break;

	//case WM_INITMENU:
	//case WM_INITMENUPOPUP:
	//	done = EventInitMenu(uMsg, (HMENU)wParam, LOWORD(lParam), (BOOL)HIWORD(lParam));
	//	break;

	//case WM_MENUSELECT:
	//	done = EvMenuSelect(LOWORD(wParam), HIWORD(wParam), (HMENU)lParam);
	//	break;

	//case WM_CTLCOLORBTN:
	//case WM_CTLCOLORDLG:
	//case WM_CTLCOLOREDIT:
	//case WM_CTLCOLORLISTBOX:
	//case WM_CTLCOLORMSGBOX:
	//case WM_CTLCOLORSCROLLBAR:
	//case WM_CTLCOLORSTATIC:
	//	done = EventCtlColor(uMsg, (HDC)wParam, (HWND)lParam, (HBRUSH *)&result);
	//	break;

	//case WM_KILLFOCUS:
	//case WM_SETFOCUS:
	//	done = EventFocus(uMsg, (HWND)wParam);
	//	break;

	//default:
	//	if (uMsg >= WM_APP && uMsg <= 0xBFFF) {
	//		result = done = EventApp(uMsg, wParam, lParam);
	//	}
	//	else if (uMsg >= WM_USER && uMsg < WM_APP || uMsg >= 0xC000 && uMsg <= 0xFFFF) {
	//		result = done = EventUser(uMsg, wParam, lParam);//用户自定义的事件交由EventUser处理
	//	}
	//	else {
	//		result = done = EventSystem(uMsg, wParam, lParam);

	//	}
	//	break;
	//}

	//return	done ? result : DefWindowProc(uMsg, wParam, lParam);//进行了响应那么就返回0，否则的话就按默认处理
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

//弹窗ANSI版本
int TWin::MessageBox(LPCSTR msg, LPCSTR title, UINT style)
{
	modalCount++;
	int ret = ::MessageBox(hWnd, msg, title, style);
	modalCount--;

	return	ret;
}

//弹窗宽字符版本
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


//获得控件上的内容
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


//创建窗口
BOOL TWin::CreateU8(LPCSTR className, LPCSTR title, DWORD style, DWORD exStyle, HMENU hMenu)
{
	Wstr	className_w(className, BY_UTF8);
	Wstr	title_w(title, BY_UTF8);

	return	CreateW(className_w.s(), title_w.s(), style, exStyle, hMenu);//执行完这一句就产生任务栏图标    
}

//创建窗口
BOOL TWin::Create(LPCSTR className, LPCSTR title, DWORD style, DWORD exStyle, HMENU hMenu)
{
	Wstr	className_w(className, BY_MBCS);
	Wstr	title_w(title, BY_MBCS);

	return	CreateW(className_w.s(), title_w.s(), style, exStyle, hMenu);
}