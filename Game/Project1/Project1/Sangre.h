#pragma once
#include "Figura.h"

class CSangre: public CFigura
{


public:
	CSangre(void);
	~CSangre(void);
	CSangre(int px,int py,Bitmap^ bmp);
	
};

CSangre::CSangre(void){}
CSangre::~CSangre(void){}
CSangre::CSangre(int px, int py,Bitmap^ bmp):CFigura(px,py,0,0,1,10,bmp){}