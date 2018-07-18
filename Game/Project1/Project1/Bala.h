#pragma once

using namespace System::Drawing;

class CBala
{
private:
	int x, y;
	int dx, dy;
	bool eliminar;

public:
	CBala(void);
	~CBala(void);
	CBala(int px, int py, int pdx, int pdy);

	void Dibujar(Graphics ^gr);
	void Mover(Graphics ^gr);
	bool Get_eliminar();
	void Set_eliminar(bool nuevo);

	int Get_x();
	int Get_y();
	int Get_W();
	int Get_H();

	void Set_x(int nuevo);
	void Set_y(int nuevo);

	int Get_dx();
	int Get_dy();

	void Set_dx(int nuevo);
	void Set_dy(int nuevo);

};


CBala::CBala(void){}
CBala::~CBala(void){}
CBala::CBala(int px, int py, int pdx, int pdy){

	x=px;
	y=py;
	dx=pdx;
	dy=pdy;
	eliminar=false;
}

void CBala:: Dibujar(Graphics ^gr){

	gr->FillEllipse(gcnew SolidBrush(Color::Yellow),x,y,5,5);
}


void CBala::Mover(Graphics ^gr){

	x+=dx;
	y+=dy;

	if(x<50 || x>750)	eliminar=true;
	if(y<20 || y>450)	eliminar=true;

	Dibujar(gr);
}


bool CBala::Get_eliminar(){ return eliminar; }

void CBala::Set_eliminar(bool nuevo){ eliminar=nuevo; }

int CBala::Get_x(){ return x; }
int CBala::Get_y(){ return y; }
int CBala::Get_W(){ return 5; }
int CBala::Get_H(){ return 5; }

void CBala::Set_x(int nuevo){ x=nuevo; }
void CBala::Set_y(int nuevo){ y=nuevo; }

int	CBala::Get_dx(){ return dx; }
int	CBala::Get_dy(){ return dy; }


void CBala::Set_dx(int nuevo){ dx=nuevo; }
void CBala::Set_dy(int nuevo){ dy=nuevo; }