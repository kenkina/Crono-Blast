#include "MyForm1.h" 
using namespace System; 
using namespace System::Windows::Forms; 
[STAThread] 
void main(array<String^>^ arg) 
{ 
Application::EnableVisualStyles(); Application::SetCompatibleTextRenderingDefault(false); 
Application::Run( gcnew Project1::MyForm1());
} 


