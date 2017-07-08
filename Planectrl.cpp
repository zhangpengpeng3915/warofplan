#include "Planectrl.h"

	CPlanectrl::CPlanectrl(void)
	{
		
	}
	CPlanectrl::~CPlanectrl(void)
	{

	}
	void CPlanectrl::CreateGame()//创建游戏
	{
		mapvback.InItBack(CGameCtrl::hinstance);//初始化背景
		myplane.InItplayerPlane(CGameCtrl::hinstance);//初始化玩家飞机
		//  启动定时器
	::SetTimer(CGameCtrl::hwnd,BACK_MOVE_TIMER_ID,1,NULL);// 背景的移动   数字代表定时器发送消息的时间间隔
	::SetTimer(CGameCtrl::hwnd,SENG_GUNNER_TIMER_ID,250,NULL);    //   玩家飞机 发射炮弹
	::SetTimer(CGameCtrl::hwnd,GUNNER_MOVE_TIMER_ID,1,NULL);    //    炮弹移动
	::SetTimer(CGameCtrl::hwnd,CREATR_FOEPLANE_TIMER_ID,1000,NULL);   //  创建敌人飞机
	::SetTimer(CGameCtrl::hwnd,FOEPLANE_MOVE_TIMER_ID,30,NULL);       //  敌人飞机的移动
	::SetTimer(CGameCtrl::hwnd,BLAST_SHOWID_TIMER_ID,150,NULL);     //  切换 图片的  定时器

	}
	void CPlanectrl::GameDraw()//界面重绘 
	{
		HDC hdc=GetDC(CGameCtrl::hwnd);//获得主界面的设备句柄
		HDC temphdc=CreateCompatibleDC(hdc);//创建兼容性DC作为缓冲 结局界面闪烁问题
		HBITMAP tempbitmap=CreateCompatibleBitmap(hdc,380,550);//创建临时位图，用于临时DC的使用
		SelectObject(temphdc,tempbitmap);//将临时位图选择给临时设备句柄
		mapvback.ShowBack(temphdc);//显示背景
		myplane.ShowPlayerPlane(temphdc);//显示我方飞机
		ShowAllGunner(temphdc);//显示所有飞机炮弹
		ShowAllFeoplane(temphdc);//显示所有敌方飞机
		ShowAllBoomFeoPlane(temphdc);//显示所有爆炸的敌方飞机
		
		
		::BitBlt(hdc,0,0,380,550,temphdc,0,0,SRCCOPY);//将临时设备句柄的图像传给窗口DC
		DeleteObject(tempbitmap);//之后三行都是释放资源
		DeleteDC(temphdc);
		ReleaseDC(CGameCtrl:: hwnd,hdc);
	}
	void CPlanectrl::GameRun(WPARAM wparam)//游戏启动
	{
		if( BACK_MOVE_TIMER_ID==wparam)//背景移动消息处理
		{
			mapvback.MoveBack();
			CPlanectrl::GameDraw();
			return ;
		}
		if(SENG_GUNNER_TIMER_ID==wparam)//炮弹发射消息处理
		{
			myplane.SendGunner(this->gunnerlist,CGameCtrl::hinstance);
			
			return ;
		}

			
		if( GUNNER_MOVE_TIMER_ID==wparam)//炮弹移动消息处理
		{
			MoveAllGunner();
			CPlanectrl::GameDraw();
			IS_GunnerdestroyFeoplane();//是否撞到敌人飞机
			DeleteGunner();
			return ;
		}
		 if(CREATR_FOEPLANE_TIMER_ID==wparam)//创建敌人飞机消息处理
		 {
			 CreateFeoplane();
			 CPlanectrl::GameDraw();
			 return ;
		 }
		 if( FOEPLANE_MOVE_TIMER_ID==wparam)//敌人飞机移动消息处理
		{
			MoveAllFeoPlane();
			CPlanectrl::GameDraw();
			IS_FeoplanedestruyMyplane();
			this->DeleteFeoplane();
			return ;
		}

		 if(BLAST_SHOWID_TIMER_ID==wparam)//敌人飞机爆炸消息处理
		 {
			CPlanectrl::MoveAllBoomFeoPlane();//切换所有的敌方死亡飞机图片
			 return ;
		 }
	}
	void CPlanectrl::ShowAllGunner(HDC hdc)//显示所有的炮弹
	{
			list<Cdou *>::iterator ite=gunnerlist.begin();
			while(ite!=gunnerlist.end())
			{
				(*ite)->ShowGunner(hdc);
				ite++;
			}
	}
	void CPlanectrl::ShowAllFeoplane(HDC hdc)//显示所有的敌人飞机
	{
		list<CdiRenPlane *>::iterator ite=FEO_list.begin();
			while(ite!=FEO_list.end())
			{
				(*ite)->ShowFeoPlane(hdc);
				ite++;
			}
	}

	//移动所有炮弹
	void CPlanectrl::MoveAllGunner()
	{
			list<Cdou *>::iterator ite=gunnerlist.begin();
			while(ite!=gunnerlist.end())
			{
				(*ite)->MoveGunner();
				ite++;
			}
		
	}
	//移动所有敌人飞机
	void CPlanectrl::MoveAllFeoPlane()
	{
		list<CdiRenPlane *>::iterator ite=FEO_list.begin();
		while(ite!=FEO_list.end())
			{
				(*ite)->MoveFeoPlane();
				
				ite++;
				//DeleteFeoplane();
			}

	}
	void CPlanectrl::CreateFeoplane()
	{
				//  随机一个敌人飞机
		CdiRenPlane* foe_plane = NULL;
		int index = rand()%12;
		if(index >= 0 && index <= 1)
		{
			//  创建大飞机
			foe_plane = new CMaxPlane;
			
		}
		if(index >= 2 && index <= 5)
		{
			//  创建中飞机
			foe_plane = new CMiddlePlane;
		}
		if(index >= 6 && index <= 11)
		{
			//  创建小飞机
			foe_plane = new CSmallPlane;
		}
		foe_plane->InItFeoPlane(this->hinstance);
		//  放到 链表里
		FEO_list.push_back(foe_plane);
			return ;
	}

	void CPlanectrl::DeleteFeoplane()//删除敌人飞机
	{
		list<CdiRenPlane*>::iterator ite_foe = FEO_list.begin();
		while(ite_foe != FEO_list.end())
		{
			if((*ite_foe)->h > 700)   //  删除
			{
				//  删除炮弹
				delete (*ite_foe);
				//  删除节点
				ite_foe = FEO_list.erase(ite_foe);
			}
			else
			{
				++ite_foe;
			}
		}
	}
	void CPlanectrl::DeleteGunner()
	{
		list<Cdou*>::iterator ite_foe = gunnerlist.begin();
		while(ite_foe != gunnerlist.end())
		{
			if((*ite_foe)->h <0)   //  删除
			{
				//  删除炮弹
				delete (*ite_foe);
				//  删除节点
				ite_foe = gunnerlist.erase(ite_foe);
			}
			else
			{
				++ite_foe;
			}
		}

	}

	//键盘消息处理
	void CPlanectrl::SelectKEY_Message()
	{

	}
	//敌人飞机碰到我方飞机
	bool CPlanectrl::IS_FeoplanedestruyMyplane()
	{
		list<CdiRenPlane *>::iterator ite=FEO_list.begin();
		while(ite!=FEO_list.end())
		{
			if((*ite)->IS_HITPlayerplane(this->myplane))
				{
					::KillTimer(hwnd,BACK_MOVE_TIMER_ID);
					::KillTimer(hwnd,SENG_GUNNER_TIMER_ID);    //   玩家飞机 发射炮弹
					::KillTimer(hwnd,GUNNER_MOVE_TIMER_ID);    //   玩家飞机 发射炮弹
					::KillTimer(hwnd,CREATR_FOEPLANE_TIMER_ID);   //  创建敌人飞机
					::KillTimer(hwnd,FOEPLANE_MOVE_TIMER_ID);       //  敌人飞机的移动
					//PostMessage(hwnd,WM_DESTROY,0,0);
					MessageBox(hwnd,L"game over",L"dead",0);//弹出游戏结束对话框
				}
			ite++;
		}
		
		return false;
	}
	//炮弹打到敌方飞机
	bool CPlanectrl::IS_GunnerdestroyFeoplane()
	{
		bool nflag = false;   //  判断  是否有炮弹击中敌人飞机


		// 遍历炮弹的链表
		list<Cdou *>::iterator ite = gunnerlist.begin();
		while(ite != gunnerlist.end())
		{
			nflag = false;
			//  拿当前的 炮弹 和 所有敌人飞  判断
		
			list<CdiRenPlane*>::iterator ite_foe_plane = FEO_list.begin();
			while(ite_foe_plane != FEO_list.end())
			{
				// 看这个 敌人飞机  是否被  击中
				if(  (*ite_foe_plane)->IS_HITGunner(*ite) )
				{
					//---------------------------------------
					nflag = true;
					//  删除炮弹
					//  先删除炮弹对象
					delete (*ite);
					//  删除炮弹节点
					ite = gunnerlist.erase(ite);
					//---------------------------------------
					//  看能不能爆炸
					if( (*ite_foe_plane)->IS_Bump() )
					{
						//  把这个飞机 放到 爆炸的 飞机的链表上
						this->DeadFeoList.push_back(*ite_foe_plane);
						this->FEO_list.erase(ite_foe_plane);
					}
					break;
				}

				++ite_foe_plane;
			}

			//  拿下一个炮弹
			if(nflag == false)
				++ite;
		}	
		return nflag;
	}
	//按键信息
	void CPlanectrl::m_WM_KEYDOWN(WPARAM wparam)
	{
		flag1=true;//标记键盘按下
		while(flag1)//此处代码块的作用是处理飞机移动灵敏问题，原理：使用多个消息来执行一次正确的执行
		{
			MSG msg;
			::GetMessage(&msg,CGameCtrl::hwnd,0,0);//获得应运程序的消息队列的消息，//注意点：只能取得postmessage函数投递的消息，sendmessage不进入程序的消息队列
			if(msg.message!=WM_KEYDOWN)//如果不是键盘消息则将消息重新分发到各自的消息处理机制中
			{
				// 翻译消息
				::TranslateMessage(&msg);
				// 处理消息
				::DispatchMessage(&msg);//该函数调度一个消息给窗口程序。通常调度从GetMessage取得的消息。
			}
			myplane.MovePlayerPlane(wparam);//依旧使用之前的消息--为了能够使飞机移动速度快
			this->GameDraw();//界面重绘
		}
	}
	void CPlanectrl::m_WM_KEYUP(WPARAM wparam)
	{
		flag1=false;//标记键盘是否按下，false代表键盘没有按下
	}
	void CPlanectrl::MoveAllBoomFeoPlane()
	{
		list<CdiRenPlane *>::iterator ite=DeadFeoList.begin();
		while(ite!=DeadFeoList.end())
		{
			if((*ite)->number!=0)
			{
				(*ite)->number--;
				ite++;
			}else
			{
				delete (*ite);
				ite=DeadFeoList.erase(ite);
			}
			
		}
	}

	void CPlanectrl::ShowAllBoomFeoPlane(HDC hdc)
	{
		list<CdiRenPlane *>::iterator ite=DeadFeoList.begin();
		while(ite!=DeadFeoList.end())
		{
			(*ite)->ShowFeoPlane(hdc);
			ite++;
		}
	}



	//此处的代码是为了给基类当中的静态函数指针赋值，其目的是在WinMain中给基类指针赋值实现多态
	CGameCtrl * _create()
	{
		return new CPlanectrl;
	}
	int _lianjie(CreatePfunction pf)
	{
		CGameCtrl::createobjectpfunction=pf;
		return 0;
	}
	int a=_lianjie(_create);


