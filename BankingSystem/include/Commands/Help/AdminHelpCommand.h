#pragma once
#include "HelpCommand.h"
#include <Services/IOService.h>

class AdminHelpCommand : public HelpCommand
{
public:
	void execute() override
	{
		IOService::WriteLine("Available commands:");
		IOService::WriteLine("help - displays the current menu");
		IOService::WriteLine("logout - log out from the system");
		IOService::WriteLine("createEmployee - registers new employee to the system");
		IOService::WriteLine("deleteEmployee - deletes employee from the system");
	}
};