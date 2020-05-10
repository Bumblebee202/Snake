#include <iostream>
#include <io.h>
#include <fcntl.h>
#include "Menus/MenuBase.h"
#include "Menus/MainMenu.h"

int main()
{
	system("mode con: lines=30 cols=60");
	_setmode(_fileno(stdout), _O_U16TEXT);
	_setmode(_fileno(stdin), _O_U16TEXT);
	_setmode(_fileno(stderr), _O_U16TEXT);

	srand(0);

	MenuBase* menu = new MainMenu();
	menu->Open();

	/*for (size_t i = 9000; i < 12000; i++)
	{
		std::wcout << L"#" << i << L": " << wchar_t(i) << std::endl;
	}*/
	return 0;
}