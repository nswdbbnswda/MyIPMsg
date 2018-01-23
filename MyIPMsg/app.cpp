#include"app.h"
#include<debugapi.h>

TApp* TApp::tapp = NULL;

TApp::TApp(HINSTANCE _hI, LPSTR _cmdLine, int _nCmdShow)
{
	hI = _hI;
	cmdLine = _cmdLine;
	nCmdShow = _nCmdShow;
	mainWnd = NULL;
	preWnd = NULL;
	defaultClass = "tapp";
	defaultClassW = L"tapp";//���ַ��汾
	tapp = this;
	twinId = 1;
}

TApp::~TApp()
{
}

BOOL TApp::InitApp(void)
{
	WNDCLASSW wc;//�����ɸ����������
	wc.style = CS_HREDRAW | CS_VREDRAW; //���ô��ڷ��
	wc.lpfnWndProc = WinProc;//������Ǵ����ɸ봫�������ڵĺ����������������ڵ���Ϣ��Ӧ����ΪTApp:WinProc
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hI;//�����ʵ�����
	wc.hIcon = LoadIcon(TApp::GetInstance(),(LPCSTR)IDI_ICON1);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);//���������Դ
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);//���ô��ڵı�����ɫ
	wc.lpszMenuName = NULL;//�����ò˵�
	wc.lpszClassName = defaultClassW;
	if (::FindWindowW(defaultClassW, NULL) == NULL)
	{
		if (::RegisterClassW(&wc) == 0)//ע�ᴰ����
			return FALSE;
	}
	return	TRUE;
}

int TApp::Run()
{
    MSG		msg;//������Ϣ�ṹ
    InitApp();//�����������Լ�ע�ᴰ����
	InitWindow();//��ʼ������
	while (::GetMessage(&msg, NULL, 0, 0))
	{
		//if (PreProcMsg(&msg))
		//	continue;
		::TranslateMessage(&msg);//������Ϣ
		::DispatchMessage(&msg);//ת����Ϣ
	}
	return	(int)msg.wParam;	
}
//���봰����Ϣ�Լ�ȷ���Ƿ��ǶԻ�����Ϣ
BOOL TApp::PreProcMsg(MSG * msg)
{
	//for (HWND hWnd = msg->hwnd; hWnd; hWnd = ::GetParent(hWnd))
	//{
	//	TWin	*win = SearchWnd(hWnd);//�ӹ�ϣ�����ҵ�������ھ��
	//	if (win)
	//		return	win->PreProcMsg(msg);
	//}
	return	FALSE;
}

//������Ϣ������
LRESULT CALLBACK TApp::WinProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	//TApp	*app = TApp::GetApp();//���app����ָ��
	//TWin	*win = app->SearchWnd(hWnd);//�ӹ�ϣ���и��ݴ��ھ���ҵ���Ӧ�Ĵ��������ָ��


	//if (win)//����ڹ�ϣ�����ҵ���һ���������
	//	return	win->WinProc(uMsg, wParam, lParam); //ִ�иö���Ĵ�����Ϣ��Ӧ����

	//if ((win = app->preWnd))//��TMainWin���ڵ�һ����Ϣ������е������жϡ�
	//{
	//	app->preWnd = NULL;
	//	app->AddWinByWnd(win, hWnd);
	//	return	win->WinProc(uMsg, wParam, lParam);
	//}
	switch (uMsg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return	::DefWindowProc(hWnd, uMsg, wParam, lParam);
}

//*********************************************APP����******************************************************************/
TMsgApp::TMsgApp(HINSTANCE _hI, LPSTR _cmdLine, int _nCmdShow) : TApp(_hI, _cmdLine, _nCmdShow)
{
	LoadLibrary("RICHED20.DLL");
	//srand((UINT)Time());//�ṩ�������
}

TMsgApp::~TMsgApp()
{

}
//�����ﴴ�����ִ���
void TMsgApp::InitWindow(void)
{
    HWND hwnd = ::CreateWindowExW(WS_EX_OVERLAPPEDWINDOW,this->defaultClassW, defaultClassW, WS_OVERLAPPEDWINDOW,
    250, 0, CW_USEDEFAULT, CW_USEDEFAULT,NULL, NULL, this->hI, NULL);
    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);
}
