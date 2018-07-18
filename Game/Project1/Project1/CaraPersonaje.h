#pragma once
#include "Figura.h"

class CCaraPersonaje: public CFigura
{


public:
	CCaraPersonaje(void);
	~CCaraPersonaje(void);
	CCaraPersonaje(int px,int py,Bitmap^ bmp);
	
};

CCaraPersonaje::CCaraPersonaje(void){}
CCaraPersonaje::~CCaraPersonaje(void){}
CCaraPersonaje::CCaraPersonaje(int px, int py,Bitmap^ bmp):CFigura(px,py,0,0,1,2,bmp){}