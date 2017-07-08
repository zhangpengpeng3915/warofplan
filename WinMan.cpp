#include<windows.h>

#include<time.h>

#include"gamectrl.h"




LRESULT CALLBACK MY_WNDPROC(HWND, UINT, WPARAM, LPARAM);//Ӧ�ó�����Ϣ������

HINSTANCE hinstace=NULL;//����ȫ�ֱ�����Ӧ�˳��������������������������������ʹ��

int CALLBACK WinMain(HINSTANCE hinstance,HINSTANCE prvhinsatnce,LPSTR lpCmdLine,int nCmdShow )//���������
{
	srand( time(0));//���������
	hinstace =hinstance;//��ʼ��Ӧ�ó�����
	//��ƴ���
	WNDCLASSEX EX;//������Ϣ�洢�Ľṹ��
	HWND hwnd;
	MSG msg;//���ڴ洢���񵽵���Ϣ
	
	EX.cbSize=sizeof(EX);
	EX.cbClsExtra=0;
	EX.cbWndExtra=0;
	EX.style=0;//CS_HREDRAW|CS_VREDRAW;//shui ping shua xin yu chuizhi shua xin 
	EX.hbrBackground=CreateSolidBrush(RGB(300,158,691));
	EX.hCursor=0;
	EX.hIcon=0;
	EX.hInstance=hinstance;
	EX.hIconSm=0;
	EX.lpszClassName=L"zpp";
	EX.lpszMenuName=NULL;
	EX.lpfnWndProc=MY_WNDPROC;//������Ϣ
	//ע�ᴰ��
	RegisterClassEx(&EX);
	//��������
	hwnd=CreateWindow(L"zpp",L"zppwindows",WS_OVERLAPPEDWINDOW,100,50,396,588,NULL,NULL,hinstance,NULL);
	//��ʾ����
	ShowWindow(hwnd,nCmdShow);


	//��Ϣѭ��
	//1. �����Ϣ
	while(GetMessage(&msg,0,/* ����hwnd �򲶻�������Ļ����Ϣ������ֻ����hwnd������ڵ���Ϣ*/0,0))
	{
		//2. ������Ϣ
		TranslateMessage(&msg);
		//3. �����ַ���Ϣ
		DispatchMessage(&msg);//�ú�������һ����Ϣ�����ڳ���ͨ�����ȴ�GetMessageȡ�õ���Ϣ��
	}

}


CGameCtrl *ctrl=NULL;//��Ϸ�������ĸ���ָ�룬������ڵ���Ϸ��չ����������д��һ���ɻ���ս�ģ����ڿ��Խ���Ӧ����������Ϸ ��̰���ߵĿ����ȵ�

LRESULT CALLBACK MY_WNDPROC(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)//msg ������
{
										
	switch (msg)//����Ӧ�ó�����Ϣ���е���Ϣ���з���
	{
	case WM_CREATE://������Ϸ
		if(CGameCtrl::createobjectpfunction==NULL)//������൱�еľ�̬����ָ��û�б���ʼ��
		{
			MessageBox(NULL,L"��������  failed!",NULL,NULL);
		}
		
		ctrl=CGameCtrl::createobjectpfunction();//���ú���ָ�봴���ɻ���ս����Ϸ������
		ctrl->SET(hwnd,hinstace);//��ʼ�����൱�е�ָ�������򴰿ڵľ���ͳ�����
		ctrl->CreateGame();//������Ϸ��ʼ������������麯��
		break;
	case WM_TIMER://����ʱ����Ϣ
		ctrl->GameRun(wparam);//��ʱ��������Ϸ����
		break;
	case WM_KEYDOWN:	//������̰�����Ϣ
		ctrl->m_WM_KEYDOWN(wparam);
		break;
	case WM_KEYUP://�������̧����Ϣ
		ctrl->m_WM_KEYUP(wparam);
		break;
	case WM_PAINT://��Ϸ����Ĵ���
		ctrl->GameDraw();
		break;
	case WM_LBUTTONDOWN://��괦��
		
		break;
	case WM_CLOSE://���ڹر�
		DestroyWindow(hwnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);//��������
		break;

	}
	return DefWindowProc(hwnd,msg,wparam,lparam);//�ص����� �������ܣ��ú�������ȱʡ�Ĵ��ڹ�����ΪӦ�ó���û�д�����κδ�����Ϣ�ṩȱʡ�Ĵ����ú���ȷ��ÿһ����Ϣ�õ���������DefWindowProc����ʱʹ�ô��ڹ��̽��յ���ͬ������
}



