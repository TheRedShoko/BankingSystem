#include "User/Person.h"

Person::Person(std::string idn, std::string firstName, std::string middleName, std::string lastName, std::string dateOfBirth, std::string phone, std::string address)
	:idn(idn), firstName(firstName), middleName(middleName), lastName(lastName), birthDate(dateOfBirth), phoneNumber(phone), address(address)
{
}

std::string Person::ToString()
{
	return this->idn + " " + this->firstName + " " + this->middleName + " " + this->lastName + " " + this->birthDate.ToString() + this->phoneNumber + this->address;
}

std::string Person::ToEscapedString()
{
	return this->idn + " " + StringEscaper::EscapeSpaces(this->firstName) + " " 
		+ StringEscaper::EscapeSpaces(this->middleName) + " " 
		+ StringEscaper::EscapeSpaces(this->lastName) + " " 
		+ this->birthDate.ToString()
		+ this->phoneNumber + StringEscaper::EscapeSpaces(this->address);
}

std::string Person::GetIDN() const
{
	return this->idn;
}
