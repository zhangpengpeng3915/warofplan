#include "PlayerPlane.h"
#include"m.h"

CPlayerPlane::CPlayerPlane(void)
{
	bitmap=NULL;
	h=0;
	l=0;
}


CPlayerPlane::~CPlayerPlane(void)
{
}

void CPlayerPlane::InItplayerPlane(HINSTANCE hinstance)//初始化我方飞机，包括在屏幕上显示
{
	 h=490,l=160;//飞机所在位置
	 bitmap=LoadBitmap(hinstance,MAKEINTRESOURCE(IDB_BITMAP5));//我方飞机位图句柄
}
void CPlayerPlane::MovePlayerPlane(WPARAM wparam)//移动我方飞机
{
	switch(wparam)
			{
			case VK_UP:
				if(h>0)
				{
					h--;
				}
				break;
			case VK_DOWN:
				if(h<490)
				{
					h++;
				}
				break;
			case VK_RIGHT:
				if(l<320)
				{
					l++;
				}
				break;
			case VK_LEFT:
				if(l>0)
				{
					l--;
				}
				break;
			}
}
void CPlayerPlane::ShowPlayerPlane(HDC hdc)//显示我方飞机
{
	HDC temphdc=CreateCompatibleDC(hdc);
	SelectObject(temphdc,this->bitmap);
	BitBlt(hdc,l,h,60,60,temphdc,0,0,SRCAND);
	DeleteDC(temphdc);
}
void CPlayerPlane::SendGunner(list<Cdou*>&doulist,HINSTANCE hinstance)//我方飞机打炮弹
{
	Cdou *p=new Cdou;
	p->InItGunner(this->h,this->l,hinstance);
	doulist.push_back(p);
}