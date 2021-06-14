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
	Person(const std::string& idn, const std::string& firstName, const std::string& middleName, const std::string& lastName, const std::string& dateOfBirth, const std::string& phone, const std::string& address);
	
	virtual std::string ToString();
	virtual std::string ToEscapedString();
	const std::string& GetIDN() const;
};