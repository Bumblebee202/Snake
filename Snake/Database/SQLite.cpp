#include "SQLite.h"

SQLite* SQLite::_singleton = nullptr;
std::mutex SQLite::_mutex;

SQLite::SQLite()
{
	_path = L"database.sqlite3";
	_db = nullptr;
	_stmt = nullptr;
	if (!DatabaseIsExist())
	{
		sqlite3_open16(_path.c_str(), &_db);
		CreateRatingTable();
	}
	else
		sqlite3_open16(_path.c_str(), &_db);
}

bool SQLite::DatabaseIsExist()
{
	std::ifstream file(_path);
	return file ? true : false;
}

SQLite::~SQLite()
{
	sqlite3_close(_db);
}

SQLite* SQLite::GetInstance()
{
	if (_singleton == nullptr)
	{
		std::lock_guard<std::mutex> lock(_mutex);
		if (_singleton == nullptr)
			_singleton = new SQLite();
	}
	return _singleton;
}

int SQLite::ColumnCount(std::wstring tableName)
{
	std::wstring query = L"select count(ID) "
						 L"from " + tableName;

	int len = query.length() * sizeof(wchar_t);

	sqlite3_prepare16(_db, query.c_str(), len, &_stmt, nullptr);
	sqlite3_step(_stmt);

	return sqlite3_column_int(_stmt, 0);
}

Rating SQLite::MinRating()
{
	std::wstring query = L"select ID, UserName, Score, Time "
						 L"from Rating "
						 L"order by Score, Time asc "
						 L"limit 1";

	int len = query.length() * sizeof(wchar_t);

	sqlite3_prepare16(_db, query.c_str(), len, &_stmt, nullptr);
	sqlite3_step(_stmt);

	int id = sqlite3_column_int(_stmt, 0);
	std::wstring name = (wchar_t*)sqlite3_column_text16(_stmt, 1);
	int score = sqlite3_column_int(_stmt, 2);
	std::wstring timeStr = (wchar_t*)sqlite3_column_text16(_stmt, 3);
	Time time = Time(timeStr);

	Rating rating = Rating(id, name, score, time);

	return rating;
}

Rating SQLite::MaxRating()
{
	std::wstring query = L"select ID, UserName, Score, Time "
						 L"from Rating "
						 L"order by Score, Time desc "
						 L"limit 1";

	int len = query.length() * sizeof(wchar_t);

	sqlite3_prepare16(_db, query.c_str(), len, &_stmt, nullptr);
	sqlite3_step(_stmt);

	int id = sqlite3_column_int(_stmt, 0);
	std::wstring name = (wchar_t*)sqlite3_column_text16(_stmt, 1);
	int score = sqlite3_column_int(_stmt, 2);
	std::wstring timeStr = (wchar_t*)sqlite3_column_text16(_stmt, 3);
	Time time = Time(timeStr);

	Rating rating = Rating(id, name, score, time);

	return rating;
}

void SQLite::CreateRatingTable()
{
	std::wstring query = L"create table `Rating` ("
						 "`ID` integer primary key autoincrement,"
						 "`UserName` text not null,"
						 "`Score` integer not null,"
						 "`Time` text not null);";

	int len = query.length() * sizeof(wchar_t);

	sqlite3_prepare16(_db, query.c_str(), len, &_stmt, nullptr);
	sqlite3_step(_stmt);
}

std::vector<Rating> SQLite::SelectRating()
{
	std::vector<Rating> ratings = std::vector<Rating>();

	std::wstring query = L"select ID, UserName, Score, Time "
						 L"from Rating "
						 L"order by Score desc, Time desc";

	int len = query.length() * sizeof(wchar_t);

	sqlite3_prepare16(_db, query.c_str(), len, &_stmt, nullptr);

	while (sqlite3_step(_stmt) == SQLITE_ROW)
	{
		int id = sqlite3_column_int(_stmt, 0);
		std::wstring name = (wchar_t*)sqlite3_column_text16(_stmt, 1);
		int score = sqlite3_column_int(_stmt, 2);
		std::wstring timeStr = (wchar_t*)sqlite3_column_text16(_stmt, 3);
		Time time = Time(timeStr);

		Rating rating = Rating(id, name, score, time);
		ratings.push_back(rating);
	}

	return ratings;
}

void SQLite::AddNewRating(Rating rating)
{
	int count = ColumnCount(L"Rating");

	if (count == 20)
	{
		Rating oldRating = MinRating();
		if (oldRating.GetScore() < rating.GetScore() ||
			(oldRating.GetScore() == rating.GetScore() && oldRating.GetTime() < rating.GetTime()))
			UpdateRating(oldRating.GetID(), rating);
	}
	else
	{
		std::wstring name = rating.GetName();
		std::wstring score = std::to_wstring(rating.GetScore());
		std::wstring time = rating.GetTime().ToString();
		std::wstring query = L"insert into Rating (UserName, Score, Time) "
							 L"values('" + name + L"', " + score + L", '" + time + L"');";

		int len = query.length() * sizeof(wchar_t);

		sqlite3_prepare16(_db, query.c_str(), len, &_stmt, nullptr);
		sqlite3_step(_stmt);
	}
}

void SQLite::UpdateRating(int oldId, Rating newValue)
{
	std::wstring id = std::to_wstring(oldId);
	std::wstring name = newValue.GetName();
	std::wstring score = std::to_wstring(newValue.GetScore());
	std::wstring time = newValue.GetTime().ToString();
	std::wstring query = L"update Rating "
						 L"set "
						 L"UserName = '" + name + L"', " 
						 L"Score = " + score + L", "
						 L"Time = '" + time + L"' "
						 L"where "
						 L"ID = " + id;

	int len = query.length() * sizeof(wchar_t);

	sqlite3_prepare16(_db, query.c_str(), len, &_stmt, nullptr);
	sqlite3_step(_stmt);
}

void SQLite::DeleteTable(std::wstring tableName)
{
	std::wstring query = L"drop table " + tableName;

	int len = query.length() * sizeof(wchar_t);

	sqlite3_prepare16(_db, query.c_str(), len, &_stmt, nullptr);
	sqlite3_step(_stmt);
}
