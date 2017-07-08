#include "MiddlePlane.h"


CMiddlePlane::CMiddlePlane(void)
{
	boold=3;
	number=3;
	l=rand()%(380-180);
	h=-128;
	this->bitmap=NULL;
 
}


CMiddlePlane::~CMiddlePlane(void)
{
}
void CMiddlePlane::InItFeoPlane(HINSTANCE hinstance)
{
	bitmap=LoadBitmap(hinstance,MAKEINTRESOURCE(IDB_BITMAP4));
}
void CMiddlePlane::ShowFeoPlane(HDC hdc)
{
	HDC temphdc=CreateCompatibleDC(hdc);
	SelectObject(temphdc,bitmap);
	BitBlt(hdc,l,h,70,90,temphdc,0,(3-number)*90,SRCAND);
	DeleteDC(temphdc);
}
void CMiddlePlane::MoveFeoPlane()
{
	h+=4;
}
bool CMiddlePlane::IS_HITGunner(Cdou * pgunner)
{
	if(pgunner->l+30 >= this->l && pgunner->l+30 <= this->l+70
		&& pgunner->h >= this->h && pgunner->h <= this->h+90)
	{
		this->boold--;
		return true;
	}

	return false;
}
bool CMiddlePlane::IS_Bump()
{
	if(boold==0)
	{
		return true;
	}
	return false;
}
bool CMiddlePlane::IS_HITPlayerplane(CPlayerPlane &plane)
{
	if(plane.l+30 >= this->l && plane.l+30 <= this->l+70
		&& plane.h >= this->h && plane.h <= this->h+90)
	{
		return true;
	}

	return false;

}
