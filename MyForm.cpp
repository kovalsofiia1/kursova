#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Globalization;
using namespace System::Threading;

[STAThreadAttribute]

int main() {
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	kursova::MyForm form;
	setlocale(LC_ALL, "uk-UA");;
	//Thread.CurrentThread.CurrentCulture = new CultureInfo("uk-UA");
	//Thread->CurrentThread.CurrentUICulture = new CultureInfo("UA");
	Application::Run(% form);
}
