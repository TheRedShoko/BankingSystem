#include "BankCard.h"

void BankCard::parseFromString(std::string s)
{
	size_t delim = s.find(" ");
	this->accountNumber = s.substr(0, delim);
	size_t end = s.find(" ", delim + 1);
	this->serialNumber = s.substr(delim + 1, end - delim);

	this->PIN = s.substr(end + 1);
}

BankCard::BankCard(std::string from_string)
{
	this->parseFromString(from_string);
}

std::string BankCard::GetAccountNumber() const
{
	return this->accountNumber;
}

std::string BankCard::ToString() const
{
	return this->accountNumber + " " + this->serialNumber + " " + this->PIN;
}
