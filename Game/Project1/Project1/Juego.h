#pragma once
#include "Personaje.h"
#include "Fondo.h"
#include "Enemigo.h"
#include "CaraPersonaje.h"
#include "Sangre.h"
#include "Bala.h"
#include <stack>
#include <iostream>
#include <vector>

using namespace std;

// Archivos
struct Enemigo
{
	int x;
	int y;
	int tipo;
	int id;
	int vida;
};


struct Bala
{
	int x;
	int y;
	int dx;
	int dy;

};

struct path
{
	int nivel;
	int Personaje_x;
	int Personaje_y;
	int Personaje_vida;
	int Puntaje;
	int cant_enemigos;
	int cant_balas;
	int energia;

	Enemigo enemigos[100];
	Bala balas[50];	

	/*vector<Enemigo> enemigos;
	vector<Balas> balas;*/

};


// Pila

struct place
{
	int first;			// x
	int second;			// y
	int third;			// ID
	int fourth;			// tipo
	int fifth;			// Vida
};



class CJuego
{
	CPersonaje* objPersonaje;
	CFondo* objFondo;
	CCaraPersonaje* objCaraPersonaje;
	
	vector<CEnemigo*> ArrEnemigos;
	vector<CBala*> ArrBalas;
	vector<CSangre*> ArrSangre;

	vector<place> Arrplace;
	stack<vector<place>> pila;

	vector<Bala> BalasPila;	
	stack<vector<Bala>> pilabala;

	int cont_aparicion_enemigos;
	int cont_aparicion_Balas;	
	int cont_guarda_pos;
	int cont_IDs;

	int Nivel;
	int puntaje;
	int energia;
	int energiaMax;

	int It_enem;
	int It_Balas;
	int It_pila;
	int It_sangre;
	int It_pilabala;

	
public:
	CJuego(void);
	~CJuego(void);

	CJuego(Bitmap^ bmpPersonaje,Bitmap^ bmpFondo,Bitmap^ bmpCara,int pNivel,int ppuntaje);

	void MostrarTodo(Graphics ^gr,Tecla teclapulsada,Bitmap^ bmpPersonaje,Bitmap^ bmpFondo,
		Bitmap^ bmpEnemigo1,Bitmap^ bmpEnemigo2,Bitmap^ bmpEnemigo3,Bitmap^ bmpCara,Bitmap^ bmpSangre);

	void Disparar(int fp);
	void AgregarEnemigo(int nivel,Bitmap^ bmpEnemigo1,Bitmap^ bmpEnemigo2,Bitmap^ bmpEnemigo3);
	void AdministrarBalas(Graphics^ gr);
	void AdministrarEnemigos(Graphics^ gr,Bitmap^ bmpEnemigo1,Bitmap^ bmpEnemigo2,Bitmap^ bmpEnemigo3);
	void AdministrarSangre(Graphics^ gr,Bitmap^ bmpSangre);
	void EvaluarColisionBalaEnemigo(Graphics^ gr,Bitmap^ bmpSangre);
	void EvaluarColisionPersonajeEnemigo(Graphics^ gr);
	void Guardar_Partida();
	bool Cargar_Partida(Bitmap^ bmpEnemigo1,Bitmap^ bmpEnemigo2,Bitmap^ bmpEnemigo3);
	bool NivelSiguiente();
	bool GamerOver();
	int Get_Puntaje();

private:

	bool ColisionBalaEnemigo(CBala* obj1,CFigura* obj2,Graphics^ gr);
	bool ColisionFiguras(CFigura* obj1,CFigura* obj2,Graphics^ gr);
	void Guardar_pila();
	void Retroceder_tiempo(Bitmap^ bmpEnemigo1,Bitmap^ bmpEnemigo2,Bitmap^ bmpEnemigo3);

	void MostrarDatos(Graphics^ gr);
	void Mostrar_Memoria(Graphics^ gr);
	
};

CJuego::CJuego(void){}
CJuego::~CJuego(void){}

CJuego::CJuego(Bitmap^ bmpPersonaje,Bitmap^ bmpFondo,Bitmap^ bmpCara,int pNivel,int ppuntaje)
{
	objPersonaje = new CPersonaje(200, 200, bmpPersonaje);
	objFondo = new CFondo(bmpFondo);
	objCaraPersonaje = new CCaraPersonaje(0,0,bmpCara);
	
	//ArrEnemigos = vector<CEnemigos*>();
	cont_aparicion_enemigos = 0;
	cont_aparicion_Balas = 2;

	//ArrBalas = vector<CBala*>();

	cont_guarda_pos=0;
	cont_IDs=0;

	Nivel=pNivel;

	puntaje=ppuntaje;
	energia=300;
	It_enem=0;
	It_Balas=0;
	It_pila=0;
	It_sangre=0;
	It_pilabala=0;
}


void CJuego::MostrarTodo(Graphics^ gr, Tecla teclapulsada, Bitmap^ bmpPersonaje, Bitmap^ bmpFondo, Bitmap^ bmpEnemigo1, Bitmap^ bmpEnemigo2, Bitmap^ bmpEnemigo3,Bitmap^ bmpCara,Bitmap^ bmpSangre)
{
	objCaraPersonaje->Set_c(0);
	energiaMax=Nivel*2000;

	if(teclapulsada!=Tecla::retroceso)
	{
		AgregarEnemigo(Nivel,bmpEnemigo1,bmpEnemigo2,bmpEnemigo3);
	}
	
	if(teclapulsada==Tecla::retroceso)
		objCaraPersonaje->Set_c(1);

	

	if(teclapulsada==Tecla::recuperarvida)
	{
		if(objPersonaje->Get_VidaE()<objPersonaje->Get_VidaOriginal())
		{
			objPersonaje->Set_VidaE(objPersonaje->Get_VidaE()+8);
			energia-=8;	
		}
	}
	
	objFondo->Dibujar(gr, bmpFondo);
	objPersonaje->Mover(gr, bmpPersonaje, teclapulsada);

	objCaraPersonaje->Dibujar(gr,bmpCara);

	EvaluarColisionBalaEnemigo(gr,bmpSangre);
	EvaluarColisionPersonajeEnemigo(gr);

	AdministrarBalas(gr);

	AdministrarEnemigos(gr,bmpEnemigo1,bmpEnemigo2,bmpEnemigo3);

	AdministrarSangre(gr,bmpSangre);

	
	if (teclapulsada != Tecla::retroceso)
	{
		if(cont_guarda_pos>=2)
		{
			cont_guarda_pos=0;
			Guardar_pila();
		}
		cont_guarda_pos++;
	}

	if(energia!=0)
	{
		if (teclapulsada == Tecla::retroceso)
		{
			Retroceder_tiempo(bmpEnemigo1,bmpEnemigo2,bmpEnemigo3);
			energia-=5;			
		}
		
		if (teclapulsada == Tecla::disparo)
		{
			Disparar(objPersonaje->Get_f());
			energia--;
		}

		// CambioVidaPorEnergía

	}
	 	

	if(teclapulsada==Tecla::LOL)
	{
		/*if(Nivel<5)
			Nivel++;*/

		if(energia<energiaMax)
			energia+=100;		
	}

	if(energia>energiaMax)
			energia=energiaMax;


	if(objPersonaje->Get_VidaE()>objPersonaje->Get_VidaOriginal())
	{
		objPersonaje->Set_VidaE(objPersonaje->Get_VidaOriginal());
	}

	if(0>energia)
			energia=0;

	MostrarDatos(gr);
	Mostrar_Memoria(gr);

	

}


// Públicos


bool CJuego::NivelSiguiente()
{
	if(energia==energiaMax)
	{
		while (pila.size()!=0)
		{
			pila.pop();
		}
		return true;
	}
	return false;
}



bool CJuego::GamerOver()
{
	if(objPersonaje->Get_VidaE()<=0)
		return true;
	return false;
}



void CJuego::AgregarEnemigo(int nivel,Bitmap^ bmpEnemigo1, Bitmap^ bmpEnemigo2, Bitmap^ bmpEnemigo3)
{
	if (cont_aparicion_enemigos == 20)
	{
		int xe=rand()%500;
		int ye=rand()%300;
		int r=xe+ye;

		switch (nivel)
		{
		case 1:
			ArrEnemigos.push_back(new CEnemigo(xe,ye,4,3,bmpEnemigo3,3,cont_IDs,nivel));
			break;

		case 2:
			if(r%2==0||r%3==0||r%5==0)
				ArrEnemigos.push_back(new CEnemigo(xe,ye,2,4,bmpEnemigo1,1,cont_IDs,nivel));
			else
				ArrEnemigos.push_back(new CEnemigo(xe,ye,4,3,bmpEnemigo3,3,cont_IDs,nivel));
			break;

		case 3:
			if(r%2==0||r%3==0)
				ArrEnemigos.push_back(new CEnemigo(xe,ye,2,4,bmpEnemigo1,1,cont_IDs,nivel));
			else if (r%5==0)
				ArrEnemigos.push_back(new CEnemigo(xe,ye,4,3,bmpEnemigo2,2,cont_IDs,nivel));
			else
				ArrEnemigos.push_back(new CEnemigo(xe,ye,4,3,bmpEnemigo3,3,cont_IDs,nivel));
			break;

		case 4:
			if(r%5==0)
				ArrEnemigos.push_back(new CEnemigo(xe,ye,2,4,bmpEnemigo1,1,cont_IDs,nivel));
			else if (r%2==0)
				ArrEnemigos.push_back(new CEnemigo(xe,ye,4,3,bmpEnemigo2,2,cont_IDs,nivel));
			else
				ArrEnemigos.push_back(new CEnemigo(xe,ye,4,3,bmpEnemigo3,3,cont_IDs,nivel));
			break;

		case 5:
			if(r%3==0&&r%5==0)
				ArrEnemigos.push_back(new CEnemigo(xe,ye,2,4,bmpEnemigo1,1,cont_IDs,nivel));
			else if(r%2==0)
				ArrEnemigos.push_back(new CEnemigo(xe,ye,4,3,bmpEnemigo2,2,cont_IDs,nivel));
			else
				ArrEnemigos.push_back(new CEnemigo(xe,ye,4,3,bmpEnemigo3,3,cont_IDs,nivel));
			break;
	
		}
		cont_IDs++;
		cont_aparicion_enemigos = 0;		
	}
	
	cont_aparicion_enemigos++;
}


void CJuego::Disparar(int fp)
{
	if (cont_aparicion_Balas == 2)
	{
		int dx = 0, dy = 0;
		if (fp == 0) dy = -30;
		else if (fp == 1) dy = 30;
		else if (fp == 2) dx = 30;
		else if (fp == 3) dx = -30;
		ArrBalas.push_back(new CBala(objPersonaje->Get_x()+objPersonaje->Get_W()/2,objPersonaje->Get_y()+objPersonaje->Get_H()/2,dx,dy));

		cont_aparicion_Balas = 0;
	}
	cont_aparicion_Balas++;
}


void CJuego::AdministrarBalas(Graphics^ gr)
{	
	if (ArrBalas.size() != 0)
	{
		for (int i = 0; i<ArrBalas.size(); i++)
			if (ArrBalas[i]->Get_eliminar() == true)
				ArrBalas.erase(ArrBalas.begin() + i);

		for (int i = 0; i<ArrBalas.size(); i++){
			ArrBalas[i]->Mover(gr);		
		
		It_Balas++;
		}
	}
}


void CJuego::AdministrarEnemigos(Graphics^ gr,Bitmap^ bmpEnemigo1,Bitmap^ bmpEnemigo2,Bitmap^ bmpEnemigo3)
{
	if (ArrEnemigos.size() != 0)
	{
		for (int i = 0; i<ArrEnemigos.size(); i++)
			if (ArrEnemigos[i]->Get_VidaE() <= 0)
			{
				energia+=(10*ArrEnemigos[i]->GetTipo());
				puntaje+=(10*ArrEnemigos[i]->GetTipo()*Nivel);								
				ArrEnemigos.erase(ArrEnemigos.begin() + i);	
				It_enem++;
			}

		for (int i = 0; i<ArrEnemigos.size(); i++)
		{
			if(ArrEnemigos[i]->GetTipo()==1)
				ArrEnemigos[i]->Mover(gr, bmpEnemigo1, objPersonaje->Get_x()+(objPersonaje->Get_W())/2, objPersonaje->Get_y()+(objPersonaje->Get_H())/2);
			else if(ArrEnemigos[i]->GetTipo()==2)
				ArrEnemigos[i]->Mover(gr, bmpEnemigo2, objPersonaje->Get_x()+(objPersonaje->Get_W())/2, objPersonaje->Get_y()+(objPersonaje->Get_H())/2);
			else if(ArrEnemigos[i]->GetTipo()==3)
				ArrEnemigos[i]->Mover(gr, bmpEnemigo3, objPersonaje->Get_x()+(objPersonaje->Get_W())/2, objPersonaje->Get_y()+(objPersonaje->Get_H())/2);
			It_enem++;
		}
	}
}


void CJuego::AdministrarSangre(Graphics^ gr,Bitmap^ bmpSangre)
{
	if (ArrSangre.size() != 0)
	{
		for (int i = 0; i<ArrSangre.size(); i++)
			if (ArrSangre[i]->Get_c() >= 10)
			{		
				ArrSangre.erase(ArrSangre.begin() + i);	
				It_sangre++;
			}

		for (int i = 0; i<ArrSangre.size(); i++)
		{
			ArrSangre[i]->Dibujar(gr,bmpSangre);
			ArrSangre[i]->Set_c(ArrSangre[i]->Get_c()+1);
			It_sangre++;
		}
	}
}



void CJuego::EvaluarColisionBalaEnemigo(Graphics^ gr,Bitmap^ bmpSangre)
{
	if (ArrBalas.size() != 0 && ArrEnemigos.size() != 0)
		for (int i = 0; i < ArrBalas.size(); i++)
		{
			for (int j = 0; j < ArrEnemigos.size(); j++)
			{
				if (ColisionBalaEnemigo(ArrBalas[i], ArrEnemigos[j],gr))
				{
					ArrBalas[i]->Set_eliminar(true);
					ArrEnemigos[j]->Set_VidaE(ArrEnemigos[j]->Get_VidaE()-1);
					ArrSangre.push_back(new CSangre(ArrEnemigos[j]->Get_x(),ArrEnemigos[j]->Get_y(),bmpSangre));
					//ArrSangre.push_back(new CSangre(100,100,bmpSangre));
				}

				It_enem++;
			}

			It_Balas++;
		}
}

void CJuego::EvaluarColisionPersonajeEnemigo(Graphics^ gr)
{
	if (ArrEnemigos.size() != 0)
	{
		for (int i = 0; i < ArrEnemigos.size(); i++)
		{
			if(ColisionFiguras(objPersonaje,ArrEnemigos[i],gr))
			{
				objPersonaje->Set_VidaE(objPersonaje->Get_VidaE()-(1*ArrEnemigos[i]->GetTipo()));
				if(objPersonaje->Get_VidaE()<0)
					objPersonaje->Set_VidaE(0);	
				//ArrSangre.push_back(new CSangre(objPersonaje->Get_x(),objPersonaje->Get_y(),bmpSangre));
			}
			It_enem++;
		}	
	}
}



// Privados

bool CJuego::ColisionBalaEnemigo(CBala* obj1,CFigura* obj2,Graphics^ gr){
	Rectangle r1 = Rectangle(obj1->Get_x(), obj1->Get_y(), obj1->Get_W(), obj1->Get_H());
	Rectangle r2 = Rectangle(obj2->Get_x()+10, obj2->Get_y()+obj2->Get_H()/3+10, obj2->Get_W()-10, 2*obj2->Get_H()/3-15);
	if (r1.IntersectsWith(r2))
	{
		//gr->DrawRectangle(Pens::Yellow,obj2->Get_x()+10, obj2->Get_y()+obj2->Get_H()/3+10, obj2->Get_W()-10, 2*obj2->Get_H()/3-15);
		return true;
	}
	return false;
}


bool CJuego::ColisionFiguras(CFigura* obj1,CFigura* obj2,Graphics^ gr)
{
	Rectangle r1 = Rectangle(obj1->Get_x()+10, obj1->Get_y()+obj1->Get_H()/3+10, obj1->Get_W()-10, 2*obj1->Get_H()/3-15);
	Rectangle r2 = Rectangle(obj2->Get_x()+10, obj2->Get_y()+obj2->Get_H()/3+10, obj2->Get_W()-10, 2*obj2->Get_H()/3-15);
	if (r1.IntersectsWith(r2))
	{
		//gr->DrawRectangle(Pens::Green,obj1->Get_x()+10, obj1->Get_y()+obj1->Get_H()/3+10, obj1->Get_W()-10, 2*obj1->Get_H()/3-15);
		//gr->DrawRectangle(Pens::Red,obj2->Get_x()+10, obj2->Get_y()+obj2->Get_H()/3+10, obj2->Get_W()-10, 2*obj2->Get_H()/3-15);
		return true;
	}
	return false;
}


void  CJuego::Guardar_pila()
{
	Arrplace.clear();
	place cor;
	cor.first=objPersonaje->Get_x();
	cor.second=objPersonaje->Get_y();
	cor.third=objPersonaje->Get_VidaE();
	cor.fourth=0;
	cor.fifth=0;
	Arrplace.push_back(cor);

	if(!ArrEnemigos.empty())
		for(int i=0;i<ArrEnemigos.size();i++)
		{
			cor.first=ArrEnemigos[i]->Get_x();
			cor.second=ArrEnemigos[i]->Get_y();
			cor.third=ArrEnemigos[i]->GetID();
			cor.fourth=ArrEnemigos[i]->GetTipo();
			cor.fifth=ArrEnemigos[i]->Get_VidaE();

			Arrplace.push_back(cor);
			It_enem++;
		}

	pila.push(Arrplace);
	It_pila++;

	

	BalasPila.clear();

	if(!ArrBalas.empty())
		for(int i=0;i<ArrBalas.size();i++)
		{
			Bala cor2;
			cor2.x=ArrBalas[i]->Get_x();
			cor2.y=ArrBalas[i]->Get_y();
			cor2.dx=ArrBalas[i]->Get_dx();
			cor2.dy=ArrBalas[i]->Get_dy();

			BalasPila.push_back(cor2);
			It_Balas++;
		}

	
	pilabala.push(BalasPila);
	It_pilabala++;
}


void CJuego::Retroceder_tiempo(Bitmap^ bmpEnemigo1,Bitmap^ bmpEnemigo2,Bitmap^ bmpEnemigo3)
{
	if(!pila.empty())
	{	
		objPersonaje->Set_x(pila.top()[0].first);
		objPersonaje->Set_y(pila.top()[0].second);
		objPersonaje->Set_VidaE(pila.top()[0].third);


		if((ArrEnemigos.empty())&&(pila.top().size()>1))
		{			
			int i=1;
			while(ArrEnemigos.size()<pila.top().size()-1)
			{
				int ptipo=pila.top()[i].fourth;

				switch (ptipo)
				{
				case 1:
					ArrEnemigos.push_back(new CEnemigo(pila.top()[i].first,pila.top()[i].second,2,4,bmpEnemigo1,ptipo,pila.top()[i].third,Nivel));
					break;
				case 2:
					ArrEnemigos.push_back(new CEnemigo(pila.top()[i].first,pila.top()[i].second,4,3,bmpEnemigo2,ptipo,pila.top()[i].third,Nivel));
					break;		
				case 3 :		
					ArrEnemigos.push_back(new CEnemigo(pila.top()[i].first,pila.top()[i].second,4,3,bmpEnemigo3,ptipo,pila.top()[i].third,Nivel));
					break;
				}

				i++;
			}

			pila.pop();
			return;		
		}

		
		if(!ArrEnemigos.empty())
		{		
			if(pila.top().size()==1)
			{
				while (ArrEnemigos.size()!=0)
					ArrEnemigos.pop_back();
				
				pila.pop();
				return;
			}

			for(int i=1, j=0;i<pila.top().size()&&j<ArrEnemigos.size();)
			{		
				if(pila.top()[i].third==ArrEnemigos[j]->GetID())
				{		
					ArrEnemigos[j]->Set_x(pila.top()[i].first);	
					ArrEnemigos[j]->Set_y(pila.top()[i].second);
					ArrEnemigos[j]->Set_VidaE(pila.top()[i].fifth);
		              

					if((i==pila.top().size()-1)&&(ArrEnemigos.size()>pila.top().size()-1))
					{
						while(ArrEnemigos.size()!=pila.top().size()-1)
							ArrEnemigos.pop_back();			

						break;
					}
					
					if(j==ArrEnemigos.size()-1)
					{
						while(ArrEnemigos.size()<pila.top().size()-1)
						{
							int ptipo=pila.top()[i].fourth;

							switch (ptipo)
							{
							case 1:
								ArrEnemigos.push_back(new CEnemigo(pila.top()[i].first,pila.top()[i].second,2,4,bmpEnemigo1,ptipo,pila.top()[i].third,Nivel));
								break;
							case 2:
								ArrEnemigos.push_back(new CEnemigo(pila.top()[i].first,pila.top()[i].second,4,3,bmpEnemigo2,ptipo,pila.top()[i].third,Nivel));
								break;		
							case 3 :		
								ArrEnemigos.push_back(new CEnemigo(pila.top()[i].first,pila.top()[i].second,4,3,bmpEnemigo3,ptipo,pila.top()[i].third,Nivel));
								break;
							}

							i++;
						}
						break;
					}

					i++; j++;
				}
				else 
				{	
					int ptipo=pila.top()[i].fourth;

					switch (ptipo)
					{
					case 1:
						ArrEnemigos.insert(ArrEnemigos.begin()+j,new CEnemigo(pila.top()[i].first,pila.top()[i].second,2,4,bmpEnemigo1,ptipo,pila.top()[i].third,Nivel));
						break;
					case 2:
						ArrEnemigos.insert(ArrEnemigos.begin()+j,new CEnemigo(pila.top()[i].first,pila.top()[i].second,4,3,bmpEnemigo2,ptipo,pila.top()[i].third,Nivel));
						break;
					case 3 :
						ArrEnemigos.insert(ArrEnemigos.begin()+j,new CEnemigo(pila.top()[i].first,pila.top()[i].second,4,3,bmpEnemigo3,ptipo,pila.top()[i].third,Nivel));
						break;
					}

					if((i==pila.top().size()-1)&&(ArrEnemigos.size()>pila.top().size()-1))
					{
						while(ArrEnemigos.size()!=pila.top().size()-1)
							ArrEnemigos.pop_back();						
						
						break;
					}


					if(j==ArrEnemigos.size()-1)
					{
						while(ArrEnemigos.size()<pila.top().size()-1)
						{
							int ptipo=pila.top()[i].fourth;

							switch (ptipo)
							{
							case 1:
								ArrEnemigos.push_back(new CEnemigo(pila.top()[i].first,pila.top()[i].second,2,4,bmpEnemigo1,ptipo,pila.top()[i].third,Nivel));
								break;
							case 2:
								ArrEnemigos.push_back(new CEnemigo(pila.top()[i].first,pila.top()[i].second,4,3,bmpEnemigo2,ptipo,pila.top()[i].third,Nivel));
								break;		
							case 3 :		
								ArrEnemigos.push_back(new CEnemigo(pila.top()[i].first,pila.top()[i].second,4,3,bmpEnemigo3,ptipo,pila.top()[i].third,Nivel));
								break;
							}

							i++;
						}
						break;
					}

					i++;	j++;					
				}
			}
	
		}

		pila.pop();
	}




	if(!pilabala.empty())
	{
		if((ArrBalas.empty())&&(pilabala.top().size()>0))
		{	
			int i=0;
			while(ArrBalas.size()<pilabala.top().size())
			{
				ArrBalas.push_back(new CBala(pilabala.top()[i].x,pilabala.top()[i].y,pilabala.top()[i].dx,pilabala.top()[i].dy));
				i++;
			}

			pilabala.pop();
			return;		
		}

		
		if(!ArrBalas.empty())
		{		
			if(pilabala.top().size()==1)
			{
				while (ArrBalas.size()!=0)
					ArrBalas.pop_back();
				
				pilabala.pop();
				return;
			}

			for(int i=0, j=0;i<pilabala.top().size()&&j<ArrBalas.size();)
			{		
				if(pilabala.top()[i].x==ArrBalas[j]->Get_x())
				{		
					ArrBalas[j]->Set_x(pilabala.top()[i].x);	
					ArrBalas[j]->Set_y(pilabala.top()[i].y);
					ArrBalas[j]->Set_dx(pilabala.top()[i].dx);
		            ArrBalas[j]->Set_dy(pilabala.top()[i].dy);  

					if((i==pilabala.top().size()-1)&&(ArrBalas.size()>pilabala.top().size()))
					{
						while(ArrBalas.size()!=pilabala.top().size())
							ArrBalas.pop_back();			

						break;
					}
					
					if(j==ArrBalas.size()-1)
					{
						while(ArrBalas.size()<pilabala.top().size()-1)
						{							
							ArrBalas.push_back(new CBala(pilabala.top()[i].x,pilabala.top()[i].y,pilabala.top()[i].dx,pilabala.top()[i].dy));
							i++;
						}
						break;
					}

					i++; j++;
				}
				else 
				{	
					ArrBalas.insert(ArrBalas.begin()+j,new CBala(pilabala.top()[i].x,pilabala.top()[i].y,pilabala.top()[i].dx,pilabala.top()[i].dy));
					

					if((i==pilabala.top().size()-1)&&(ArrBalas.size()>pilabala.top().size()))
					{
						while(ArrBalas.size()!=pilabala.top().size())
							ArrBalas.pop_back();
						break;
					}

					if(j==ArrBalas.size()-1)
					{
						while(ArrBalas.size()<pilabala.top().size())
						{
							ArrBalas.push_back(new CBala(pilabala.top()[i].x,pilabala.top()[i].y,pilabala.top()[i].dx,pilabala.top()[i].dy));
							i++;
						}
						break;
					}

					i++;	j++;					
				}
			}
	
		}
		pilabala.pop();	
	}
}


void CJuego::MostrarDatos(Graphics^ gr)
{
	Font^f = gcnew Font("Arial Black",8);
	gr->FillRectangle(Brushes::Gray,50,0,600,45);	

	gr->DrawString("Vida: ",f,Brushes::Black,55,2);	
	gr->DrawRectangle(Pens::Black,109,4,301,11);	
	gr->FillRectangle(Brushes::Red,110,5,objPersonaje->Get_VidaE(),10);
	gr->DrawString("("+objPersonaje->Get_VidaE()+"/"+objPersonaje->Get_VidaOriginal()+")",
					f,Brushes::Black,415,2);
	
	gr->DrawString("Energía: ",f,Brushes::Black,55,23);
	gr->DrawRectangle(Pens::Black,109,24,301,11);	
	gr->FillRectangle(Brushes::Yellow,110,25,(300*energia)/energiaMax,10);
	gr->DrawString("("+energia+"/"+energiaMax+")",f,Brushes::Black,415,22);
	
	gr->DrawString("Puntaje:",f,Brushes::Black,500,11);	
	gr->DrawString(puntaje.ToString(),f,Brushes::Black,550,11);

	gr->DrawString("Nivel: ",f,Brushes::Black,500,0);	
	gr->DrawString(Nivel.ToString(),f,Brushes::Black,550,0);	

}



void CJuego::Guardar_Partida()
{
	path snapshot;

	snapshot.Personaje_x=objPersonaje->Get_x();
	snapshot.Personaje_y=objPersonaje->Get_y();
	snapshot.Personaje_vida=objPersonaje->Get_VidaE();
	snapshot.Puntaje=puntaje;
	snapshot.nivel=Nivel;
	snapshot.cant_enemigos=ArrEnemigos.size();
	snapshot.cant_balas=ArrBalas.size();
	snapshot.energia=energia;

	for (int i = 0; i < ArrEnemigos.size(); i++)
	{
		Enemigo captura;

		captura.id=ArrEnemigos[i]->GetID();
		captura.tipo=ArrEnemigos[i]->GetTipo();
		captura.vida=ArrEnemigos[i]->Get_VidaE();
		captura.x=ArrEnemigos[i]->Get_x();
		captura.y=ArrEnemigos[i]->Get_y();
		
		snapshot.enemigos[i]=captura;
	}

	for (int i = 0; i < ArrBalas.size(); i++)
	{
		Bala captu;

		captu.x=ArrBalas[i]->Get_x();
		captu.y=ArrBalas[i]->Get_y();
		captu.dx=ArrBalas[i]->Get_dx();
		captu.dy=ArrBalas[i]->Get_dy();

		snapshot.balas[i]=captu;	
	}

	FILE* archivo= fopen("Partida.dat","wb");
	fwrite(&snapshot,sizeof(snapshot),1,archivo);
	fclose(archivo);
}


bool CJuego::Cargar_Partida(Bitmap^ bmpEnemigo1,Bitmap^ bmpEnemigo2,Bitmap^ bmpEnemigo3)
{
	path datos;
	FILE* archivo= fopen("Partida.dat","rb");
	
	if(archivo==nullptr)
		return false;

	fread(&datos,sizeof(datos),1,archivo);
	fclose(archivo);

	objPersonaje->Set_x(datos.Personaje_x);
	objPersonaje->Set_y(datos.Personaje_y);
	objPersonaje->Set_VidaE(datos.Personaje_vida);
	puntaje=datos.Puntaje;
	Nivel=datos.nivel;
	
	
	ArrEnemigos.clear();
	ArrBalas.clear();

	energia=datos.energia;

	for (int i = 0; i < datos.cant_enemigos; i++)
	{
		int ptipo=datos.enemigos[i].tipo;

		switch (ptipo)
		{
		case 1:
			ArrEnemigos.push_back(new CEnemigo(datos.enemigos[i].x,datos.enemigos[i].y,2,4,bmpEnemigo1,ptipo,datos.enemigos[i].id,Nivel));
			break;
		case 2:
			ArrEnemigos.push_back(new CEnemigo(datos.enemigos[i].x,datos.enemigos[i].y,4,3,bmpEnemigo2,ptipo,datos.enemigos[i].id,Nivel));
			break;
		case 3 :
			ArrEnemigos.push_back(new CEnemigo(datos.enemigos[i].x,datos.enemigos[i].y,4,3,bmpEnemigo3,ptipo,datos.enemigos[i].id,Nivel));
			break;
		}
	}

	for (int i = 0; i <datos.cant_balas; i++)
		ArrBalas.push_back(new CBala(datos.balas[i].x,datos.balas[i].y,datos.balas[i].dx,datos.balas[i].dy));
}

void CJuego::Mostrar_Memoria(Graphics^ gr)
{
	int memoria_tota=0;
	memoria_tota=sizeof(CPersonaje)+sizeof(CFondo)+sizeof( CEnemigo)*(ArrEnemigos.size())+sizeof(CBala)*(ArrBalas.size())+sizeof(CSangre)*(ArrSangre.size())+sizeof(Arrplace)+sizeof(pila)+11*sizeof(int)+(sizeof(path)*pila.size());
		
	Font^f = gcnew Font("Arial Black",8);
	gr->FillRectangle(Brushes::Green,781,1,178,459);
	gr->FillRectangle(Brushes::Black,781+5,1+5,178-10,459-10);
	gr->DrawString("Memoria En Uso Del Juego",f,Brushes::Green,785,3);
	gr->DrawString("Juego total:  "+memoria_tota.ToString(),f,Brushes::Green,785,3+9);
	gr->DrawString("Personaje:    "+(sizeof(CPersonaje)).ToString(),f,Brushes::Green,785,3+18);
	gr->DrawString("Enemigos:     "+(sizeof( CEnemigo)*(ArrEnemigos.size())).ToString(),f,Brushes::Green,785,3+27);
	gr->DrawString("Pila:  "+((sizeof(path)*pila.size())+(sizeof(Bala)*pilabala.size())).ToString(),f,Brushes::Green,785,3+36);
	gr->DrawString("Balas:   "+(sizeof( CBala)*(ArrBalas.size())).ToString(),f,Brushes::Green,785,3+45);
	gr->DrawString("Sangre:   "+(sizeof( CSangre)*(ArrSangre.size())).ToString(),f,Brushes::Green,785,3+54);
	gr->DrawString("             Iteraciones     ",f,Brushes::Green,785,3+63);
	gr->DrawString("Guardado en Pila:    "+(It_pila+It_pilabala).ToString(),f,Brushes::Green,785,3+72);
	gr->DrawString("Enemigos:      "+It_enem.ToString(),f,Brushes::Green,785,3+81);
	gr->DrawString("Balas:      "+It_Balas.ToString(),f,Brushes::Green,785,3+90);
	gr->DrawString("Sangre:      "+It_sangre.ToString(),f,Brushes::Green,785,3+99);
}


int CJuego::Get_Puntaje(){return puntaje;}