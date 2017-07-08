#pragma once
#include"m.h"
class CBack
{
public:
	CBack(void);
	~CBack(void);
public:
	HBITMAP mapA;
	HBITMAP mapB;
	int h;
	int l;
	void ShowBack(HDC hdc);//œ‘ æ±≥æ∞Õº∆¨
	void MoveBack();//±≥æ∞Õº∆¨“∆∂Ø
	void InItBack(HINSTANCE hinstance);//≥ı ºªØ±≥æ∞
};

