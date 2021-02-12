#include "MyForm11.h"

using namespace System;
using namespace System::Windows::Forms;


[STAThread]
int main()
{
	Application::EnableVisualStyles(); 
	Application::SetCompatibleTextRenderingDefault(false);
	Pro::MyForm1 form; 
	Application::Run(% form);

}