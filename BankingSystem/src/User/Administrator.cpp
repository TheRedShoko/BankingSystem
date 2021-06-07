#include "User/Administrator.h"
#include <iostream>


void Administrator::parseFromString(std::string s)
{
	size_t delim = s.find(" ");
	this->authorizationKey = s.substr(0, delim);
	this->authorizationPassword = std::stod(s.substr(delim + 1));
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

BankEmployee Administrator::CreateEmployee() const
{
	std::string username, password, idn, firstName, middleName, lastName, dateOfBirth, phoneNumber, address;

	// TODO: Dependency
	std::cout << "Input username: ";
	std::cin >> username;

	std::cout << "Input password: ";
	std::cin >> password;

	std::cout << "Input UID: ";
	std::cin >> idn;

	std::cin.ignore();

	std::cout << "Input First name: ";
	getline(std::cin, firstName);
	
	std::cout << "Input Middle name: ";
	getline(std::cin, middleName);

	std::cout << "Input Last name: ";
	getline(std::cin, lastName);

	std::cout << "Input date of birth (dd/MM/yyyy): ";
	std::cin >> dateOfBirth;

	std::cout << "Input phone number: ";
	std::cin >> phoneNumber;
	
	std::cin.ignore();

	std::cout << "Input address: ";
	getline(std::cin, address);

	// TODO
	return BankEmployee("");
}

std::string Administrator::ToString() const
{
	return this->authorizationKey + " " + this->authorizationPassword;
}
