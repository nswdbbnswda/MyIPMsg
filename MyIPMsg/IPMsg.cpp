#include<Windows.h>
#include"app.h"


//���������
int WINAPI WinMain(HINSTANCE hI, HINSTANCE, LPSTR cmdLine, int nCmdShow)
{
	TMsgApp app(hI,cmdLine,nCmdShow);//���캯��
	return app.Run();
}