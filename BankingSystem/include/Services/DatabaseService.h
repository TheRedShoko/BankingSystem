#pragma once
#include <Services/FileService.h>
#include <vector>
#include <User/Client.h>
#include <User/BankEmployee.h>
class DatabaseService
{
private:
	const std::string employeesFile = "./data/employees.db";
	const std::string clientsFile = "./data/clients.db";
	const std::string clientsBankAccountsInformation = "./data/";

	std::vector<Client> clients;
	std::vector<BankEmployee> employees;

	void LoadClientsFromFile();
	void LoadEmployeesFromFile();
public:
	DatabaseService();
};

