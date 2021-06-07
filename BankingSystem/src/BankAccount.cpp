#include "BankAccount.h"

void BankAccount::parseAccountFromString(std::string s)
{
	size_t delim = s.find(" ");
	this->serialNumber = s.substr(0, delim);
	this->amount = std::stod(s.substr(delim + 1));
}

BankAccount::BankAccount(std::string account_as_string)
{
	this->parseAccountFromString(account_as_string);
}

bool BankAccount::operator==(const std::string& other) const
{
	return this->serialNumber == other;
}

bool BankAccount::operator==(const BankAccount& other) const
{
	return this->serialNumber == other.serialNumber;
}

void BankAccount::AddCard(BankCard card)
{
	this->cards.push_back(card);
}

std::string BankAccount::ToString() const
{
	return this->serialNumber + " " + std::to_string(this->amount);
}
