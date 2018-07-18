#pragma once
#include "MyForm.h"
#include <Windows.h>
namespace Project1 {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	/// <summary>
	/// Resumen de MyForm1
	/// </summary>
	public ref class MyForm1 : public System::Windows::Forms::Form
	{
		Project1::MyForm^ frm;
		ResourceManager^ rm1;
		Bitmap^ bmpmenu;
		Bitmap^ bmpNivelMapa;
		Bitmap^ bmpInfo;
		Bitmap^ bmpCred;
		int capa;
		Tecla teclapulsada;
		Tecla* cheatcode1;
		int contcc1;
		Tecla* cheatcode2;
		int contcc2;
		Tecla* cheatcode3;
		int contcc3;
		Tecla* cheatcode4;
		int contcc4;
		int contMuestraLogroCC;
	private: System::Windows::Forms::Button^  button9;
	private: System::Windows::Forms::Button^  button10;
	private: System::Windows::Forms::Button^  button11;
	private: System::Windows::Forms::Button^  button12;
	private: System::Windows::Forms::Timer^  timer1;
			 
	public:
		MyForm1(void)
		{
			InitializeComponent();
			rm1=gcnew ResourceManager ("Project1.Resource", GetType()->Assembly);
			bmpmenu=(Bitmap^)(rm1)->GetObject("Menu");
			bmpNivelMapa=(Bitmap^)(rm1)->GetObject("MapaNiveles");
			bmpNivelMapa->MakeTransparent(bmpNivelMapa->GetPixel(1,1));
			bmpInfo=(Bitmap^)(rm1)->GetObject("Fondo_histo_fin");
			bmpInfo->MakeTransparent(bmpInfo->GetPixel(1,1));
			bmpCred=(Bitmap^)(rm1)->GetObject("Fondo_Credi");
			bmpCred->MakeTransparent(bmpCred->GetPixel(1,1));
			InicializarCC();
			capa=1;
			teclapulsada=Tecla::ninguno;
			contMuestraLogroCC=0;
			
		}
		
	protected:
		/// <summary>
		/// Limpiar los recursos que se estén utilizando.
		/// </summary>
		~MyForm1()
		{
			delete rm1;
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::Button^  button8;
	private: System::ComponentModel::IContainer^  components;
	protected:
	private:
		/// <summary>
		/// Variable del diseñador requerida.
		/// </summary>
		//void CambiarEstadoBotones();
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido del método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(620, 181);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(135, 35);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Nuevo Juego";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm1::button1_Click);
			// 
			// button2
			// 
			this->button2->Enabled = false;
			this->button2->Location = System::Drawing::Point(148, 321);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(60, 20);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Nivel 2";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Visible = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm1::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(181, 159);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(60, 20);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Nivel 1";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Visible = false;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm1::button3_Click);
			// 
			// button4
			// 
			this->button4->Enabled = false;
			this->button4->Location = System::Drawing::Point(335, 375);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(60, 20);
			this->button4->TabIndex = 3;
			this->button4->Text = L"Nivel 3";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Visible = false;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm1::button4_Click);
			// 
			// button5
			// 
			this->button5->Enabled = false;
			this->button5->Location = System::Drawing::Point(503, 269);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(60, 20);
			this->button5->TabIndex = 4;
			this->button5->Text = L"Nivel 4";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Visible = false;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm1::button5_Click);
			// 
			// button6
			// 
			this->button6->Cursor = System::Windows::Forms::Cursors::Default;
			this->button6->Enabled = false;
			this->button6->Location = System::Drawing::Point(370, 137);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(60, 20);
			this->button6->TabIndex = 5;
			this->button6->Text = L"Nivel 5";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Visible = false;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm1::button6_Click);
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(620, 269);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(135, 35);
			this->button7->TabIndex = 6;
			this->button7->Text = L"Seleccionar Nivel";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm1::button7_Click);
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(620, 406);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(135, 35);
			this->button8->TabIndex = 7;
			this->button8->Text = L"Salir";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &MyForm1::button8_Click);
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm1::timer1_Tick);
			// 
			// button9
			// 
			this->button9->Location = System::Drawing::Point(620, 406);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(135, 35);
			this->button9->TabIndex = 8;
			this->button9->Text = L"Volver al Menú";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Visible = false;
			this->button9->Click += gcnew System::EventHandler(this, &MyForm1::button9_Click);
			// 
			// button10
			// 
			this->button10->Location = System::Drawing::Point(620, 222);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(135, 35);
			this->button10->TabIndex = 9;
			this->button10->Text = L"Cargar Partida";
			this->button10->UseVisualStyleBackColor = true;
			this->button10->Click += gcnew System::EventHandler(this, &MyForm1::button10_Click);
			// 
			// button11
			// 
			this->button11->Location = System::Drawing::Point(620, 360);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(135, 35);
			this->button11->TabIndex = 10;
			this->button11->Text = L"Créditos";
			this->button11->UseVisualStyleBackColor = true;
			this->button11->Click += gcnew System::EventHandler(this, &MyForm1::button11_Click);
			// 
			// button12
			// 
			this->button12->Location = System::Drawing::Point(620, 314);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(135, 35);
			this->button12->TabIndex = 11;
			this->button12->Text = L"Información";
			this->button12->UseVisualStyleBackColor = true;
			this->button12->Click += gcnew System::EventHandler(this, &MyForm1::button12_Click);
			// 
			// MyForm1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(784, 471);
			this->Controls->Add(this->button12);
			this->Controls->Add(this->button11);
			this->Controls->Add(this->button10);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->KeyPreview = true;
			this->Name = L"MyForm1";
			this->Text = L"MyForm1";
			this->Load += gcnew System::EventHandler(this, &MyForm1::MyForm1_Load);
			this->Click += gcnew System::EventHandler(this, &MyForm1::MyForm1_Click);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm1::MyForm1_KeyDown);
			this->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm1::MyForm1_MouseClick);
			this->ResumeLayout(false);
		}
#pragma endregion
	private: System::Void MyForm1_Load(System::Object^  sender, System::EventArgs^  e) {
		//PlaySound(TEXT("s.wav"),NULL,SND_ASYNC);
		this->Text="Crono-Blast";
		timer1->Enabled=true;
		button2->Visible=false;
		button3->Visible=false;
		button4->Visible=false;
		button5->Visible=false;
		button6->Visible=false;
		button9->Visible=false;
		
		button3->Enabled=true;
		button2->Enabled=false;
		button4->Enabled=false;
		button5->Enabled=false;
		button6->Enabled=false;

		this->Left=100;
		this->Top=100;


		this->Focus();	 
	}
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
				 
			int teclaint=teclapulsada;			
						
			Graphics ^gr=this->CreateGraphics();
			BufferedGraphicsContext ^bgc= BufferedGraphicsManager::Current;
			BufferedGraphics ^bg=bgc->Allocate(gr, this->ClientRectangle);
			
			if(contcc1==5||contcc2==5||contcc3==5||contcc4==5)
				EvaluarCapa();
			if(capa==1)
			{
				Drawing::Rectangle porcion = Drawing::Rectangle(0,0,bmpmenu->Width,bmpmenu->Width);
				bg->Graphics->DrawImage(bmpmenu,0,0,porcion,GraphicsUnit::Pixel);	
			}
			
			if(capa==2)
			{
				Drawing::Rectangle porcion = Drawing::Rectangle(0,0,bmpNivelMapa->Width,bmpNivelMapa->Height);
				bg->Graphics->DrawImage(bmpNivelMapa,0,0,porcion,GraphicsUnit::Pixel);	
				AdministrarCC(teclaint);
				if(contMuestraLogroCC==0)
					this->Text="Crono-Blast "+teclaint+" "+contcc1+" "+contcc2+" "+contcc3+" "+contcc4;
			}
			if(capa==3)
			{
				Drawing::Rectangle porcion = Drawing::Rectangle(0,0,bmpInfo->Width,bmpInfo->Width);
				bg->Graphics->DrawImage(bmpInfo,0,0,porcion,GraphicsUnit::Pixel);	
			
			}
			if(capa==4)
			{
				Drawing::Rectangle porcion = Drawing::Rectangle(0,0,bmpCred->Width,bmpCred->Width);
				bg->Graphics->DrawImage(bmpCred,0,0,porcion,GraphicsUnit::Pixel);	
			
			}
			bg->Render(gr);
			delete bg; 				 
			delete bgc; 				 
			delete gr;
				
				
			if(capa==1||capa==3||capa==4)
				timer1->Enabled=false;
			else if(capa==2)
				timer1->Enabled=true;
			teclapulsada=Tecla::ninguno;
			this->Focus();
		 }
	
	private: System::Void MyForm1_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		if(timer1->Enabled==true)
		{
				if (e->KeyCode==Keys::W)					teclapulsada=Tecla::arriba;
				else if (e->KeyCode==Keys::S)				teclapulsada=Tecla::abajo;
				else if (e->KeyCode==Keys::A)				teclapulsada=Tecla::izquierda;
				else if (e->KeyCode==Keys::D)				teclapulsada=Tecla::derecha;
				else if (e->KeyCode==Keys::J)				teclapulsada=Tecla::disparo;
				else if (e->KeyCode==Keys::K)				teclapulsada=Tecla::retroceso;
				//else if (e->KeyCode==Keys::V)				teclapulsada=Tecla::LOL;
				else if (e->KeyCode==Keys::L)				teclapulsada=Tecla::recuperarvida;
			
				else										teclapulsada=Tecla::ninguno;
		}
		if (e->KeyCode==Keys::Escape)
		{
			if(capa==1)
			{
				Close();
			}
			if(capa==2)
			{
				capa=1;	
				EvaluarCapa();	
				timer1->Enabled=true;
				this->Focus();
			}
		}
	}
	void MyForm1::EvaluarCapa()
	{
		switch(capa)
		{
			case 1:
			{
				button1->Visible=true;
				button10->Visible=true;
				button7->Visible=true;
				button8->Visible=true;
				button12->Visible=true;
				button11->Visible=true;
				button2->Visible=false;
				button3->Visible=false;
				button4->Visible=false;
				button5->Visible=false;
				button6->Visible=false;
				button9->Visible=false;
				this->Focus();
				break;
			}
			case 2:
			{
				button1->Visible=false;
				button10->Visible=false;
				button7->Visible=false;
				button8->Visible=false;
				button12->Visible=false;
				button11->Visible=false;
				button2->Visible=true;
				button3->Visible=true;
				button4->Visible=true;
				button5->Visible=true;
				button6->Visible=true;					
				if(contcc1==5)
					button2->Enabled=true;
				if(contcc2==5)
					button4->Enabled=true;
				if(contcc3==5)
					button5->Enabled=true;
				if(contcc4==5)
					button6->Enabled=true;
				
				button9->Visible=true;
				
				this->Focus();
				break;	
			case 3: case 4:
				button1->Visible=false;
			    button10->Visible=false;
				button7->Visible=false;
				button8->Visible=false;
				button12->Visible=false;
				button11->Visible=false;
				button2->Visible=false;
				button3->Visible=false;
				button4->Visible=false;
				button5->Visible=false;
				button6->Visible=false;
				button9->Visible=true;
				this->Focus();
				break;
			
			}		
		
		}		 
	}
		 
		int MyForm1::ComprobarCheatcode(Tecla* cheatcode, int contcc)
		{
			if(teclapulsada!=Tecla::ninguno)
			{
				if(teclapulsada==cheatcode[contcc])
					contcc++;			
				
				else
					contcc=0;			
			}
			return contcc;
		}
		void MyForm1::AdministrarCC(int teclaint)
		{					
			if(contcc1<5)
				contcc1 = ComprobarCheatcode(cheatcode1,contcc1);
			else
				button2->Enabled=true;
			if(contcc2<5)
				contcc2 = ComprobarCheatcode(cheatcode2,contcc2);
			if(contcc3<5)
				contcc3 = ComprobarCheatcode(cheatcode3,contcc3);
			if(contcc4<5)
				contcc4 = ComprobarCheatcode(cheatcode4,contcc4);		
		}
		void MyForm1::InicializarCC()
		{
			cheatcode1 = new Tecla[5];
			cheatcode1[0]=Tecla::abajo;
			cheatcode1[1]=Tecla::arriba;
			cheatcode1[2]=Tecla::izquierda;
			cheatcode1[3]=Tecla::derecha;
			cheatcode1[4]=Tecla::disparo;
			contcc1=0;
			cheatcode2 = new Tecla[5];
			cheatcode2[0]=Tecla::abajo;
			cheatcode2[1]=Tecla::abajo;
			cheatcode2[2]=Tecla::retroceso;
			cheatcode2[3]=Tecla::abajo;
			cheatcode2[4]=Tecla::retroceso;
			contcc2=0;
			cheatcode3 = new Tecla[5];
					 
			cheatcode3[0]=Tecla::arriba;
			cheatcode3[1]=Tecla::izquierda;
			cheatcode3[2]=Tecla::disparo;
			cheatcode3[3]=Tecla::recuperarvida;
			cheatcode3[4]=Tecla::arriba;
			contcc3=0;
		
			cheatcode4 = new Tecla[5];
					 
			cheatcode4[0]=Tecla::retroceso;
			cheatcode4[1]=Tecla::derecha;
			cheatcode4[2]=Tecla::recuperarvida;
			cheatcode4[3]=Tecla::disparo;
			cheatcode4[4]=Tecla::izquierda;
			contcc4=0;		
		}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				capa=1;
				EvaluarCapa();
				timer1->Enabled=true;	

				frm = gcnew Project1::MyForm(1);
				/*frm->Left=100;
				frm->Top=100;*/
				frm->ShowDialog();
		}
	private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) {
				capa=2;
				EvaluarCapa();
				timer1->Enabled=true;
				this->Focus();
			 }
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
			 				
				capa=1;
				EvaluarCapa();
				timer1->Enabled=true;	
				frm = gcnew Project1::MyForm(1);
				/*frm->Left=100;
				frm->Top=100;*/
				frm->ShowDialog();
		 }
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
				capa=1;
				EvaluarCapa();
				timer1->Enabled=true;	
				frm = gcnew Project1::MyForm(2);
				/*frm->Left=100;
				frm->Top=100;*/
				frm->ShowDialog();
		 }
	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
				capa=1;
				EvaluarCapa();
				timer1->Enabled=true;	
				frm = gcnew Project1::MyForm(3);
				/*frm->Left=100;
				frm->Top=100;*/
				frm->ShowDialog();
		 }
	private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
				capa=1;
				EvaluarCapa();
				timer1->Enabled=true;	
				frm = gcnew Project1::MyForm(4);
				/*frm->Left=100;
				frm->Top=100;*/
				frm->ShowDialog();
		 }
	private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
				capa=1;
				EvaluarCapa();
				timer1->Enabled=true;				
				frm = gcnew Project1::MyForm(5);
				/*frm->Left=100;
				frm->Top=100;*/
				frm->ShowDialog();
		 }
	private: System::Void button8_Click(System::Object^  sender, System::EventArgs^  e) {
				Close();
		 }
			 
	private: System::Void button9_Click(System::Object^  sender, System::EventArgs^  e) {
				capa=1;			
				EvaluarCapa();	
				timer1->Enabled=true;
				this->Focus();
		 }
private: System::Void MyForm1_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Focus();
		 }
private: System::Void MyForm1_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 this->Focus();
		 }
private: System::Void button10_Click(System::Object^  sender, System::EventArgs^  e) {
			
			FILE* archivo= fopen("Partida.dat","rb");		
						
			if(archivo==nullptr)
				return;

			path datos;
			fread(&datos,sizeof(datos),1,archivo);		
				
			int Nivelguardado=datos.nivel;
			frm = gcnew Project1::MyForm(Nivelguardado);
			frm->Cargar();
			
			frm->ShowDialog();

			fclose(archivo);
		 }
private: System::Void button12_Click(System::Object^  sender, System::EventArgs^  e) {
			 capa=3;			
				EvaluarCapa();	
				timer1->Enabled=true;
				this->Focus();
		 }
private: System::Void button11_Click(System::Object^  sender, System::EventArgs^  e) {
			 capa=4;			
				EvaluarCapa();	
				timer1->Enabled=true;
				this->Focus();
		 }
};
}