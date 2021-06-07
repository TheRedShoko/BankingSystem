#include "Services/DatabaseService.h"
#include <filesystem>

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

            client.AddBankAccount(account);
        }

        FileService clientCardsFile(clientDataPath + "/cards.db");

        while (clientCardsFile.ReadNextLine(line))
        {
            BankCard card(line);
            
            client.AddCardToAccount(card.GetAccountNumber(), card);
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

    for (size_t i = 0; i < this->clients.size(); i++)
    {
        clFile.WriteLine(this->clients[i].ToEscapedString());

        std::string clientDataPath = this->clientsBankAccountsInformation + this->clients[i].GetIDN();

        std::filesystem::create_directories(clientDataPath);
        FileService clientAccountsFile(clientDataPath + "/accounts.db", std::ios::out | std::ios::trunc);
        FileService clientCardsFile(clientDataPath + "/cards.db", std::ios::out | std::ios::trunc);
        
        for (size_t j = 0; j < this->clients[i].bankAccounts.size(); j++)
        {
            clientAccountsFile.WriteLine(this->clients[i].bankAccounts[j].ToString());

            for (size_t k = 0; k < this->clients[i].bankAccounts[j].cards.size(); k++)
            {
                clientCardsFile.WriteLine(this->clients[i].bankAccounts[j].cards[k].ToString());
            }
        }
    }
}

void DatabaseService::SaveEmployeesToFile()
{
    FileService employeesFile(this->employeesFile, std::ios::out | std::ios::trunc);

    for (size_t i = 0; i < this->employees.size(); i++)
    {
        employeesFile.WriteLine(this->employees[i].ToEscapedString());
    }
}

void DatabaseService::SaveAdministratorsToFile()
{
    FileService adminsFile(this->adminsFile, std::ios::out | std::ios::trunc);

    for (size_t i = 0; i < this->admins.size(); i++)
    {
        adminsFile.WriteLine(this->admins[i].ToString());
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
    for (size_t i = 0; i < this->admins.size(); i++)
    {
        if (username == this->admins[i].GetUsername())
        {
            throw new std::exception("Administrator with the given Username already exists!");
        }
    }

    // Hash password
    this->admins.push_back(Administrator(username, password));
}

void DatabaseService::AddEmployee(std::string username, std::string password, std::string idn, std::string firstName, std::string middleName, std::string lastName, std::string dateOfBirth, std::string phoneNumber, std::string address)
{
    for (size_t i = 0; i < this->employees.size(); i++)
    {
        if (idn == this->employees[i].GetIDN())
        {
            throw new std::exception("Employee with the given IDN already exists!");
        }

        if (username == this->employees[i].GetUsername())
        {
            throw new std::exception("Employee with the given Username already exists!");
        }
    }

    // Hash password
    BankEmployee employee(username, password, idn, firstName, middleName, lastName, dateOfBirth, phoneNumber, address);
    this->employees.push_back(employee);
}
