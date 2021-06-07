#include "User/BankEmployee.h"
#include <sstream>

void BankEmployee::parseFromString(std::string s)
{
	std::stringstream stream(s);
	std::string bDay;
	stream >> this->authorizationKey >> this->authorizationPassword >> this->idn >> this->firstName >> this->middleName >> this->lastName >> bDay >> this->phoneNumber >> this->address;

	this->birthDate.SetDateFromString(bDay);
}

BankEmployee::BankEmployee(std::string from_string)
{
	this->parseFromString(from_string);
}

BankEmployee::BankEmployee(std::string username, std::string password, std::string idn, std::string firstName, std::string middleName, std::string lastName, std::string dateOfBirth, std::string phoneNumber, std::string address)
	:SystemAccount(username, password), Person(idn, firstName, middleName, lastName, dateOfBirth, phoneNumber, address)
{
}

std::string BankEmployee::ToEscapedString()
{
	return this->authorizationKey + " " + this->authorizationPassword + " " + Person::ToEscapedString();
}
