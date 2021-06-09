#include "User/Client.h"
#include <sstream>

void Client::parseClientFromString(std::string s)
{
	std::stringstream stream(s);
	std::string bDay;
	stream >> this->idn >> this->firstName >> this->middleName >> this->lastName >> bDay >> this->phoneNumber >> this->address >> this->totalNumberOfAccounts >> this->totalNumberOfCards;
	this->birthDate.SetDateFromString(bDay);
}

Client::Client(std::string clientString)
{
	this->parseClientFromString(clientString);
}

Client::Client(std::string idn, std::string firstName, std::string middleName, std::string lastName, std::string dateOfBirth, std::string phoneNumber, std::string address)
	:Person(idn, firstName, middleName, lastName, dateOfBirth, phoneNumber, address)
{
	this->totalNumberOfAccounts = 0;
	this->totalNumberOfCards = 0;
}

void Client::AddBankAccount(BankAccount account)
{
	this->bankAccounts.push_back(account);
}

void Client::AddNewBankAccount(BankAccount account)
{
	this->totalNumberOfAccounts++;
	this->AddBankAccount(account);
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

void Client::AddNewCardToAccount(std::string account, BankCard card)
{
	this->totalNumberOfCards++;
	this->AddCardToAccount(account, card);
}

std::string Client::ToString()
{
	return Person::ToString() + " " + std::to_string(this->totalNumberOfAccounts) + " " + std::to_string(this->totalNumberOfCards);
}
