#include "User/Person.h"
#include "Utils/Validator.h"

Person::Person(const std::string& idn, const std::string& firstName, const std::string& middleName, const std::string& lastName, const std::string& dateOfBirth, const std::string& phone, const std::string& address)
	:idn(idn), firstName(firstName), middleName(middleName), lastName(lastName), birthDate(dateOfBirth), phoneNumber(phone), address(address)
{
	if (!Validator::IsValidIDN(idn))
	{
		throw std::exception("Invalid UID provided!");
	}
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
		+ this->birthDate.ToString() + " "
		+ this->phoneNumber + " " + StringEscaper::EscapeSpaces(this->address);
}

const std::string& Person::GetIDN() const
{
	return this->idn;
}
