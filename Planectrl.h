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
class CPlanectrl:public CGameCtrl//游戏控制器
{
public:
	CPlanectrl(void);
	~CPlanectrl(void);
public:
	bool flag1;//键盘按下与抬起的标记
	CBack mapvback;//背景
	CPlayerPlane myplane;//我方飞机
	list<CdiRenPlane *>FEO_list;//存储在屏幕上现实的飞机
	list<Cdou *> gunnerlist;//  炮弹链表
	list<CdiRenPlane *>DeadFeoList;//爆炸的敌人飞机链表
	//定时器

public:
	void CreateGame();//创建游戏
	void GameDraw();//界面重绘 
	void GameRun(WPARAM wparam);//游戏启动
	void ShowAllGunner(HDC hdc);//显示所有的炮弹
	void CreateFeoplane();//创建敌人飞机
	void ShowAllFeoplane(HDC hdc);//显示所有的敌人飞机
	void ShowAllBoomFeoPlane(HDC hdc);
	//显示所有的敌方爆炸飞机
	void MoveAllBoomFeoPlane();
	void DeleteFeoplane();//删除敌人飞机
	void DeleteGunner();//删除炮弹
	//移动所有炮弹
	void MoveAllGunner();
	//移动所有敌人飞机
	void MoveAllFeoPlane();
	//键盘消息处理
	void SelectKEY_Message();
	//敌人飞机碰到我方飞机
	bool IS_FeoplanedestruyMyplane();
	//炮弹打到敌方飞机
	bool IS_GunnerdestroyFeoplane();
	
	//键盘按下与抬起
	void m_WM_KEYDOWN(WPARAM wparam);
	void m_WM_KEYUP(WPARAM wparam);
};

