#include "GameCtrl.h"

CreatePfunction CGameCtrl:: createobjectpfunction=NULL;

void CGameCtrl:: SET(HWND hwnd,HINSTANCE hinstance)
{
	 CGameCtrl::hwnd=hwnd;
	 CGameCtrl::hinstance=hinstance;
}
CGameCtrl::CGameCtrl(void)
{

}
	

CGameCtrl::~CGameCtrl(void)
{
}
 