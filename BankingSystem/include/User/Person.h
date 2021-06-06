#pragma once
#include <string>
#include "Utils/Date.h"
class Person
{
protected:
	std::string idn;
	std::string firstName;
	std::string middleName;
	std::string lastName;
	Date birthDate;
	std::string phoneNumber;
	std::string address;

	Person() = default;
public:
	virtual std::string ToString();
};

