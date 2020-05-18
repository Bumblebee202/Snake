#pragma once

class LevelBase
{
protected:
	wchar_t** _field;
	int _row;
	int _col;
	int _toNextLvl;

	void Delete();
public:
	LevelBase();
	LevelBase(wchar_t** field, int row, int col);
	virtual ~LevelBase();

	void virtual Loading() = 0;
	int virtual GetLevel() const = 0;
	int GetRow() const;
	int GetCol() const;
	void SetSymbol(wchar_t symbol, int x, int y);
	wchar_t GetSymbol(int x, int y);
	wchar_t** GetField() const;
	int GetToNextLvl() const;
	void SetToNextLvl(int value);
	bool IsRoad(int x, int y);
	bool IsWall(int x, int y);
};