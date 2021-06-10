#include "User/Client.h"
#include "Services/IOService.h"
#include "Services/DatabaseService.h"
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

void Client::DepositAmount()
{
	double amount;
	IOService::ReadDouble("Input amount to deposit:", amount);

	this->dbContext->DepositBalance(this, amount);

	IOService::WriteLine("Amount successfully added to your balance!");
}

void Client::WithdrawAmount()
{
	double amount;
	IOService::ReadDouble("Input amount to withdraw:", amount);

	this->dbContext->WithdrawBalance(this, amount);

	IOService::WriteLine("Amount successfully withdrawn from your balance!");
}

void Client::CheckBalance()
{
	IOService::WriteLine("Available balance: " + std::to_string(this->loggedInAccount->amount));
}

std::string Client::ToEscapedString()
{
	return Person::ToEscapedString() + " " + std::to_string(this->totalNumberOfAccounts) + " " + std::to_string(this->totalNumberOfCards);
}

std::string Client::ToString()
{
	return Person::ToString() + " " + std::to_string(this->totalNumberOfAccounts) + " " + std::to_string(this->totalNumberOfCards);
}
