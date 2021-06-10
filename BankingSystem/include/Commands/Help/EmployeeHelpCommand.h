#pragma once
#include "HelpCommand.h"
#include "Services/IOService.h"

class EmployeeHelpCommand : public HelpCommand
{
public:
	void execute() override
	{
		IOService::WriteLine("Available commands:");
		IOService::WriteLine("help - displays the current menu");
		IOService::WriteLine("logout - log out from the system");
		IOService::WriteLine("createClient - registers new client to the system");
		IOService::WriteLine("deleteClient - deletes client from the system");
		IOService::WriteLine("createBankAccount - creates new bank account to existing client");
		IOService::WriteLine("deleteBankAccount - deletes existing bank account");
		IOService::WriteLine("createCard - adds new card to given bank account");
		IOService::WriteLine("deleteCard - deletes existing card");
		IOService::WriteLine("getReport - gives summary for all bank's clients");
		IOService::WriteLine("individualReport - gives all information about given client");
	}
};