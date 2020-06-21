#include <iostream>
#include <io.h>
#include <fcntl.h>
#include "Menus/MenuBase.h"
#include "Menus/MainMenu.h"
#include "Display/IDisplay.h"
#include "Display/ConsoleDisplay.h"

int main()
{
	system("mode con: lines=30 cols=60");
	_setmode(_fileno(stdout), _O_U16TEXT);
	_setmode(_fileno(stdin), _O_U16TEXT);
	_setmode(_fileno(stderr), _O_U16TEXT);

	MenuBase* menu = new MainMenu();
	menu->Open();

	/*IDisplay<wchar_t>* d = new ConsoleDisplay<wchar_t>();

	auto t = d->EnterText();

	std::wcout << std::endl << t;*/

	/*for (size_t i = 9000; i < 12000; i++)
	{
		std::wcout << L"#" << i << L": " << wchar_t(i) << std::endl;
	}*/
	return 0;
}