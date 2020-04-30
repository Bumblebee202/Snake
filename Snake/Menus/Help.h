#pragma once
#include <vector>
#include <string>
#include "MenuBase.h"
#include "../Creators.h"

class Help : public MenuBase
{
private:
	std::vector<ItemBase*> _items;

protected:
	virtual void GenerateMenu() override;

public:
	Help(IDisplay<wchar_t>* display, int width);
	~Help();

	void virtual SelectMenuItem() override;
	void virtual Open() override;
	void virtual Show() override;
	void virtual Clear() override;
};

