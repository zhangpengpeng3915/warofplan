#pragma once
#include"m.h"
#include"Cdou.h"

class CPlayerPlane
{
public:
	CPlayerPlane(void);
	~CPlayerPlane(void);
public:
	int h,l;//�ɻ�����λ��
	HBITMAP bitmap;//�ҷ��ɻ�λͼ���
	int planeblood;//�ҷ��ɻ�Ѫ��----1.0�汾��δʵ�ּ�ֻ��һ������
public:
	void InItplayerPlane(HINSTANCE hinstance);//��ʼ���ҷ��ɻ�����������Ļ����ʾ
	void MovePlayerPlane(WPARAM wparam);//�ƶ��ҷ��ɻ�
	void ShowPlayerPlane(HDC hdc);//��ʾ�ҷ��ɻ�
	void SendGunner(list<Cdou*>&doulist,HINSTANCE hinstance);//�ҷ��ɻ����ڵ�
};

