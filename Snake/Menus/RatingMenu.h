#pragma once
#include <vector>
#include <string>
#include "MenuBase.h"
#include "../Settings/Button.h"
#include "../Database/SQLite.h"
#include "../Other/Rating.h"

class RatingMenu : public MenuBase
{
private:
	std::vector<Rating> _ratings;
	SQLite* _sqlite;
protected:
	virtual void GenerateMenu() override;
public:
	RatingMenu(IDisplay<wchar_t>* display, int width);

	void virtual SelectMenuItem() override;
	void virtual Open() override;
	void virtual Show() override;
	void virtual Clear() override;
};

