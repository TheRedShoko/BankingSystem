#include "User/BankEmployee.h"
#include <sstream>
#include "Services/IOService.h"
#include "Services/DatabaseService.h"

void BankEmployee::parseFromString(std::string s)
{
	std::stringstream stream(s);
	std::string bDay;
	stream >> this->authorizationKey >> this->authorizationPassword >> this->idn >> this->firstName >> this->middleName >> this->lastName >> bDay >> this->phoneNumber >> this->address;

	this->birthDate.SetDateFromString(bDay);
}

BankEmployee::BankEmployee(std::string from_string)
{
	this->parseFromString(from_string);
}

BankEmployee::BankEmployee(std::string username, std::string password, std::string idn, std::string firstName, std::string middleName, std::string lastName, std::string dateOfBirth, std::string phoneNumber, std::string address)
	:SystemAccount(username, password), Person(idn, firstName, middleName, lastName, dateOfBirth, phoneNumber, address)
{
}

void BankEmployee::CreateClient()
{
	std::string idn, firstName, middleName, lastName, dateOfBirth, phoneNumber, address;

	IOService::ReadString("Input UID:", idn);
	IOService::ReadLine("Input First name:", firstName);
	IOService::ReadLine("Input Middle name:", middleName);
	IOService::ReadLine("Input Last name:", lastName);
	IOService::ReadString("Input date of birth (dd/MM/yyyy):", dateOfBirth);
	IOService::ReadString("Input phone number:", phoneNumber);
	IOService::ReadLine("Input address:", address);

	this->dbContext->AddClient(idn, firstName, middleName, lastName, dateOfBirth, phoneNumber, address);

	IOService::WriteLine("Client added successfully!");
}

void BankEmployee::DeleteClient()
{
	std::string idn;

	IOService::ReadString("Input UID:", idn);

	this->dbContext->DeleteClient(idn);

	IOService::WriteLine("Client successfully deleted!");
}

void BankEmployee::CreateBankAccount()
{
	std::string idn;
	double deposit;
	IOService::ReadString("Input client's UID:", idn);
	IOService::ReadDouble("Input initial deposit:", deposit);

	std::string accNumber = this->dbContext->AddBankAccount(idn, deposit);

	IOService::WriteLine("Bank account created successfully!");
	IOService::WriteLine("Account number: " + accNumber);
}

void BankEmployee::DeleteBankAccount()
{
	std::string idn, accountNumber;
	IOService::ReadString("Input client's UID:", idn);
	IOService::ReadString("Input account number:", accountNumber);

	this->dbContext->DeleteBankAccount(idn, accountNumber);

	IOService::WriteLine("Account deleted successfully!");
}

void BankEmployee::CreateCard()
{
	std::string idn, bankAccount;
	IOService::ReadString("Input client's UID:", idn);
	IOService::ReadString("Input bank account:", bankAccount);

	std::string cardAndPin = this->dbContext->AddCard(idn, bankAccount);

	IOService::WriteLine("Card created successfully!");
	IOService::WriteLine("Card number and PIN: " + cardAndPin);
}

void BankEmployee::DeleteCard()
{
	std::string idn, cardNumber;
	IOService::ReadString("Input client's UID:", idn);
	IOService::ReadString("Input card number:", cardNumber);

	this->dbContext->DeleteCard(idn, cardNumber);

	IOService::WriteLine("Card deleted successfully");
}

void BankEmployee::AllClientsReport()
{
	IOService::WriteLine(this->dbContext->AllClientsReport());
}

void BankEmployee::IndividualClientReport()
{
	std::string idn;
	IOService::ReadString("Input client's UID:", idn);

	IOService::WriteLine(this->dbContext->IndividualClientReport(idn));
}

std::string BankEmployee::ToEscapedString()
{
	return this->authorizationKey + " " + this->authorizationPassword + " " + Person::ToEscapedString();
}
