#pragma once
#include "Figura.h"


class CPersonaje :public CFigura
{
	Tecla direccion;

public:
	CPersonaje(void);
	CPersonaje(int px, int py, Bitmap^ pbmp);
	~CPersonaje(void);
	void Mover(Graphics ^gr, Bitmap ^bmp,Tecla teclapulsada);	
};

CPersonaje::CPersonaje(void){}
CPersonaje::~CPersonaje(void){}

CPersonaje::CPersonaje(int px, int py, Bitmap^ pbmp):CFigura(px,py,0,0,4,9,pbmp)
{
	f=1; c=0;
	VidaE=300;
	demora=0;
	VidaOriginal=VidaE;
}


void CPersonaje::Mover(Graphics ^gr, Bitmap ^bmp,Tecla teclapulsada){

	dx=dy=0;

	direccion=teclapulsada;

	if(teclapulsada==Tecla::abajo)	
	{	
		f=1;
		dy=30;
	}
	if(teclapulsada==Tecla::arriba)
	{	
		f=0;
		dy=-30;
	}
	if(teclapulsada==Tecla::izquierda)
	{	
		f=3;
		dx=-30;
	}
	if(teclapulsada==Tecla::derecha)
	{	
		f=2;
		dx=30;
	}

		
	if(demora==1)
	{
		c++;
		demora=0;
	}

	demora++;
	if(c>8) c=1;
	

	if(teclapulsada==Tecla::ninguno||teclapulsada==Tecla::disparo||teclapulsada==Tecla::recuperarvida)
	{
		dx=dy=0;
		c=0;
	}

	if (x+dx<50 || x+dx+w>750)	//510
	{
		dx=0;
		teclapulsada=Tecla::ninguno;
	}

	if (y+dy<20 || y+dy+h>450)	//285
	{
		dy=0;
		teclapulsada=Tecla::ninguno;
	}
	
	x+=dx;
	y+=dy;

	Dibujar(gr,bmp);
	
}



