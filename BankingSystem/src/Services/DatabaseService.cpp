#include "Services/DatabaseService.h"
#include <filesystem>
#include <sstream>
void DatabaseService::LoadClientsFromFile()
{
	FileService clientsFile(this->clientsFile);

	std::string line;
	while (clientsFile.ReadNextLine(line))
	{
		Client client(line);

		std::string clientDataPath = this->clientsBankAccountsInformation + client.GetIDN();

		FileService clientAccountsFile(clientDataPath + "/accounts.db");

		while (clientAccountsFile.ReadNextLine(line))
		{
			BankAccount account(line);

			client.bankAccounts.push_back(account);
		}

		FileService clientCardsFile(clientDataPath + "/cards.db");

		while (clientCardsFile.ReadNextLine(line))
		{
			BankCard card(line);

			for (auto jt = client.bankAccounts.begin(); jt < client.bankAccounts.end(); jt++)
			{
				if (*jt == card.accountNumber)
				{
					jt->AddCard(card);
				}
			}
		}

		this->clients.push_back(client);
	}
}

void DatabaseService::LoadEmployeesFromFile()
{
	FileService employeesFile(this->employeesFile);

	std::string line;
	while (employeesFile.ReadNextLine(line))
	{
		BankEmployee employee(line);
		this->employees.push_back(employee);
	}
}

void DatabaseService::LoadAdministratorsFromFile()
{
	FileService adminsFile(this->adminsFile);

	std::string line;
	while (adminsFile.ReadNextLine(line))
	{
		Administrator admin(line);
		this->admins.push_back(admin);
	}

	if (this->admins.size() == 0)
	{
		this->AddAdministrator("admin", "admin");
	}
}

void DatabaseService::SaveClientsToFile()
{
	FileService clFile(this->clientsFile, std::ios::out | std::ios::trunc);

	for (auto it = this->clients.begin(); it < this->clients.end(); it++)
	{
		clFile.WriteLine(it->ToEscapedString());

		std::string clientDataPath = this->clientsBankAccountsInformation + it->idn;

		std::filesystem::create_directories(clientDataPath);
		FileService clientAccountsFile(clientDataPath + "/accounts.db", std::ios::out | std::ios::trunc);
		FileService clientCardsFile(clientDataPath + "/cards.db", std::ios::out | std::ios::trunc);

		for (auto jt = it->bankAccounts.begin(); jt < it->bankAccounts.end(); jt++)
		{
			clientAccountsFile.WriteLine(jt->ToString());

			for (auto kt = jt->cards.begin(); kt < jt->cards.end(); kt++)
			{
				clientCardsFile.WriteLine(kt->ToString());
			}
		}
	}
}

void DatabaseService::SaveEmployeesToFile()
{
	FileService employeesFile(this->employeesFile, std::ios::out | std::ios::trunc);

	for (auto it = this->employees.begin(); it < this->employees.end(); it++)
	{
		employeesFile.WriteLine(it->ToEscapedString());
	}
}

void DatabaseService::SaveAdministratorsToFile()
{
	FileService adminsFile(this->adminsFile, std::ios::out | std::ios::trunc);

	for (auto it = this->admins.begin(); it < this->admins.end(); it++)
	{
		adminsFile.WriteLine(it->ToString());
	}
}

DatabaseService::~DatabaseService()
{
	this->SaveAdministratorsToFile();
	this->SaveEmployeesToFile();
	this->SaveClientsToFile();
}

DatabaseService::DatabaseService()
{
	this->LoadAdministratorsFromFile();
	this->LoadClientsFromFile();
	this->LoadEmployeesFromFile();
}

void DatabaseService::AddAdministrator(std::string username, std::string password)
{
	for (auto it = this->admins.begin(); it < this->admins.end(); it++)
	{
		if (username == it->GetUsername())
		{
			throw new std::exception("Administrator with the given Username already exists!");
		}
	}

	// Hash password
	this->admins.push_back(Administrator(username, password));
}

void DatabaseService::AddEmployee(std::string username, std::string password, std::string idn, std::string firstName, std::string middleName, std::string lastName, std::string dateOfBirth, std::string phoneNumber, std::string address)
{
	for (auto it = this->employees.begin(); it < this->employees.end(); it++)
	{
		if (idn == it->GetIDN())
		{
			throw new std::exception("Employee with the given IDN already exists!");
		}

		if (username == it->GetUsername())
		{
			throw new std::exception("Employee with the given Username already exists!");
		}
	}

	// Hash password
	BankEmployee employee(username, password, idn, firstName, middleName, lastName, dateOfBirth, phoneNumber, address);
	this->employees.push_back(employee);
}

void DatabaseService::DeleteEmployee(std::string idn)
{
	for (auto it = this->employees.begin(); it < this->employees.end(); it++)
	{
		if (it->GetIDN() == idn)
		{
			this->employees.erase(it);
			return;
		}
	}

	throw std::exception("Employee with the given IDN not found!");
}

void DatabaseService::AddClient(std::string idn, std::string firstName, std::string middleName, std::string lastName, std::string dateOfBirth, std::string phoneNumber, std::string address)
{
	for (auto it = this->clients.begin(); it < this->clients.end(); it++)
	{
		if (idn == it->idn)
		{
			throw new std::exception("Client with the given IDN already exists!");
		}
	}

	Client client(idn, firstName, middleName, lastName, dateOfBirth, phoneNumber, address);
	this->clients.push_back(client);
}

void DatabaseService::DeleteClient(std::string idn)
{
	for (auto it = this->clients.begin(); it < this->clients.end(); it++)
	{
		if (it->idn == idn)
		{
			this->clients.erase(it);
			return;
		}
	}

	throw std::exception("Client with the given IDN not found!");
}

std::string DatabaseService::AddBankAccount(std::string idn, double deposit)
{
	for (auto it = this->clients.begin(); it < this->clients.end(); it++)
	{
		if (it->GetIDN() == idn)
		{
			std::string accNumber = "00MYBANK" + it->idn.substr(6) + std::to_string(it->totalNumberOfAccounts);
			it->bankAccounts.push_back(BankAccount(accNumber, deposit));
			it->totalNumberOfAccounts++;

			return accNumber;
		}
	}

	throw std::exception("Client with the given IDN not found!");
}

void DatabaseService::DeleteBankAccount(std::string idn, std::string account)
{
	for (auto it = this->clients.begin(); it < this->clients.end(); it++)
	{
		if (it->idn == idn)
		{
			for (auto jt = it->bankAccounts.begin(); jt < it->bankAccounts.end(); jt++)
			{
				if (*jt == account)
				{
					it->bankAccounts.erase(jt);
					return;
				}
			}

			throw std::exception("The client with the given UID does not have bank account with the given number!");
		}
	}

	throw std::exception("Client with the given UID not found!");
}

std::string generateFourDigitPIN()
{
	std::string result("0000");
	srand((int)time(nullptr));

	for (size_t i = 0; i < 4; i++)
	{
		result[i] = '0' + (rand() % 10);
	}

	return result;
}

std::string DatabaseService::AddCard(std::string idn, std::string account)
{
	for (auto it = this->clients.begin(); it < this->clients.end(); it++)
	{
		if (it->idn == idn)
		{
			for (auto jt = it->bankAccounts.begin(); jt < it->bankAccounts.end(); jt++)
			{
				if (*jt == account)
				{
					std::string cardNumber = "00" + it->idn.substr(6) + std::to_string(it->totalNumberOfCards);
					std::string pin = generateFourDigitPIN();
					jt->AddCard(BankCard(account, cardNumber, pin));
					it->totalNumberOfCards++;

					return cardNumber + " " + pin;
				}
			}

			throw std::exception("The client with the given UID does not have bank account with the given number!");
		}
	}

	throw std::exception("Client with the given UID not found!");
}

void DatabaseService::DeleteCard(std::string idn, std::string card)
{
	for (auto it = this->clients.begin(); it < this->clients.end(); it++)
	{
		if (it->idn == idn)
		{
			for (auto jt = it->bankAccounts.begin(); jt < it->bankAccounts.end(); jt++)
			{
				for (auto kt = jt->cards.begin(); kt < jt->cards.end(); kt++)
				{
					if (*kt == card)
					{
						jt->cards.erase(kt);
						return;
					}
				}
			}

			throw std::exception("The client with the given UID does not have bank card with the given number!");
		}
	}

	throw std::exception("Client with the given UID not found!");
}

std::string DatabaseService::AllClientsReport()
{
	std::string report = "";

	for (auto it = this->clients.begin(); it < this->clients.end(); it++)
	{
		report += it->idn + " " + std::to_string(it->totalNumberOfAccounts) + " " + std::to_string(it->totalNumberOfCards) + '\n';
	}

	return report;
}

std::string roundAndCastToString(double a)
{
	std::stringstream ss;
	ss << std::fixed << std::setprecision(2) << a;

	return ss.str();
}

std::string DatabaseService::IndividualClientReport(std::string idn)
{
	for (auto it = this->clients.begin(); it < this->clients.end(); it++)
	{
		if (it->idn == idn)
		{
			std::string result = "\n-------Client-------";
			result += "\nUID: " + it->idn
				+ "\nName: " + it->firstName + " " + it->middleName + " " + it->lastName
				+ "\nBirth date: " + it->birthDate.ToString()
				+ "\nPhone number: " + it->phoneNumber
				+ "\nAddress: " + it->address
				+ "\nNumber of accounts: " + std::to_string(it->totalNumberOfAccounts);

			for (auto jt = it->bankAccounts.begin(); jt < it->bankAccounts.end(); jt++)
			{
				result += "\n-------Account " + std::to_string(jt - it->bankAccounts.begin()) + "-------"
					+ "\nAccount number: " + jt->serialNumber
					+ "\nBalance: " + roundAndCastToString(jt->amount)
					+ "\nNumber of cards: " + std::to_string(jt->cards.size());

				for (auto kt = jt->cards.begin(); kt < jt->cards.end(); kt++)
				{
					result += "\n-------Card " + std::to_string(kt - jt->cards.begin()) + "-------"
						+ "\nCard number: " + kt->serialNumber
						+ "\nPIN: " + kt->PIN;
				}
			}

			return result;
		}
	}

	throw std::exception("Client with the given UID not found!");
}

void DatabaseService::DepositBalance(Client* client, double amount)
{
	if (amount <= 0)
	{
		throw std::exception("Invalid amount provided! Must be a positive number!");
	}

	client->loggedInAccount->amount += amount;
}

void DatabaseService::WithdrawBalance(Client* client, double amount)
{
	if (amount <= 0)
	{
		throw std::exception("Invalid amount provided! Must be a positive number!");
	}

	if (client->loggedInAccount->amount < amount)
	{
		throw std::exception("insufficient balance!");
	}

	client->loggedInAccount->amount -= amount;
}
