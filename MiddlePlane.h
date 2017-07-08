#pragma once
#include "cdirenplane.h"
#include"Cdou.h"
#include"PlayerPlane.h"


class CMiddlePlane :
	public CdiRenPlane
{

public:
	CMiddlePlane(void);
	~CMiddlePlane(void);
	void InItFeoPlane(HINSTANCE hinstance);
	void ShowFeoPlane(HDC hdc);
	void MoveFeoPlane();
	bool IS_HITGunner(Cdou *pgunner);
	bool IS_HITPlayerplane(CPlayerPlane &plane);
	bool IS_Bump();
};

