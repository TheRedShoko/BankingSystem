#include "User/Client.h"
#include <sstream>

void Client::parseClientFromString(std::string s)
{
	std::stringstream stream(s);
	std::string bDay;
	stream >> this->idn >> this->firstName >> this->middleName >> this->lastName >> bDay >> this->phoneNumber >> this->address;
	this->birthDate.SetDateFromString(bDay);
}

Client::Client(std::string clientString)
{
	this->parseClientFromString(clientString);
}

void Client::AddBankAccount(BankAccount account)
{
	this->bankAccounts.push_back(account);
}

void Client::AddCardToAccount(std::string account, BankCard card)
{
	for (size_t i = 0; i < this->bankAccounts.size(); i++)
	{
		if (this->bankAccounts[i] == account)
		{
			this->bankAccounts[i].AddCard(card);

			break;
		}
	}
}
