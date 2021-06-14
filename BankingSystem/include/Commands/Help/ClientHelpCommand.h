#pragma once
#include "HelpCommand.h"
#include <Services/IOService.h>

class ClientHelpCommand : public HelpCommand
{
public:
	void execute() override
	{
		IOService::WriteLine("Available commands:");
		IOService::WriteLine("exit - quit the application");
		IOService::WriteLine("help - displays the current menu");
		IOService::WriteLine("logout - log out from the system");
		IOService::WriteLine("deposit - deposit given amount in your current bank account");
		IOService::WriteLine("withdraw - withdraw from your current bank account");
		IOService::WriteLine("checkBalance - check the balance in your current bank account");
	}
};