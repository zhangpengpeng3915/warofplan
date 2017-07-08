#include "MaxPlane.h"


CMaxPlane::CMaxPlane(void)
{
	 number=4;
	 boold=6;
	l=rand()%(380-108);
	h=-128;
	this->bitmap=NULL;
}
CMaxPlane::~CMaxPlane(void)
{
}
void CMaxPlane::InItFeoPlane(HINSTANCE hinstance)//��ʼ����ŵ��˷ɻ�
{
	bitmap=LoadBitmap(hinstance,MAKEINTRESOURCE(IDB_BITMAP2));
}
void CMaxPlane::ShowFeoPlane(HDC hdc)//��ʾ���˷ɻ�
{
	HDC temphdc=CreateCompatibleDC(hdc);
	SelectObject(temphdc,bitmap);
	BitBlt(hdc,l,h,108,128,temphdc,0,(4-number)*128,SRCAND);
	DeleteDC(temphdc);
}
void CMaxPlane::MoveFeoPlane()//�����˷ɻ��������ı�
{
	h+=2;
}
bool CMaxPlane::IS_HITGunner(Cdou * pgunner)//�Ƿ��ڵ�����
{
	if(pgunner->l+30 >= this->l && pgunner->l+30 <= this->l+108
		&& pgunner->h >= this->h && pgunner->h <= this->h+128)
	{
		boold--;
		return true;
	}
	return false;
}
bool CMaxPlane::IS_Bump()
{
	if(boold==0)
	{
		return true;
	}
	return false;
}
bool CMaxPlane::IS_HITPlayerplane(CPlayerPlane &plane)//�Ƿ�����ҷɻ���ײ
{
	if(plane.l+30 >= this->l && plane.l+30 <= this->l+108
		&& plane.h >= this->h && plane.h <= this->h+128)
	{
		return true;
	}

	return false;
}
