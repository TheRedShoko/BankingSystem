#pragma once
#include <string>

class Validator
{
public:
	static bool IsValidIDN(std::string idn);
	static bool IsValidDate(unsigned int year, unsigned short month, unsigned short date);
};