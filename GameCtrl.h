#pragma once
#include<windows.h>
class CGameCtrl;
typedef CGameCtrl * (* CreatePfunction)();//定义一个返回类型为CGameCtrl *  的函数指针，目的指向创建其子类的函数，从而实现多态

class CGameCtrl//游戏主控接口类
{
public:
	 HWND hwnd;
	 HINSTANCE hinstance;
	 void SET(HWND hwnd,HINSTANCE hinstance);//使其子类可以使用数据成员
public:
	static CreatePfunction createobjectpfunction;//定义一个静态的函数的指针，最终创建其子类初始化winmain中的ctrl指针
public:
	CGameCtrl(void);
	virtual ~CGameCtrl(void);
public:
	//virtual void GameRun(HWND hwnd,HINSTANCE hinstance);//不用纯虚函数是因为子类不一定用到
	virtual void m_WM_KEYDOWN(WPARAM wparam){};
	virtual void m_WM_KEYUP(WPARAM wparam){};
	virtual void m_WM_MOUSEMOVE(){};
	virtual void m_WM_ONLBUTTERNL(){};
	virtual void m_WM_ONLBUTTERNR(){};
	virtual void CreateGame(){};//创建游戏
	virtual void GameDraw(){};//界面重绘 
	virtual void GameRun(WPARAM wparam){};//游戏启动


public:


};


class INIT 
{
public :
	INIT(CreatePfunction pfn )
	{
		CGameCtrl ::createobjectpfunction=pfn;

	}
	~INIT()
	{
	}
};
