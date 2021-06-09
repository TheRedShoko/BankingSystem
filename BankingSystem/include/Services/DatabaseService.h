#pragma once
#include "Services/FileService.h"
#include <vector>
#include "User/Client.h"
#include "User/BankEmployee.h"
#include "User/Administrator.h"
class DatabaseService
{
private:
	const std::string employeesFile = "./data/employees.db";
	const std::string clientsFile = "./data/clients.db";
	const std::string adminsFile = "./data/admins.db";
	const std::string clientsBankAccountsInformation = "./data/";

	std::vector<Client> clients;
	std::vector<BankEmployee> employees;
	std::vector<Administrator> admins;

	void LoadClientsFromFile();
	void LoadEmployeesFromFile();
	void LoadAdministratorsFromFile();

	void SaveClientsToFile();
	void SaveEmployeesToFile();
	void SaveAdministratorsToFile();
public:
	~DatabaseService();
	DatabaseService();
	
	void AddAdministrator(std::string username, std::string password);

	void AddEmployee(std::string username, std::string password, std::string idn, std::string firstName, std::string middleName, std::string lastName, std::string dateOfBirth, std::string phoneNumber, std::string address);
	void DeleteEmployee(std::string idn);

	void AddClient(std::string idn, std::string firstName, std::string middleName, std::string lastName, std::string dateOfBirth, std::string phoneNumber, std::string address);
	void DeleteClient(std::string idn);
	std::string AddBankAccount(std::string idn, double deposit);
	void DeleteBankAccount(std::string idn, std::string account);
	std::string AddCard(std::string idn, std::string account);
	void DeleteCard(std::string idn, std::string card);
	std::string AllClientsReport();
	std::string IndividualClientReport(std::string idn);
};

