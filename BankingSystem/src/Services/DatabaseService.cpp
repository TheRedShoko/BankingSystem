#include "Services/DatabaseService.h"

void DatabaseService::LoadClientsFromFile()
{
    FileService clientsFile(this->clientsFile);

    std::string line;
    while (clientsFile.ReadNextLine(line))
    {
        Client client(line);
    }
}

void DatabaseService::LoadEmployeesFromFile()
{
}

DatabaseService::DatabaseService()
{
    this->LoadClientsFromFile();
    this->LoadEmployeesFromFile();
}
