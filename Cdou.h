#pragma once
#include"m.h"
class Cdou//==gunner�ɻ��ڵ�
{
public:
	Cdou(void);
	~Cdou(void);
public:
	int h,l;
	HBITMAP bitmap;
public :
	void InItGunner(int h,int l,HINSTANCE hinstance);//��ʼ���ڵ�
	void ShowGunner(HDC hdc);//��ʾ�ڵ�
	void MoveGunner();//�ƶ��ڵ�

};

