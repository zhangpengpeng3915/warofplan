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

void CPlayerPlane::InItplayerPlane(HINSTANCE hinstance)//��ʼ���ҷ��ɻ�����������Ļ����ʾ
{
	 h=490,l=160;//�ɻ�����λ��
	 bitmap=LoadBitmap(hinstance,MAKEINTRESOURCE(IDB_BITMAP5));//�ҷ��ɻ�λͼ���
}
void CPlayerPlane::MovePlayerPlane(WPARAM wparam)//�ƶ��ҷ��ɻ�
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
void CPlayerPlane::ShowPlayerPlane(HDC hdc)//��ʾ�ҷ��ɻ�
{
	HDC temphdc=CreateCompatibleDC(hdc);
	SelectObject(temphdc,this->bitmap);
	BitBlt(hdc,l,h,60,60,temphdc,0,0,SRCAND);
	DeleteDC(temphdc);
}
void CPlayerPlane::SendGunner(list<Cdou*>&doulist,HINSTANCE hinstance)//�ҷ��ɻ����ڵ�
{
	Cdou *p=new Cdou;
	p->InItGunner(this->h,this->l,hinstance);
	doulist.push_back(p);
}