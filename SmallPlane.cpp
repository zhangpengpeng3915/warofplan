#include "SmallPlane.h"


CSmallPlane::CSmallPlane(void)
{
	boold=1;
	number=2;
	l=rand()%(380-180);
	h=-128;
	this->bitmap=NULL;
 
}


CSmallPlane::~CSmallPlane(void)
{
}
void CSmallPlane::InItFeoPlane(HINSTANCE hinstance)
{
	bitmap=LoadBitmap(hinstance,MAKEINTRESOURCE(IDB_BITMAP7));
}
void CSmallPlane::ShowFeoPlane(HDC hdc)
{
	HDC temphdc=CreateCompatibleDC(hdc);
	SelectObject(temphdc,bitmap);
	BitBlt(hdc,l,h,34,28,temphdc,0,(2-number)*28,SRCAND);
	DeleteDC(temphdc);
}
void CSmallPlane::MoveFeoPlane()
{
	h+=6;
}
bool CSmallPlane::IS_HITGunner(Cdou *pgunner)
{
	if( pgunner->l+30 >= this->l && pgunner->l+30 <= this->l+34
		&& pgunner->h >= this->h && pgunner->h <= this->h+28)
	{
		boold--;
		return true;
	}

	return false;
}
bool CSmallPlane::IS_Bump()
{
	if(boold==0)
	{
		return true;
	}
	return false;
}
bool CSmallPlane::IS_HITPlayerplane(CPlayerPlane &plane)
{
	if(plane.l+30 >= this->l && plane.l+30 <= this->l+34
		&& plane.h >= this->h && plane.h <= this->h+28)
	{
		return true;
	}

	return false;
	return false;
	return false;
}
