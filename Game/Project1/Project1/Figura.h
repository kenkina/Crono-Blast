#pragma once
#include <string.h>

using namespace System::Drawing;


public enum Tecla{arriba,abajo,derecha,izquierda,ninguno,disparo,retroceso,recuperarvida,LOL};


class CFigura
{
protected:
	int x,y,dx,dy,c,f,w,h,Numerof,Numeroc;
	int demora, cuentaDemora;
	int VidaE;
	int VidaOriginal;

public:
	CFigura(void);

	~CFigura(void);

	CFigura(int px, int py, int pdx, int pdy,int pNumerof, int pNumeroc, Bitmap^ bmp);

	int Get_x();
	void Set_x(int nuevo);
	int Get_y();
	void Set_y(int nuevo);
	int Get_W();
	int Get_H();
	int Get_f();
	void Set_f(int nuevo);
	void Set_c(int nuevo);
	int Get_dx();
	void Set_dx(int nuevo);
	int Get_dy();
	void Set_dy(int nuevo);
	int Get_c();

	void Dibujar(Graphics ^gr, Bitmap ^bmp);

	int Get_VidaE();
	void Set_VidaE(int nuevo);

	int Get_VidaOriginal();
	void Set_VidaOriginal(int nuevo);

};


CFigura::CFigura(void){}


CFigura::CFigura(int px, int py, int pdx, int pdy, int pNumerof, int pNumeroc, Bitmap^ bmp)
{
	x = px;  y = py;  dx = pdx; dy = pdy;
	f = 0;
	c = 0;
	Numeroc=pNumeroc;
	Numerof=pNumerof;

	if(bmp==nullptr)
	{
		w=10;
		h=10;			
	}
	else
	{
		w = bmp->Width / Numeroc;
		h = bmp->Height / Numerof;
	}
	cuentaDemora=0;

	VidaE=0;
	
}

CFigura::~CFigura(void){}

int CFigura::Get_x(){return x;}
void CFigura::Set_x(int nuevo){x = nuevo;}
int CFigura::Get_y(){return y;}
void CFigura::Set_y(int nuevo){y = nuevo;}
int CFigura::Get_W(){return w;}
int CFigura::Get_H(){return h;}
int CFigura::Get_f(){return f;}
void CFigura::Set_f(int nuevo){f = nuevo;}
void CFigura::Set_c(int nuevo){c = nuevo;}
int CFigura::Get_dx(){return dx;}
void CFigura::Set_dx(int nuevo){dx=nuevo;}
int CFigura::Get_dy(){return dx;}
void CFigura::Set_dy(int nuevo){dx=nuevo;}
int CFigura::Get_c(){return c;}



void CFigura::Dibujar(Graphics ^gr, Bitmap ^bmp)
{
	Rectangle porcion = Rectangle(w*c,h*f,w,h);
	gr->DrawImage(bmp,x,y,porcion,GraphicsUnit::Pixel);	
}

int CFigura::Get_VidaE(){return VidaE;}
void CFigura::Set_VidaE(int nuevo){VidaE=nuevo;}

int CFigura::Get_VidaOriginal(){return VidaOriginal;}
void CFigura::Set_VidaOriginal(int nuevo){VidaOriginal=nuevo;}