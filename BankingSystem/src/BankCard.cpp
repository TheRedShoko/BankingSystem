#include "BankCard.h"

void BankCard::parseFromString(std::string s)
{
	size_t delim = s.find(" ");
	this->accountNumber = s.substr(0, delim);
	size_t end = s.find(" ", delim + 1);
	this->serialNumber = s.substr(delim + 1, end - delim - 1);

	this->PIN = s.substr(end + 1);
}

BankCard::BankCard(std::string account, std::string serialNumber, std::string PIN)
	: accountNumber(account), serialNumber(serialNumber), PIN(PIN)
{
}

BankCard::BankCard(std::string from_string)
{
	this->parseFromString(from_string);
}

bool BankCard::operator==(const std::string& other) const
{
	return this->serialNumber == other;
}

bool BankCard::operator==(const BankCard& other) const
{
	return this->serialNumber == other.serialNumber;
}

std::string BankCard::GetAccountNumber() const
{
	return this->accountNumber;
}

std::string BankCard::ToString() const
{
	return this->accountNumber + " " + this->serialNumber + " " + this->PIN;
}
