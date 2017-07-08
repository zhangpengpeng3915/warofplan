#pragma once
#include"m.h"
#include"Cdou.h"

class CPlayerPlane
{
public:
	CPlayerPlane(void);
	~CPlayerPlane(void);
public:
	int h,l;//飞机所在位置
	HBITMAP bitmap;//我方飞机位图句柄
	int planeblood;//我方飞机血量----1.0版本还未实现即只有一次生命
public:
	void InItplayerPlane(HINSTANCE hinstance);//初始化我方飞机，包括在屏幕上显示
	void MovePlayerPlane(WPARAM wparam);//移动我方飞机
	void ShowPlayerPlane(HDC hdc);//显示我方飞机
	void SendGunner(list<Cdou*>&doulist,HINSTANCE hinstance);//我方飞机打炮弹
};

