#pragma once
#include <string>
class Date
{
private:
	unsigned int year;
	unsigned short month;
	unsigned short date;

	bool isValidDate(unsigned int year, unsigned short month, unsigned short date);
	bool isLeapYear(unsigned int year);

	void parseDate(std::string date_as_string);
public:
	Date() = default;
	Date(unsigned int year, unsigned short month, unsigned short date);
	Date(std::string date_as_string);
	void SetDateFromString(std::string date);
	std::string ToString();
};

