#pragma once
#include <string>
#include "Utils/Date.h"
#include "Utils/StringEscaper.h"

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
	virtual ~Person() = default;
	Person(std::string idn, std::string firstName, std::string middleName, std::string lastName, std::string dateOfBirth, std::string phone, std::string address);
	
	virtual std::string ToString();
	virtual std::string ToEscapedString();
	std::string GetIDN() const;
};

