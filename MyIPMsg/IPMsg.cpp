#include<Windows.h>
#include"app.h"


//主函数入口
int WINAPI WinMain(HINSTANCE hI, HINSTANCE, LPSTR cmdLine, int nCmdShow)
{
	TMsgApp app(hI,cmdLine,nCmdShow);//构造函数
	return app.Run();
}