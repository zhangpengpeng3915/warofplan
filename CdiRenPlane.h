#pragma once
#include"m.h"
#include"Cdou.h"
#include"PlayerPlane.h"
class CdiRenPlane
{
public:
	int number;//游戏中显示第几张图片---让子类中继承使用
	int boold;//血量  子类可使用
	CdiRenPlane(void);
	virtual ~CdiRenPlane(void);
public:
	int h,l;//图片的纵坐标与横坐标
	HBITMAP bitmap;//飞机图片  子类可使用
	virtual void InItFeoPlane(HINSTANCE hinstance)=0;//初始化敌人飞机
	virtual void ShowFeoPlane(HDC hdc)=0;//显示敌人飞机
	virtual void MoveFeoPlane()=0;//敌人飞机移动
	virtual bool IS_HITGunner(Cdou * pgunner)=0;//是否与玩家子弹相撞
	virtual bool IS_HITPlayerplane(CPlayerPlane &plane)=0;//是否与玩家飞机相撞 以玩家飞机头为生死判点
	virtual bool IS_Bump()=0;//是否被打爆
};

