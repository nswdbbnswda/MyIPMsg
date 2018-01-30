
#include<Windows.h>
#include<iostream>
#include"resource.h"
#include"tlib.h"
#include"TWin.h"

//����APP��
class TApp {
protected:
	static TApp	*tapp;//��̬��Ա������ֻ���������ʼ����ֻ�ܶ���һ�Σ����Ա��������������๲��
	LPCSTR		defaultClass;//��������
	LPCWSTR		defaultClassW;
	LPSTR		cmdLine;//�����в���
	int			nCmdShow;//���ڵ���ʾ��ʽ
	HINSTANCE	hI;//����ʵ�����
	DWORD		twinId;//����ID��
	TWin		*mainWnd;//��������ָ��
	TWin		*preWnd;//��һ������
	TWinHashTbl	*hash;//�����ϣ��
	virtual BOOL	InitApp(void);//��ʼ��APP
public:
	TApp(HINSTANCE _hI, LPSTR _cmdLine, int _nCmdShow);//���캯��
	virtual ~TApp();//����������
	virtual void	InitWindow() = 0;//��ʼ
	virtual int		Run();//�麯��
	virtual BOOL	PreProcMsg(MSG *msg);//������ϢԤ����
	LPCSTR	GetDefaultClass() { return defaultClass; }
	LPCWSTR	GetDefaultClassW() { return defaultClassW; }
	void	AddWin(TWin *win) { preWnd = win; }//���һ������
	void	AddWinByWnd(TWin *win, HWND hWnd) {//���һ������
		win->hWnd = hWnd;
		hash->Register(win, hash->MakeHashId(hWnd));
	}
	void	DelWin(TWin *win) { hash->UnRegister(win); }//ɾ��һ������
	TWin	*SearchWnd(HWND hWnd) {//���Ҵ���
		return (TWin *)hash->Search(&hWnd, hash->MakeHashId(hWnd));
	}

	int GetHashNum() { return hash->GetRegisterNum(); }//��ù�ϣ���е�Ԫ�ظ���
	static TApp *GetApp() { return tapp; }//���APPָ��
	static void Idle(DWORD timeout = 0);
	static HINSTANCE GetInstance() { return tapp->hI; }	//��ó����ʵ�����									   											       
	static LRESULT CALLBACK WinProc(HWND hW, UINT uMsg, WPARAM wParam, LPARAM lParam);//���ڻص�����
	static DWORD  GenTWinID() { return tapp ? tapp->twinId++ : 0; }//��ô���ID
};


//����app��
class TMsgApp : public TApp {
public:
	TMsgApp(HINSTANCE _hI, LPSTR _cmdLine, int _nCmdShow);//���캯��
	virtual ~TMsgApp();//��������
	virtual void	InitWindow(void);//ʵ������ʼ������
};