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

//��������
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

//�ؼ��¼�
BOOL TWin::EvCommand(WORD wNotifyCode, WORD wID, LPARAM hwndCtl)
{
	return	FALSE;
}



BOOL TWin::EvSysCommand(WPARAM uCmdType, POINTS pos)
{
	return	FALSE;
}


//�����¼�
BOOL TWin::EvCreate(LPARAM lParam)
{
	return	FALSE;
}


//�ر��¼�
BOOL TWin::EvClose(void)
{
	return	FALSE;
}


//��ʾ����
void TWin::Show(int mode)
{
	::ShowWindow(hWnd, mode);
	::UpdateWindow(hWnd);
}


//����
BOOL TWin::EvMeasureItem(UINT ctlID, MEASUREITEMSTRUCT *lpMis)
{
	return	FALSE;
}

//���ƿؼ�
BOOL TWin::EvDrawItem(UINT ctlID, DRAWITEMSTRUCT *lpDis)
{
	return	FALSE;
}

//����
BOOL TWin::EvDestroy(void)
{
	return	FALSE;
}

BOOL TWin::EvNcDestroy(void)
{
	return	FALSE;
}

//��ʱ���¼�
BOOL TWin::EvTimer(WPARAM timerID, TIMERPROC proc)
{
	return	FALSE;
}

//������ѯ����
BOOL TWin::EvQueryEndSession(BOOL nSession, BOOL nLogOut)
{
	return	TRUE;
}

//��������
BOOL TWin::EvEndSession(BOOL nSession, BOOL nLogOut)
{
	return	TRUE;
}
//�򿪲�ѯ
BOOL TWin::EvQueryOpen(void)
{
	return	TRUE;
}


//��ͼ
BOOL TWin::EvPaint(void)
{
	return	FALSE;
}


BOOL TWin::EvNcPaint(HRGN hRgn)
{
	return	FALSE;
}



//�ߴ�仯
BOOL TWin::EvSize(UINT fwSizeType, WORD nWidth, WORD nHeight)
{
	return	FALSE;
}


//�����ƶ�
BOOL TWin::EvMove(int xpos, int ypos)
{
	return	FALSE;
}

//��ʾ����
BOOL TWin::EvShowWindow(BOOL fShow, int fnStatus)
{
	return	FALSE;
}



//��������С��Ϣ
BOOL TWin::EvGetMinMaxInfo(MINMAXINFO *info)
{
	return	FALSE;
}

//�������
BOOL TWin::EvSetCursor(HWND cursorWnd, WORD nHitTest, WORD wMouseMsg)
{
	return	FALSE;
}

//����ƶ�
BOOL TWin::EvMouseMove(UINT fwKeys, POINTS pos)
{
	return	FALSE;
}


BOOL TWin::EvNcHitTest(POINTS pos, LRESULT *result)
{
	return	FALSE;
}

//������Ϣ
BOOL TWin::EvNotify(UINT ctlID, NMHDR *pNmHdr)
{
	return	FALSE;
}

//���ݲ˵�
BOOL TWin::EvContextMenu(HWND childWnd, POINTS pos)
{
	return	FALSE;
}

//��ݼ�
BOOL TWin::EvHotKey(int hotKey)
{
	return	FALSE;
}



BOOL TWin::EvActivateApp(BOOL fActivate, DWORD dwThreadID)
{
	return	FALSE;
}

//����
BOOL TWin::EvActivate(BOOL fActivate, DWORD fMinimized, HWND hActiveWnd)
{
	return	FALSE;
}

//���ڽ���ı�
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
		// 32bit���ꥹ����`���Q
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

	return	::SetDlgItemTextW(hWnd, ctlId, wbuf.s());//���öԻ����пؼ����ı��ͱ���
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








//��������
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



//��ʾ����
BOOL TWin::ShowWindow(int mode)
{
	return	::ShowWindow(hWnd, mode);
}


//��ָ������Ͷ����Ϣ
BOOL TWin::PostMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	return	::PostMessage(hWnd, uMsg, wParam, lParam);
}


//��ָ������Ͷ����Ϣ
BOOL TWin::PostMessageW(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	return	::PostMessageW(hWnd, uMsg, wParam, lParam);
}



//��ָ�����ڷ�����Ϣ
LRESULT TWin::SendMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	return	::SendMessage(hWnd, uMsg, wParam, lParam);
}


//��ָ�����ڷ�����Ϣ
LRESULT TWin::SendMessageW(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	return	::SendMessageW(hWnd, uMsg, wParam, lParam);
}


//����Ϣ���͸�ָ���ĶԻ����еĿؼ�
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




//���ڴ�����
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

//�Ѵ������ó�ǰ̨������ô���,��������ת��ô���
BOOL TWin::SetForegroundWindow(void)
{
	return	::SetForegroundWindow(hWnd);
}

//��ָ���Ĵ������õ�Z��Ķ������������Ϊ���㴰�ڣ���ô��ڱ�����������Ϊ�Ӵ��ڣ�����Ӧ�Ķ��������ڱ����
BOOL TWin::BringWindowToTop(void)
{
	return	::BringWindowToTop(hWnd);
}


//�ú�������/��ָֹ���Ĵ��ڻ�ؼ��������ͼ��̵����룬�����뱻��ֹʱ�����ڲ���Ӧ���Ͱ���������,��������ʱ�����ڽ������е�����
BOOL TWin::EnableWindow(BOOL is_enable)
{
	return	::EnableWindow(hWnd, is_enable);
}


//�ú������Ի��ָ�����ڵĿ���״̬������ʾ��������
BOOL TWin::IsWindowVisible(void)
{
	return	::IsWindowVisible(hWnd);
}


//ȷ��ĳ����ť�ؼ��Ƿ���ѡ�б�־��������̬��ť�����Ƿ�Ϊ��ɫ�ġ�ѡ�еġ������߶����ǡ�
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


//�ı䰴ť���Ƶ�ѡ��״̬
BOOL TWin::CheckDlgButton(int ctlId, UINT check)
{
	return	::CheckDlgButton(hWnd, ctlId, check);
}


//���ָ�������еĿؼ����
HWND TWin::GetDlgItem(int ctlId)
{
	return	::GetDlgItem(hWnd, ctlId);
}

//���öԻ����пؼ����ı��ͱ���
BOOL TWin::SetDlgItemTextW(int ctlId, const WCHAR *buf)
{
	return	::SetDlgItemTextW(hWnd, ctlId, buf);
}

//���öԻ����пؼ����ı��ͱ���
BOOL TWin::SetDlgItemText(int ctlId, LPCSTR buf)
{
	return	::SetDlgItemText(hWnd, ctlId, buf);
}


//����ָ���ؼ����ı�
int TWin::GetDlgItemInt(int ctlId, BOOL *err, BOOL sign)
{
	return	(int)::GetDlgItemInt(hWnd, ctlId, err, sign);
}

//���öԻ����ı�
BOOL TWin::SetDlgItemInt(int ctlId, int val, BOOL sign)
{
	return	::SetDlgItemInt(hWnd, ctlId, val, sign);
}


//�����Ի����еĿؼ���صı�����ı�
UINT TWin::GetDlgItemText(int ctlId, LPSTR buf, int len)
{
	return	::GetDlgItemText(hWnd, ctlId, buf, len);
}

//�����Ի����еĿؼ���صı�����ı�
UINT TWin::GetDlgItemTextW(int ctlId, WCHAR *buf, int len)
{
	return	::GetDlgItemTextW(hWnd, ctlId, buf, len);
}



//�ƶ����ڵ�ָ��λ��
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



//�����߳�
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



//���ô��ڽ���
BOOL TWin::SetWindowPos(HWND hInsAfter, int x, int y, int cx, int cy, UINT fuFlags)
{
	return	::SetWindowPos(hWnd, hInsAfter, x, y, cx, cy, fuFlags);
}


//��ô��ھ���
BOOL TWin::GetWindowRect(RECT *_rect)
{
	return	::GetWindowRect(hWnd, _rect ? _rect : &rect);
}


//��ÿͻ�������
BOOL TWin::GetClientRect(RECT *rc)
{
	return	::GetClientRect(hWnd, rc);
}


//����һ������(������)
HWND TWin::SetActiveWindow(void)
{
	return	::SetActiveWindow(hWnd);
}


//��ȡ�ؼ���ǰ����
int TWin::GetWindowText(LPSTR text, int size)
{
	return	::GetWindowText(hWnd, text, size);
}

//���ÿؼ�����
BOOL TWin::SetWindowText(LPCSTR text)
{
	return	::SetWindowText(hWnd, text);
}

//��ô�������
int TWin::GetWindowTextW(WCHAR *text, int size)
{
	return	::GetWindowTextW(hWnd, text, size);
}


//���ô�������
BOOL TWin::SetWindowTextW(const WCHAR *text)
{
	return	::SetWindowTextW(hWnd, text);
}


//������ݳ���
int TWin::GetWindowTextLengthW(void)
{
	return	::GetWindowTextLengthW(hWnd);
}



//��ô��������ݳ���
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


//��ָ���Ĵ�������������һ�����Σ�Ȼ�󴰿ڿͻ��������һ���ֽ������»���
BOOL TWin::InvalidateRect(const RECT *rc, BOOL fErase)
{
	return	::InvalidateRect(hWnd, rc, fErase);
}

//����ڶ��ⴰ���ڴ���ָ��ƫ��λ��ַ��32λ������ֵ
LONG_PTR TWin::GetWindowLong(int index)
{
	return	::GetWindowLong(hWnd, index);
}


LONG_PTR TWin::SetWindowLong(int index, LONG_PTR val)
{
	return	::SetWindowLong(hWnd, index, val);
}

//���ָ�����ڽṹ����Ϣ
WORD TWin::GetWindowWord(int index)
{
	return	::GetWindowWord(hWnd, index);
}


//����ָ�����ڽṹ����Ϣ
WORD TWin::SetWindowWord(int index, WORD val)
{
	return	::SetWindowWord(hWnd, index, val);
}



BOOL TWin::CreateU8(LPCSTR className, LPCSTR title, DWORD style, DWORD exStyle, HMENU hMenu)
{
	Wstr	className_w(className, BY_UTF8);
	Wstr	title_w(title, BY_UTF8);

	return	CreateW(className_w.s(), title_w.s(), style, exStyle, hMenu);//ִ������һ��Ͳ���������ͼ��    
}


BOOL TWin::Create(LPCSTR className, LPCSTR title, DWORD style, DWORD exStyle, HMENU hMenu)
{
	Wstr	className_w(className, BY_MBCS);
	Wstr	title_w(title, BY_MBCS);

	return	CreateW(className_w.s(), title_w.s(), style, exStyle, hMenu);
}