#pragma once
#include "Figura.h"
class CFondo :
	public CFigura

{

private:
		bool tope;
public:
	CFondo(void);
	~CFondo(void);
	CFondo(Bitmap^ pbmp);
	bool Get_tope();
	
	void Mover(Tecla direccion);
};


CFondo::CFondo(void){}

CFondo::CFondo(Bitmap^ pbmp):CFigura(0,0,0,0,1,1,pbmp){

	tope=false;

}

CFondo::~CFondo(void){}


void CFondo::Mover(Tecla direccion){}

bool CFondo::Get_tope(){return tope;}