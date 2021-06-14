#pragma once
#include <string>
#include "BankCard.h"
#include <vector>
class BankAccount
{
private:
	friend class DatabaseService;
	friend class Client;

	std::string serialNumber;
	double amount;

	std::vector<BankCard> cards;

	void parseAccountFromString(const std::string& s);
public:
	BankAccount(const std::string& accNumber, double amount);
	BankAccount(const std::string& account_as_string);

	bool operator==(const std::string& other) const;
	bool operator==(const BankAccount& other) const;

	void AddCard(BankCard card);

	std::string ToString() const;
};

