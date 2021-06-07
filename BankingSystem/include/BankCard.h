#pragma once
#include <string>

class BankCard
{
private:
	std::string accountNumber;
	std::string serialNumber;
	std::string PIN;

	void parseFromString(std::string s);
public:
	BankCard(std::string from_string);

	std::string GetAccountNumber() const;

	std::string ToString() const;
};