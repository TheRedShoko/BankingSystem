#include "User/Administrator.h"
#include <iostream>
#include "Services/IOService.h"
#include "Services/DatabaseService.h"


void Administrator::parseFromString(std::string s)
{
	size_t delim = s.find(" ");
	this->authorizationKey = s.substr(0, delim);
	this->authorizationPassword = s.substr(delim + 1);
}

Administrator::Administrator(std::string username, std::string password)
{
	this->authorizationKey = username;
	this->authorizationPassword = password;
}

Administrator::Administrator(std::string from_string)
{
	this->parseFromString(from_string);
}

void Administrator::CreateEmployee() const
{
	std::string username, password, idn, firstName, middleName, lastName, dateOfBirth, phoneNumber, address;

	IOService::ReadString("Input username:", username);
	IOService::ReadString("Input password:", password);
	IOService::ReadString("Input UID:", idn);
	IOService::ReadLine("Input First name:", firstName);
	IOService::ReadLine("Input Middle name:", middleName);
	IOService::ReadLine("Input Last name:", lastName);
	IOService::ReadString("Input date of birth (dd/MM/yyyy):", dateOfBirth);
	IOService::ReadString("Input phone number:", phoneNumber);
	IOService::ReadLine("Input address:", address);

	this->dbContext->AddEmployee(username, password, idn, firstName, middleName, lastName, dateOfBirth, phoneNumber, address);

	IOService::WriteLine("Employee added successfully!");
}

void Administrator::DeleteEmployee() const
{
	std::string idn;
	IOService::ReadString("Input UID:", idn);

	this->dbContext->DeleteEmployee(idn);

	IOService::WriteLine("Employee deleted successfuly!");
}

std::string Administrator::ToString() const
{
	return this->authorizationKey + " " + this->authorizationPassword;
}
