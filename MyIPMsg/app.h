
#include<Windows.h>
#include<iostream>
#include"resource.h"
#include"tlib.h"
#include"TWin.h"

//抽象APP类
class TApp {
protected:
	static TApp	*tapp;//静态成员变量，只能在类外初始化，只能定义一次，可以被这个类的所有子类共享
	LPCSTR		defaultClass;//窗体名称
	LPCWSTR		defaultClassW;
	LPSTR		cmdLine;//命令行参数
	int			nCmdShow;//窗口的显示方式
	HINSTANCE	hI;//程序实例句柄
	DWORD		twinId;//窗体ID号
	TWin		*mainWnd;//主窗口类指针
	TWin		*preWnd;//上一个窗体
	TWinHashTbl	*hash;//窗体哈希表
	virtual BOOL	InitApp(void);//初始化APP
public:
	TApp(HINSTANCE _hI, LPSTR _cmdLine, int _nCmdShow);//构造函数
	virtual ~TApp();//虚析构函数
	virtual void	InitWindow() = 0;//初始
	virtual int		Run();//虚函数
	virtual BOOL	PreProcMsg(MSG *msg);//窗口消息预处理
	LPCSTR	GetDefaultClass() { return defaultClass; }
	LPCWSTR	GetDefaultClassW() { return defaultClassW; }
	void	AddWin(TWin *win) { preWnd = win; }//添加一个窗口
	void	AddWinByWnd(TWin *win, HWND hWnd) {//添加一个窗口
		win->hWnd = hWnd;
		hash->Register(win, hash->MakeHashId(hWnd));
	}
	void	DelWin(TWin *win) { hash->UnRegister(win); }//删除一个窗口
	TWin	*SearchWnd(HWND hWnd) {//查找窗口
		return (TWin *)hash->Search(&hWnd, hash->MakeHashId(hWnd));
	}

	int GetHashNum() { return hash->GetRegisterNum(); }//获得哈希表中的元素个数
	static TApp *GetApp() { return tapp; }//获得APP指针
	static void Idle(DWORD timeout = 0);
	static HINSTANCE GetInstance() { return tapp->hI; }	//获得程序的实例句柄									   											       
	static LRESULT CALLBACK WinProc(HWND hW, UINT uMsg, WPARAM wParam, LPARAM lParam);//窗口回调函数
	static DWORD  GenTWinID() { return tapp ? tapp->twinId++ : 0; }//获得窗体ID
};


//派生app类
class TMsgApp : public TApp {
public:
	TMsgApp(HINSTANCE _hI, LPSTR _cmdLine, int _nCmdShow);//构造函数
	virtual ~TMsgApp();//析构函数
	virtual void	InitWindow(void);//实例化初始化窗体
};