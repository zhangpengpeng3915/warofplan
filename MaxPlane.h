#pragma once
#include"CdiRenPlane.h"
#include"m.h"
#include"PlayerPlane.h"


class CMaxPlane :
	public CdiRenPlane
{
public:

public:
	CMaxPlane(void);
	~CMaxPlane(void);
	void InItFeoPlane(HINSTANCE hinstance);
	void ShowFeoPlane(HDC hdc);
	void MoveFeoPlane();
	bool IS_HITGunner(Cdou * pgunner);
	bool IS_HITPlayerplane(CPlayerPlane &plane);
	bool IS_Bump();
};

