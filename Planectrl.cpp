#include "Planectrl.h"

	CPlanectrl::CPlanectrl(void)
	{
		
	}
	CPlanectrl::~CPlanectrl(void)
	{

	}
	void CPlanectrl::CreateGame()//������Ϸ
	{
		mapvback.InItBack(CGameCtrl::hinstance);//��ʼ������
		myplane.InItplayerPlane(CGameCtrl::hinstance);//��ʼ����ҷɻ�
		//  ������ʱ��
	::SetTimer(CGameCtrl::hwnd,BACK_MOVE_TIMER_ID,1,NULL);// �������ƶ�   ���ִ���ʱ��������Ϣ��ʱ����
	::SetTimer(CGameCtrl::hwnd,SENG_GUNNER_TIMER_ID,250,NULL);    //   ��ҷɻ� �����ڵ�
	::SetTimer(CGameCtrl::hwnd,GUNNER_MOVE_TIMER_ID,1,NULL);    //    �ڵ��ƶ�
	::SetTimer(CGameCtrl::hwnd,CREATR_FOEPLANE_TIMER_ID,1000,NULL);   //  �������˷ɻ�
	::SetTimer(CGameCtrl::hwnd,FOEPLANE_MOVE_TIMER_ID,30,NULL);       //  ���˷ɻ����ƶ�
	::SetTimer(CGameCtrl::hwnd,BLAST_SHOWID_TIMER_ID,150,NULL);     //  �л� ͼƬ��  ��ʱ��

	}
	void CPlanectrl::GameDraw()//�����ػ� 
	{
		HDC hdc=GetDC(CGameCtrl::hwnd);//�����������豸���
		HDC temphdc=CreateCompatibleDC(hdc);//����������DC��Ϊ���� ��ֽ�����˸����
		HBITMAP tempbitmap=CreateCompatibleBitmap(hdc,380,550);//������ʱλͼ��������ʱDC��ʹ��
		SelectObject(temphdc,tempbitmap);//����ʱλͼѡ�����ʱ�豸���
		mapvback.ShowBack(temphdc);//��ʾ����
		myplane.ShowPlayerPlane(temphdc);//��ʾ�ҷ��ɻ�
		ShowAllGunner(temphdc);//��ʾ���зɻ��ڵ�
		ShowAllFeoplane(temphdc);//��ʾ���ез��ɻ�
		ShowAllBoomFeoPlane(temphdc);//��ʾ���б�ը�ĵз��ɻ�
		
		
		::BitBlt(hdc,0,0,380,550,temphdc,0,0,SRCCOPY);//����ʱ�豸�����ͼ�񴫸�����DC
		DeleteObject(tempbitmap);//֮�����ж����ͷ���Դ
		DeleteDC(temphdc);
		ReleaseDC(CGameCtrl:: hwnd,hdc);
	}
	void CPlanectrl::GameRun(WPARAM wparam)//��Ϸ����
	{
		if( BACK_MOVE_TIMER_ID==wparam)//�����ƶ���Ϣ����
		{
			mapvback.MoveBack();
			CPlanectrl::GameDraw();
			return ;
		}
		if(SENG_GUNNER_TIMER_ID==wparam)//�ڵ�������Ϣ����
		{
			myplane.SendGunner(this->gunnerlist,CGameCtrl::hinstance);
			
			return ;
		}

			
		if( GUNNER_MOVE_TIMER_ID==wparam)//�ڵ��ƶ���Ϣ����
		{
			MoveAllGunner();
			CPlanectrl::GameDraw();
			IS_GunnerdestroyFeoplane();//�Ƿ�ײ�����˷ɻ�
			DeleteGunner();
			return ;
		}
		 if(CREATR_FOEPLANE_TIMER_ID==wparam)//�������˷ɻ���Ϣ����
		 {
			 CreateFeoplane();
			 CPlanectrl::GameDraw();
			 return ;
		 }
		 if( FOEPLANE_MOVE_TIMER_ID==wparam)//���˷ɻ��ƶ���Ϣ����
		{
			MoveAllFeoPlane();
			CPlanectrl::GameDraw();
			IS_FeoplanedestruyMyplane();
			this->DeleteFeoplane();
			return ;
		}

		 if(BLAST_SHOWID_TIMER_ID==wparam)//���˷ɻ���ը��Ϣ����
		 {
			CPlanectrl::MoveAllBoomFeoPlane();//�л����еĵз������ɻ�ͼƬ
			 return ;
		 }
	}
	void CPlanectrl::ShowAllGunner(HDC hdc)//��ʾ���е��ڵ�
	{
			list<Cdou *>::iterator ite=gunnerlist.begin();
			while(ite!=gunnerlist.end())
			{
				(*ite)->ShowGunner(hdc);
				ite++;
			}
	}
	void CPlanectrl::ShowAllFeoplane(HDC hdc)//��ʾ���еĵ��˷ɻ�
	{
		list<CdiRenPlane *>::iterator ite=FEO_list.begin();
			while(ite!=FEO_list.end())
			{
				(*ite)->ShowFeoPlane(hdc);
				ite++;
			}
	}

	//�ƶ������ڵ�
	void CPlanectrl::MoveAllGunner()
	{
			list<Cdou *>::iterator ite=gunnerlist.begin();
			while(ite!=gunnerlist.end())
			{
				(*ite)->MoveGunner();
				ite++;
			}
		
	}
	//�ƶ����е��˷ɻ�
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
				//  ���һ�����˷ɻ�
		CdiRenPlane* foe_plane = NULL;
		int index = rand()%12;
		if(index >= 0 && index <= 1)
		{
			//  ������ɻ�
			foe_plane = new CMaxPlane;
			
		}
		if(index >= 2 && index <= 5)
		{
			//  �����зɻ�
			foe_plane = new CMiddlePlane;
		}
		if(index >= 6 && index <= 11)
		{
			//  ����С�ɻ�
			foe_plane = new CSmallPlane;
		}
		foe_plane->InItFeoPlane(this->hinstance);
		//  �ŵ� ������
		FEO_list.push_back(foe_plane);
			return ;
	}

	void CPlanectrl::DeleteFeoplane()//ɾ�����˷ɻ�
	{
		list<CdiRenPlane*>::iterator ite_foe = FEO_list.begin();
		while(ite_foe != FEO_list.end())
		{
			if((*ite_foe)->h > 700)   //  ɾ��
			{
				//  ɾ���ڵ�
				delete (*ite_foe);
				//  ɾ���ڵ�
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
			if((*ite_foe)->h <0)   //  ɾ��
			{
				//  ɾ���ڵ�
				delete (*ite_foe);
				//  ɾ���ڵ�
				ite_foe = gunnerlist.erase(ite_foe);
			}
			else
			{
				++ite_foe;
			}
		}

	}

	//������Ϣ����
	void CPlanectrl::SelectKEY_Message()
	{

	}
	//���˷ɻ������ҷ��ɻ�
	bool CPlanectrl::IS_FeoplanedestruyMyplane()
	{
		list<CdiRenPlane *>::iterator ite=FEO_list.begin();
		while(ite!=FEO_list.end())
		{
			if((*ite)->IS_HITPlayerplane(this->myplane))
				{
					::KillTimer(hwnd,BACK_MOVE_TIMER_ID);
					::KillTimer(hwnd,SENG_GUNNER_TIMER_ID);    //   ��ҷɻ� �����ڵ�
					::KillTimer(hwnd,GUNNER_MOVE_TIMER_ID);    //   ��ҷɻ� �����ڵ�
					::KillTimer(hwnd,CREATR_FOEPLANE_TIMER_ID);   //  �������˷ɻ�
					::KillTimer(hwnd,FOEPLANE_MOVE_TIMER_ID);       //  ���˷ɻ����ƶ�
					//PostMessage(hwnd,WM_DESTROY,0,0);
					MessageBox(hwnd,L"game over",L"dead",0);//������Ϸ�����Ի���
				}
			ite++;
		}
		
		return false;
	}
	//�ڵ��򵽵з��ɻ�
	bool CPlanectrl::IS_GunnerdestroyFeoplane()
	{
		bool nflag = false;   //  �ж�  �Ƿ����ڵ����е��˷ɻ�


		// �����ڵ�������
		list<Cdou *>::iterator ite = gunnerlist.begin();
		while(ite != gunnerlist.end())
		{
			nflag = false;
			//  �õ�ǰ�� �ڵ� �� ���е��˷�  �ж�
		
			list<CdiRenPlane*>::iterator ite_foe_plane = FEO_list.begin();
			while(ite_foe_plane != FEO_list.end())
			{
				// ����� ���˷ɻ�  �Ƿ�  ����
				if(  (*ite_foe_plane)->IS_HITGunner(*ite) )
				{
					//---------------------------------------
					nflag = true;
					//  ɾ���ڵ�
					//  ��ɾ���ڵ�����
					delete (*ite);
					//  ɾ���ڵ��ڵ�
					ite = gunnerlist.erase(ite);
					//---------------------------------------
					//  ���ܲ��ܱ�ը
					if( (*ite_foe_plane)->IS_Bump() )
					{
						//  ������ɻ� �ŵ� ��ը�� �ɻ���������
						this->DeadFeoList.push_back(*ite_foe_plane);
						this->FEO_list.erase(ite_foe_plane);
					}
					break;
				}

				++ite_foe_plane;
			}

			//  ����һ���ڵ�
			if(nflag == false)
				++ite;
		}	
		return nflag;
	}
	//������Ϣ
	void CPlanectrl::m_WM_KEYDOWN(WPARAM wparam)
	{
		flag1=true;//��Ǽ��̰���
		while(flag1)//�˴������������Ǵ���ɻ��ƶ��������⣬ԭ��ʹ�ö����Ϣ��ִ��һ����ȷ��ִ��
		{
			MSG msg;
			::GetMessage(&msg,CGameCtrl::hwnd,0,0);//���Ӧ�˳������Ϣ���е���Ϣ��//ע��㣺ֻ��ȡ��postmessage����Ͷ�ݵ���Ϣ��sendmessage������������Ϣ����
			if(msg.message!=WM_KEYDOWN)//������Ǽ�����Ϣ����Ϣ���·ַ������Ե���Ϣ���������
			{
				// ������Ϣ
				::TranslateMessage(&msg);
				// ������Ϣ
				::DispatchMessage(&msg);//�ú�������һ����Ϣ�����ڳ���ͨ�����ȴ�GetMessageȡ�õ���Ϣ��
			}
			myplane.MovePlayerPlane(wparam);//����ʹ��֮ǰ����Ϣ--Ϊ���ܹ�ʹ�ɻ��ƶ��ٶȿ�
			this->GameDraw();//�����ػ�
		}
	}
	void CPlanectrl::m_WM_KEYUP(WPARAM wparam)
	{
		flag1=false;//��Ǽ����Ƿ��£�false�������û�а���
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



	//�˴��Ĵ�����Ϊ�˸����൱�еľ�̬����ָ�븳ֵ����Ŀ������WinMain�и�����ָ�븳ֵʵ�ֶ�̬
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


