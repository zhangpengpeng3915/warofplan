#include "Back.h"


CBack::~CBack(void)
{
	
}

CBack::CBack(void)
{
	mapA=NULL;
	mapB=NULL;
	h=-550;
	l=0;
}

void CBack::ShowBack(HDC hdc)//将两张图循环显示
{
	HDC tempdca=CreateCompatibleDC(hdc);
	HDC tempdcb=CreateCompatibleDC(hdc);
	SelectObject(tempdca,mapA);
	SelectObject(tempdcb,mapB);
	BitBlt(hdc,l,h,380,550,tempdca,0,0,SRCCOPY);
	BitBlt(hdc,l,h+550,380,550,tempdca,0,0,SRCCOPY);
	DeleteDC(tempdca);
	DeleteDC(tempdcb);
}
void CBack::MoveBack()
{
	if(h == 0)//这个自己想吧
	{
		h = -550;
	}
	else
	{
		h++;
	}
}
void CBack::InItBack(HINSTANCE hinstance)
{
	mapA=LoadBitmap(hinstance,MAKEINTRESOURCE(IDB_BITMAP3));
	mapB=LoadBitmap(hinstance,MAKEINTRESOURCE(IDB_BITMAP3));
}






