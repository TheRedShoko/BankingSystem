#pragma once
#include <string>

class BankCard
{
	friend class DatabaseService;
private:
	std::string accountNumber;
	std::string serialNumber;
	std::string PIN;

	void parseFromString(const std::string& s);
public:
	BankCard(const std::string& account, const std::string& serialNumber, const std::string& PIN);
	BankCard(const std::string& from_string);

	bool operator==(const std::string& other) const;
	bool operator==(const BankCard& other) const;

	const std::string& GetAccountNumber() const;

	std::string ToString() const;
};