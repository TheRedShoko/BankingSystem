#include "Utils\Validator.h"

bool Validator::IsValidIDN(std::string idn)
{
    if (idn.length() != 10)
    {
        return false;
    }

    for (size_t i = 0; i < idn.length(); i++)
    {
        if (!isdigit(idn[i]))
        {
            return false;
        }
    }

    return true;
}

bool isLeapYear(unsigned int year)
{
    return ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0)));
}

bool Validator::IsValidDate(unsigned int year, unsigned short month, unsigned short date)
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
