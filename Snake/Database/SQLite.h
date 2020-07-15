#pragma once
#include <string>
#include <vector>
#include <mutex>
#include <fstream>
#include "SQLite/sqlite3.h"
#include "../Other/Rating.h"


class SQLite
{
private:
	std::wstring _path;
	sqlite3* _db;
	sqlite3_stmt* _stmt;


	static std::mutex _mutex;
	static SQLite* _singleton;

	SQLite();
	bool DatabaseIsExist();
	int ColumnCount(std::wstring tableName);
	Rating MinRating();
	Rating MaxRating();
public:
	~SQLite();

	static SQLite* GetInstance();

	void CreateRatingTable();
	std::vector<Rating> SelectRating();
	void AddNewRating(Rating rating);
	void UpdateRating(int oldId, Rating newValue);
	void DeleteTable(std::wstring tableName);
};

