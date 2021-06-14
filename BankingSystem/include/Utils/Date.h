#pragma once
#include <string>
class Date
{
private:
	unsigned int year;
	unsigned short month;
	unsigned short date;

	void parseDate(const std::string& date_as_string);
public:
	Date() = default;
	Date(unsigned int year, unsigned short month, unsigned short date);
	Date(const std::string& date_as_string);
	void SetDateFromString(const std::string& date);
	std::string ToString();
};

