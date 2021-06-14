#pragma once
#include "Person.h"
#include "SystemAccount.h"

class BankEmployee : public Person, public SystemAccount
{
	void parseFromString(const std::string& s);
public:
	BankEmployee(const std::string& from_string);
	BankEmployee(const std::string& username, const std::string& password, const std::string& idn, const std::string& firstName, const std::string& middleName, const std::string& lastName, const std::string& dateOfBirth, const std::string& phoneNumber, const std::string& address);

	void CreateClient();
	void DeleteClient();

	void CreateBankAccount();
	void DeleteBankAccount();

	void CreateCard();
	void DeleteCard();

	void AllClientsReport();
	void IndividualClientReport();

	std::string ToEscapedString() override;
};