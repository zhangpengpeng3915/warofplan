#pragma once
#include"gamectrl.h"
#include"playerplane.h"
#include"m.h"
#include"CdiRenPlane.h"
#include"MaxPlane.h"
#include"Cdou.h"
#include"Back.h"
#include"MiddlePlane.h"
#include"SmallPlane.h"
class CPlanectrl:public CGameCtrl//��Ϸ������
{
public:
	CPlanectrl(void);
	~CPlanectrl(void);
public:
	bool flag1;//���̰�����̧��ı��
	CBack mapvback;//����
	CPlayerPlane myplane;//�ҷ��ɻ�
	list<CdiRenPlane *>FEO_list;//�洢����Ļ����ʵ�ķɻ�
	list<Cdou *> gunnerlist;//  �ڵ�����
	list<CdiRenPlane *>DeadFeoList;//��ը�ĵ��˷ɻ�����
	//��ʱ��

public:
	void CreateGame();//������Ϸ
	void GameDraw();//�����ػ� 
	void GameRun(WPARAM wparam);//��Ϸ����
	void ShowAllGunner(HDC hdc);//��ʾ���е��ڵ�
	void CreateFeoplane();//�������˷ɻ�
	void ShowAllFeoplane(HDC hdc);//��ʾ���еĵ��˷ɻ�
	void ShowAllBoomFeoPlane(HDC hdc);
	//��ʾ���еĵз���ը�ɻ�
	void MoveAllBoomFeoPlane();
	void DeleteFeoplane();//ɾ�����˷ɻ�
	void DeleteGunner();//ɾ���ڵ�
	//�ƶ������ڵ�
	void MoveAllGunner();
	//�ƶ����е��˷ɻ�
	void MoveAllFeoPlane();
	//������Ϣ����
	void SelectKEY_Message();
	//���˷ɻ������ҷ��ɻ�
	bool IS_FeoplanedestruyMyplane();
	//�ڵ��򵽵з��ɻ�
	bool IS_GunnerdestroyFeoplane();
	
	//���̰�����̧��
	void m_WM_KEYDOWN(WPARAM wparam);
	void m_WM_KEYUP(WPARAM wparam);
};

