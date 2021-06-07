#pragma once
#include <string>
#include "BankCard.h"
#include <vector>
class BankAccount
{
private:
	friend class DatabaseService;

	std::string serialNumber;
	double amount;

	std::vector<BankCard> cards;

	void parseAccountFromString(std::string s);
public:
	BankAccount(std::string account_as_string);

	bool operator==(const std::string& other) const;
	bool operator==(const BankAccount& other) const;

	void AddCard(BankCard card);

	std::string ToString() const;
};

