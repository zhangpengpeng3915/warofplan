#include<windows.h>

#include<time.h>

#include"gamectrl.h"




LRESULT CALLBACK MY_WNDPROC(HWND, UINT, WPARAM, LPARAM);//应用程序消息处理函数

HINSTANCE hinstace=NULL;//定义全局变量的应运程序句柄，方便非主函数的其他被调函数使用

int CALLBACK WinMain(HINSTANCE hinstance,HINSTANCE prvhinsatnce,LPSTR lpCmdLine,int nCmdShow )//主程序入口
{
	srand( time(0));//随机数种子
	hinstace =hinstance;//初始化应用程序句柄
	//设计窗口
	WNDCLASSEX EX;//窗口信息存储的结构体
	HWND hwnd;
	MSG msg;//用于存储捕获到的消息
	
	EX.cbSize=sizeof(EX);
	EX.cbClsExtra=0;
	EX.cbWndExtra=0;
	EX.style=0;//CS_HREDRAW|CS_VREDRAW;//shui ping shua xin yu chuizhi shua xin 
	EX.hbrBackground=CreateSolidBrush(RGB(300,158,691));
	EX.hCursor=0;
	EX.hIcon=0;
	EX.hInstance=hinstance;
	EX.hIconSm=0;
	EX.lpszClassName=L"zpp";
	EX.lpszMenuName=NULL;
	EX.lpfnWndProc=MY_WNDPROC;//处理消息
	//注册窗口
	RegisterClassEx(&EX);
	//创建窗口
	hwnd=CreateWindow(L"zpp",L"zppwindows",WS_OVERLAPPEDWINDOW,100,50,396,588,NULL,NULL,hinstance,NULL);
	//显示窗口
	ShowWindow(hwnd,nCmdShow);


	//消息循环
	//1. 获得消息
	while(GetMessage(&msg,0,/* 不传hwnd 则捕获整个屏幕的消息，否则只捕获hwnd这个窗口的消息*/0,0))
	{
		//2. 翻译消息
		TranslateMessage(&msg);
		//3. 处理并分发消息
		DispatchMessage(&msg);//该函数调度一个消息给窗口程序。通常调度从GetMessage取得的消息。
	}

}


CGameCtrl *ctrl=NULL;//游戏控制器的父类指针，方便后期的游戏扩展，例如这里写了一个飞机大战的，后期可以将其应用于类似游戏 如贪吃蛇的开发等等

LRESULT CALLBACK MY_WNDPROC(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)//msg 处理函数
{
										
	switch (msg)//根据应用程序消息队列的消息进行分类
	{
	case WM_CREATE://创建游戏
		if(CGameCtrl::createobjectpfunction==NULL)//如果父类当中的静态函数指针没有被初始化
		{
			MessageBox(NULL,L"ｃｒｅａｔｅ  failed!",NULL,NULL);
		}
		
		ctrl=CGameCtrl::createobjectpfunction();//调用函数指针创建飞机大战的游戏控制器
		ctrl->SET(hwnd,hinstace);//初始化父类当中的指向主程序窗口的句柄和程序句柄
		ctrl->CreateGame();//创建游戏开始，调用子类的虚函数
		break;
	case WM_TIMER://处理定时器消息
		ctrl->GameRun(wparam);//定时器控制游戏运行
		break;
	case WM_KEYDOWN:	//处理键盘按下消息
		ctrl->m_WM_KEYDOWN(wparam);
		break;
	case WM_KEYUP://处理键盘抬起消息
		ctrl->m_WM_KEYUP(wparam);
		break;
	case WM_PAINT://游戏界面的处理
		ctrl->GameDraw();
		break;
	case WM_LBUTTONDOWN://鼠标处理
		
		break;
	case WM_CLOSE://窗口关闭
		DestroyWindow(hwnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);//窗口销毁
		break;

	}
	return DefWindowProc(hwnd,msg,wparam,lparam);//回调函数 函数功能：该函数调用缺省的窗口过程来为应用程序没有处理的任何窗口消息提供缺省的处理。该函数确保每一个消息得到处理。调用DefWindowProc函数时使用窗口过程接收的相同参数。
}



