#pragma once

#include "Juego.h"

namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Reflection;
	using namespace System::Resources;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{

	private:

		ResourceManager^ rm;
		Bitmap^ bmpPersonaje;
		Bitmap^ bmpFondo1;
		Bitmap^ bmpFondo2;
		Bitmap^ bmpCara;

		Bitmap^ bmpEnemigo1;
		Bitmap^ bmpEnemigo2;
		Bitmap^ bmpEnemigo3;

		Bitmap^ bmpSangre;

		CJuego* objJuego;

		Tecla teclapulsada;
		int nivel;
		

	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;

	private: System::Windows::Forms::Timer^  timer1;
			 

	public:
		
		MyForm(int pnivel)
		{
			InitializeComponent();

			rm=gcnew ResourceManager ("Project1.Resource", GetType()->Assembly);

			bmpPersonaje=(Bitmap^)rm->GetObject("Django-Camina");
			bmpPersonaje->MakeTransparent(bmpPersonaje->GetPixel(1,1));
			
			bmpFondo1=(Bitmap^)rm->GetObject("map1");
			bmpFondo2=(Bitmap^)rm->GetObject("map2");

			bmpCara=(Bitmap^)rm->GetObject("Django-Cara");

			bmpEnemigo1=(Bitmap^)rm->GetObject("Enemigo1");
			bmpEnemigo1->MakeTransparent(bmpEnemigo1->GetPixel(1,1));

			bmpEnemigo2=(Bitmap^)rm->GetObject("Enemigo2");
			bmpEnemigo2->MakeTransparent(bmpEnemigo2->GetPixel(1,1));

			bmpEnemigo3=(Bitmap^)rm->GetObject("Enemigo3");
			bmpEnemigo3->MakeTransparent(bmpEnemigo3->GetPixel(1,1));

			bmpSangre=(Bitmap^)rm->GetObject("sangre");
			bmpSangre->MakeTransparent(bmpSangre->GetPixel(1,1));

			nivel=pnivel;

			Bitmap^ bmpFondo;
					if(nivel==1||nivel==2)
						bmpFondo=bmpFondo1;
					else if(nivel==3||nivel==4||nivel==5)
						bmpFondo=bmpFondo2;

			objJuego=new CJuego(bmpPersonaje,bmpFondo,bmpCara,nivel,0);

			teclapulsada=Tecla::ninguno;
			
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén utilizando.
		/// </summary>
		~MyForm()
		{
			delete objJuego;
			delete rm;

			if (components)
			{
				delete components;
			}
		}
	private: System::ComponentModel::IContainer^  components;
	protected: 

	private:
		/// <summary>
		/// Variable del diseñador requerida.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido del método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Interval = 150;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// button1
			// 
			this->button1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button1->Location = System::Drawing::Point(338, 94);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(125, 25);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Continuar Partida";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Visible = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(338, 160);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(125, 25);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Guardar Partida";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Visible = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(338, 238);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(125, 25);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Volver al Menú";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Visible = false;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(959, 462);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->KeyPreview = true;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {

			this->Text="Crono-Blast  Nivel:"+nivel;

			Graphics ^gr=this->CreateGraphics();
			BufferedGraphicsContext ^bgc= BufferedGraphicsManager::Current;
			BufferedGraphics ^bg=bgc->Allocate(gr, this->ClientRectangle);

			Bitmap^ bmpFondo;
					if(nivel==1||nivel==2)
						bmpFondo=bmpFondo1;
					else if(nivel==3||nivel==4||nivel==5)
						bmpFondo=bmpFondo2;

			
			objJuego->MostrarTodo(bg->Graphics,teclapulsada,bmpPersonaje,bmpFondo,bmpEnemigo1,bmpEnemigo2,bmpEnemigo3,bmpCara,bmpSangre);
			
			if(objJuego->GamerOver())
			{
				this->Text="Crono-Blast  GAME OVER! :'v";
				timer1->Enabled=false;
				button1->Visible=true;
				button2->Visible=true;
				button3->Visible=true;
				button1->Enabled=false;
				button2->Enabled=false;			
			}


			if(objJuego->NivelSiguiente())
			{
				if(nivel==5)
				{
					this->Text="Crono-Blast  GAME OVER! Has ganado ._.";
					timer1->Enabled=false;
					button1->Visible=true;
					button2->Visible=true;
					button3->Visible=true;
					button1->Enabled=false;
					button2->Enabled=false;		
				
				}
				else
				{
					nivel++;				

					objJuego=new CJuego(bmpPersonaje,bmpFondo,bmpCara,nivel,objJuego->Get_Puntaje());
					
				}
			}

			//bg->Graphics->Clear(Color::Gray);
			
			bg->Render(gr);


			delete bg; 				 
			delete bgc; 				 
			delete gr;

			teclapulsada=Tecla::ninguno;
			this->Focus();

		 }


	private: System::Void MyForm_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {

	if(timer1->Enabled==true)
	{

			if (e->KeyCode==Keys::W)					teclapulsada=Tecla::arriba;
			else if (e->KeyCode==Keys::S)				teclapulsada=Tecla::abajo;
			else if (e->KeyCode==Keys::A)				teclapulsada=Tecla::izquierda;
			else if (e->KeyCode==Keys::D)				teclapulsada=Tecla::derecha;
			else if (e->KeyCode==Keys::J)				teclapulsada=Tecla::disparo;
			else if (e->KeyCode==Keys::K)				teclapulsada=Tecla::retroceso;
			else if (e->KeyCode==Keys::L)				teclapulsada=Tecla::recuperarvida;
			//else if (e->KeyCode==Keys::V)				teclapulsada=Tecla::LOL;
			
			else										teclapulsada=Tecla::ninguno;

	}

	if (e->KeyCode==Keys::P)
	{
		if(!objJuego->GamerOver())
		{
			timer1->Enabled=!timer1->Enabled;

			button1->Visible=!button1->Visible;
			button2->Visible=!button2->Visible;
			button3->Visible=!button3->Visible;
		
			this->Focus();

			teclapulsada=Tecla::ninguno;
		}
	}


	if (e->KeyCode==Keys::Escape)						Close();


	}


	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {

			timer1->Enabled = true;	
			this->Focus();
	}


	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

			button1->Visible=false;
			button2->Visible=false;
			button3->Visible=false;

			this->Focus();

			teclapulsada=Tecla::ninguno;
			timer1->Enabled=true;

	}

private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {

			
			objJuego->Guardar_Partida();
			Close();
	}


private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {

			Close();
	}


		  public:
         bool MyForm::Cargar()
		 {
		 	if(objJuego->Cargar_Partida(bmpEnemigo1,bmpEnemigo2,bmpEnemigo3))
				return true;
			else
				return false;
		 }



};
}
