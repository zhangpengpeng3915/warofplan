#pragma once
#include"m.h"
#include"Cdou.h"
#include"PlayerPlane.h"
class CdiRenPlane
{
public:
	int number;//��Ϸ����ʾ�ڼ���ͼƬ---�������м̳�ʹ��
	int boold;//Ѫ��  �����ʹ��
	CdiRenPlane(void);
	virtual ~CdiRenPlane(void);
public:
	int h,l;//ͼƬ���������������
	HBITMAP bitmap;//�ɻ�ͼƬ  �����ʹ��
	virtual void InItFeoPlane(HINSTANCE hinstance)=0;//��ʼ�����˷ɻ�
	virtual void ShowFeoPlane(HDC hdc)=0;//��ʾ���˷ɻ�
	virtual void MoveFeoPlane()=0;//���˷ɻ��ƶ�
	virtual bool IS_HITGunner(Cdou * pgunner)=0;//�Ƿ�������ӵ���ײ
	virtual bool IS_HITPlayerplane(CPlayerPlane &plane)=0;//�Ƿ�����ҷɻ���ײ ����ҷɻ�ͷΪ�����е�
	virtual bool IS_Bump()=0;//�Ƿ񱻴�
};

