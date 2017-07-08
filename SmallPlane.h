#pragma once
#include "cdirenplane.h"
#include"PlayerPlane.h"


class CSmallPlane :
	public CdiRenPlane
{
public:

public:
	CSmallPlane(void);
	~CSmallPlane(void);
	void InItFeoPlane(HINSTANCE hinstance);
	void ShowFeoPlane(HDC hdc);
	void MoveFeoPlane();
	bool IS_HITGunner(Cdou *pgunner);
	bool IS_HITPlayerplane(CPlayerPlane &plane);
	bool IS_Bump();
};

