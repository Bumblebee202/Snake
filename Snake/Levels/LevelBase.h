#pragma once
#include <string>

class LevelBase
{
protected:
	wchar_t** _field;
	int _row;
	int _col;

	void Delete();
	void virtual GenerateField() = 0;
public:
	LevelBase();
	LevelBase(wchar_t** field, int row, int col);
	virtual ~LevelBase();

	std::wstring virtual GetLevel() const = 0;
	int GetRow() const;
	int GetCol() const;
	void SetSymbol(wchar_t symbol, int x, int y);
	//void SetField(wchar_t** field, int row, int col);
	wchar_t** GetField() const;
	bool IsRoad(int x, int y);
};