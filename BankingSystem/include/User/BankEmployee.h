#pragma once
#include "Person.h"
#include "SystemAccount.h"

class BankEmployee : public virtual Person, public virtual SystemAccount
{
	void parseFromString(std::string s);
public:
	BankEmployee(std::string from_string);
	BankEmployee(std::string username, std::string password, std::string idn, std::string firstName, std::string middleName, std::string lastName, std::string dateOfBirth, std::string phoneNumber, std::string address);

	std::string ToEscapedString() override;
};