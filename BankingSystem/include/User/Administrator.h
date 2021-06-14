#pragma once
#include "SystemAccount.h"
#include "User/BankEmployee.h"

class Administrator : public SystemAccount
{
	void parseFromString(const std::string& s);
public:
	Administrator() = default;
	Administrator(const std::string& username, const std::string& password);
	Administrator(const std::string& from_string);

	void CreateEmployee() const;
	void DeleteEmployee() const;

	std::string ToString() const;
};