#include "Utils\Date.h"
#include "Utils\Validator.h"

void Date::parseDate(const std::string& date_as_string)
{
    unsigned short date, month;
    unsigned int year;

    size_t endPos = date_as_string.find('/');
    date = stoi(date_as_string.substr(0, endPos));

    size_t startPos = endPos + 1;
    endPos = date_as_string.find('/', startPos);
    month = stoi(date_as_string.substr(startPos, endPos));

    year = stoi(date_as_string.substr(endPos + 1));

    if (!Validator::IsValidDate(year, month, date))
    {
        throw std::exception("Invalid date provided!");
    }

    this->year = year;
    this->month = month;
    this->date = date;
}

Date::Date(unsigned int year, unsigned short month, unsigned short date)
{
    if (!Validator::IsValidDate(year, month, date))
    {
        throw std::exception("Invalid date provided!");
    }

    this->year = year;
    this->month = month;
    this->date = date;
}

Date::Date(const std::string& date_as_string)
{
    this->parseDate(date_as_string);
}

void Date::SetDateFromString(const std::string& date)
{
    this->parseDate(date);
}

std::string Date::ToString()
{
    return std::to_string(this->date) + "/" + std::to_string(this->month) + "/" + std::to_string(this->year);
}
