#include "Cdou.h"


Cdou::Cdou(void)
{
	h=0;
	l=0;
	bitmap=NULL;
}


Cdou::~Cdou(void)
{
	
}

void Cdou::InItGunner(int h,int l,HINSTANCE hinstance)//初始化炮弹
{
	this->h=h;
	this->l=l;
	bitmap=LoadBitmap(hinstance,MAKEINTRESOURCE(IDB_BITMAP1));//加载位图
}
void Cdou::ShowGunner(HDC hdc)//显示炮弹
{
	HDC temphdc=CreateCompatibleDC(hdc);//创建临时设备句柄
	SelectObject(temphdc,bitmap);
	BitBlt(hdc,l+27,h,6,9,temphdc,0,0,SRCAND);
	DeleteDC(temphdc);
}
void Cdou::MoveGunner()//移动炮弹
{
	h-=6;
}