#pragma once
#include "Figura.h"

class CEnemigo :
	public CFigura
{
private:

	int tipo;
	int ID;		 

public:
	CEnemigo(int px, int py,int pNumerof,int pNumeroc,Bitmap^ pbmp,int ptipo,int PID,int pNivel);
	CEnemigo(void);
	~CEnemigo(void);
	void Mover(Graphics ^gr, Bitmap ^pbmp,int Xp,int Yp);

	int GetTipo();
	int GetID();

};

CEnemigo::CEnemigo(void){}

CEnemigo::CEnemigo(int px, int py,int pNumerof,int pNumeroc,Bitmap^ pbmp,int ptipo,int PID,int pNivel):CFigura(px,py,0,0,pNumerof,pNumeroc,pbmp)
{
	tipo=ptipo;
	ID=PID;

	if(tipo==1)
	{
		dx=2;
		dy=2;
		VidaE=3*pNivel;
		demora=2;
	}
	else if(tipo==2)
	{
		dx=3;
		dy=3;
		VidaE=4*pNivel;
		demora=5;
	}
	else if(tipo==3)
	{
		dx=5;
		dy=5;
		VidaE=1*pNivel;
		demora=3;
	}

	VidaOriginal=VidaE;
}

CEnemigo::~CEnemigo(void){}
	

void CEnemigo::Mover(Graphics ^gr, Bitmap ^pbmp,int Xp,int Yp)
{
	int pdx=0, pdy=0;

	if(x+w/2<=Xp&&y+h/2<=Yp)
	{
		pdx=dx; pdy=dy;
		
		if(tipo==1) f=0;
		else if(tipo==2) f=0;
		else if(tipo==3) f=0;
	}
	
	else if(x+w/2<=Xp&&y+h/2>=Yp)
	{
		pdx=dx; pdy=-dy;

		if(tipo==1) f=0;
		else if(tipo==2) f=1;
		else if(tipo==3) f=1;
	}
	
	else if(x+w/2>=Xp&&y+h/2<=Yp)
	{
		pdx=-dx; pdy=dy;
		
		if(tipo==1) f=1;
		else if(tipo==2) f=2;
		else if(tipo==3) f=2;
	}
	
	else if(x+w/2>=Xp&&y+h/2>=Yp)
	{
		pdx=-dx; pdy=-dy;
		
		if(tipo==1) f=1;
		else if(tipo==2) f=3;
		else if(tipo==3) f=3;
	}

	/*else 
	{
		pdx=0;
		pdy=0;
		
		f=0;	
	}*/
	
	x+=pdx;
	y+=pdy;

	
	if(cuentaDemora==demora)
	{
		c++;
		cuentaDemora=0;
	}	
	cuentaDemora++;
	
	if(c > Numeroc-1)		c = 0;
		

	Dibujar(gr,pbmp);

	gr->DrawRectangle(Pens::Black,x-1,y+h-1,w+1,5+1);
	gr->FillRectangle(Brushes::Green,x,y+h,(w*VidaE)/VidaOriginal,5);
	//Font^f = gcnew Font("Arial Black",8);
	//gr->DrawString(ID.ToString(),f,Brushes::Black,x,y);	

}
		
	


int CEnemigo::GetTipo(){return tipo;}
int CEnemigo::GetID(){return ID;}