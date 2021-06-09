#pragma once
#include <string>

class BankCard
{
	friend class DatabaseService;
private:
	std::string accountNumber;
	std::string serialNumber;
	std::string PIN;

	void parseFromString(std::string s);
public:
	BankCard(std::string account, std::string serialNumber, std::string PIN);
	BankCard(std::string from_string);

	bool operator==(const std::string& other) const;
	bool operator==(const BankCard& other) const;

	std::string GetAccountNumber() const;

	std::string ToString() const;
};