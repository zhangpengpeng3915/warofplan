#pragma once
#include"m.h"
class CBack
{
public:
	CBack(void);
	~CBack(void);
public:
	HBITMAP mapA;
	HBITMAP mapB;
	int h;
	int l;
	void ShowBack(HDC hdc);//��ʾ����ͼƬ
	void MoveBack();//����ͼƬ�ƶ�
	void InItBack(HINSTANCE hinstance);//��ʼ������
};

