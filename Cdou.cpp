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

void Cdou::InItGunner(int h,int l,HINSTANCE hinstance)//��ʼ���ڵ�
{
	this->h=h;
	this->l=l;
	bitmap=LoadBitmap(hinstance,MAKEINTRESOURCE(IDB_BITMAP1));//����λͼ
}
void Cdou::ShowGunner(HDC hdc)//��ʾ�ڵ�
{
	HDC temphdc=CreateCompatibleDC(hdc);//������ʱ�豸���
	SelectObject(temphdc,bitmap);
	BitBlt(hdc,l+27,h,6,9,temphdc,0,0,SRCAND);
	DeleteDC(temphdc);
}
void Cdou::MoveGunner()//�ƶ��ڵ�
{
	h-=6;
}