#pragma once
#include<windows.h>
class CGameCtrl;
typedef CGameCtrl * (* CreatePfunction)();//����һ����������ΪCGameCtrl *  �ĺ���ָ�룬Ŀ��ָ�򴴽�������ĺ������Ӷ�ʵ�ֶ�̬

class CGameCtrl//��Ϸ���ؽӿ���
{
public:
	 HWND hwnd;
	 HINSTANCE hinstance;
	 void SET(HWND hwnd,HINSTANCE hinstance);//ʹ���������ʹ�����ݳ�Ա
public:
	static CreatePfunction createobjectpfunction;//����һ����̬�ĺ�����ָ�룬���մ����������ʼ��winmain�е�ctrlָ��
public:
	CGameCtrl(void);
	virtual ~CGameCtrl(void);
public:
	//virtual void GameRun(HWND hwnd,HINSTANCE hinstance);//���ô��麯������Ϊ���಻һ���õ�
	virtual void m_WM_KEYDOWN(WPARAM wparam){};
	virtual void m_WM_KEYUP(WPARAM wparam){};
	virtual void m_WM_MOUSEMOVE(){};
	virtual void m_WM_ONLBUTTERNL(){};
	virtual void m_WM_ONLBUTTERNR(){};
	virtual void CreateGame(){};//������Ϸ
	virtual void GameDraw(){};//�����ػ� 
	virtual void GameRun(WPARAM wparam){};//��Ϸ����


public:


};


class INIT 
{
public :
	INIT(CreatePfunction pfn )
	{
		CGameCtrl ::createobjectpfunction=pfn;

	}
	~INIT()
	{
	}
};
