#include "Utils\Date.h"

bool Date::isLeapYear(unsigned int year)
{
    return ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0)));
}

void Date::parseDate(std::string date_as_string)
{
    size_t endPos = date_as_string.find('/');
    this->date = stoi(date_as_string.substr(0, endPos));

    size_t startPos = endPos + 1;
    endPos = date_as_string.find('/', startPos);
    this->month = stoi(date_as_string.substr(startPos, endPos));

    this->year = stoi(date_as_string.substr(endPos + 1));
}

bool Date::isValidDate(unsigned int year, unsigned short month, unsigned short date)
{
    if (year > 9999 || year < 1)
    {
        return false;
    }
        
    if (month < 1 || month > 12)
    {
        return false;
    }
        
    if (date < 1 || date > 31)
    {
        return false;
    }
        
    if (month == 2)
    {
        if (isLeapYear(year))
        {
            return (date <= 29);
        }
            
        return (date <= 28);
    }

    if (month == 4 || month == 6 || month == 9 || month == 11)
    {
       return (date <= 30);
    }
        

    return true;
}

Date::Date(unsigned int year, unsigned short month, unsigned short date)
{
    if (!isValidDate(year, month, date))
    {
        throw std::exception("Invalid date provided!");
    }

    this->year = year;
    this->month = month;
    this->date = date;
}

Date::Date(std::string date_as_string)
{
    this->parseDate(date_as_string);
}

void Date::SetDateFromString(std::string date)
{
    this->parseDate(date);
}

std::string Date::ToString()
{
    return std::to_string(this->date) + "/" + std::to_string(this->month) + "/" + std::to_string(this->year);
}
