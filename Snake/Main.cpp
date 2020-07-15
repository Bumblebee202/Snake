#include <iostream>
#include <io.h>
#include <fcntl.h>
#include <string>
#include "Menus/MenuBase.h"
#include "Menus/MainMenu.h"
#include "Database/SQLite.h"

int main()
{
	system("mode con: lines=30 cols=60");
	_setmode(_fileno(stdout), _O_U16TEXT);
	_setmode(_fileno(stdin), _O_U16TEXT);
	_setmode(_fileno(stderr), _O_U16TEXT);

	MenuBase* menu = new MainMenu();
	menu->Open();

	return 0;
}