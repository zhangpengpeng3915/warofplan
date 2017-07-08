#pragma once
#include"m.h"
class Cdou//==gunner飞机炮弹
{
public:
	Cdou(void);
	~Cdou(void);
public:
	int h,l;
	HBITMAP bitmap;
public :
	void InItGunner(int h,int l,HINSTANCE hinstance);//初始化炮弹
	void ShowGunner(HDC hdc);//显示炮弹
	void MoveGunner();//移动炮弹

};

