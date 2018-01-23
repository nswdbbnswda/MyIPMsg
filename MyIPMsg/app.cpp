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
	defaultClassW = L"tapp";//宽字符版本
	tapp = this;
	twinId = 1;
}

TApp::~TApp()
{
}

BOOL TApp::InitApp(void)
{
	WNDCLASSW wc;//创建飞鸽的主窗口类
	wc.style = CS_HREDRAW | CS_VREDRAW; //设置窗口风格
	wc.lpfnWndProc = WinProc;//这个就是创建飞鸽传书主窗口的函数，并设置主窗口的消息响应函数为TApp:WinProc
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hI;//程序的实例句柄
	wc.hIcon = LoadIcon(TApp::GetInstance(),(LPCSTR)IDI_ICON1);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);//加载鼠标资源
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);//设置窗口的背景颜色
	wc.lpszMenuName = NULL;//不设置菜单
	wc.lpszClassName = defaultClassW;
	if (::FindWindowW(defaultClassW, NULL) == NULL)
	{
		if (::RegisterClassW(&wc) == 0)//注册窗口类
			return FALSE;
	}
	return	TRUE;
}

int TApp::Run()
{
    MSG		msg;//创建消息结构
    InitApp();//创建窗口类以及注册窗口类
	InitWindow();//初始化窗体
	while (::GetMessage(&msg, NULL, 0, 0))
	{
		//if (PreProcMsg(&msg))
		//	continue;
		::TranslateMessage(&msg);//翻译消息
		::DispatchMessage(&msg);//转发消息
	}
	return	(int)msg.wParam;	
}
//翻译窗口消息以及确认是否是对话框消息
BOOL TApp::PreProcMsg(MSG * msg)
{
	//for (HWND hWnd = msg->hwnd; hWnd; hWnd = ::GetParent(hWnd))
	//{
	//	TWin	*win = SearchWnd(hWnd);//从哈希表中找到这个窗口句柄
	//	if (win)
	//		return	win->PreProcMsg(msg);
	//}
	return	FALSE;
}

//窗口消息处理函数
LRESULT CALLBACK TApp::WinProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	//TApp	*app = TApp::GetApp();//获得app对象指针
	//TWin	*win = app->SearchWnd(hWnd);//从哈希表中根据窗口句柄找到对应的窗口类对象指针


	//if (win)//如果在哈希表中找到了一个窗体对象
	//	return	win->WinProc(uMsg, wParam, lParam); //执行该对象的窗口消息响应函数

	//if ((win = app->preWnd))//对TMainWin窗口第一次消息处理进行的特殊判断。
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

//*********************************************APP子类******************************************************************/
TMsgApp::TMsgApp(HINSTANCE _hI, LPSTR _cmdLine, int _nCmdShow) : TApp(_hI, _cmdLine, _nCmdShow)
{
	LoadLibrary("RICHED20.DLL");
	//srand((UINT)Time());//提供随机种子
}

TMsgApp::~TMsgApp()
{

}
//在这里创建各种窗口
void TMsgApp::InitWindow(void)
{
    HWND hwnd = ::CreateWindowExW(WS_EX_OVERLAPPEDWINDOW,this->defaultClassW, defaultClassW, WS_OVERLAPPEDWINDOW,
    250, 0, CW_USEDEFAULT, CW_USEDEFAULT,NULL, NULL, this->hI, NULL);
    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);
}
