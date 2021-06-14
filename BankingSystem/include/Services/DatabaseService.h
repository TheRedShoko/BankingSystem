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
	
	void AddAdministrator(const std::string& username, const std::string& password);

	void AddEmployee(const std::string& username, const std::string& password, const std::string& idn, const std::string& firstName, const std::string& middleName, const std::string& lastName, const std::string& dateOfBirth, const std::string& phoneNumber, const std::string& address);
	void DeleteEmployee(const std::string& idn);

	void AddClient(const std::string& idn, const std::string& firstName, const std::string& middleName, const std::string& lastName, const std::string& dateOfBirth, const std::string& phoneNumber, const std::string& address);
	void DeleteClient(const std::string& idn);
	std::string AddBankAccount(const std::string& idn, double deposit);
	void DeleteBankAccount(const std::string& idn, const std::string& account);
	std::string AddCard(const std::string& idn, const std::string& account);
	void DeleteCard(const std::string& idn, const std::string& card);
	std::string AllClientsReport();
	std::string IndividualClientReport(const std::string& idn);

	void DepositBalance(Client* client, double amount);
	void WithdrawBalance(Client* client, double amount);

	Administrator* GetAdministratorByUsername(const std::string& username);
	BankEmployee* GetEmployeeByUsername(const std::string& username);
	Client* GetClientByCardNumber(const std::string& card);
};

