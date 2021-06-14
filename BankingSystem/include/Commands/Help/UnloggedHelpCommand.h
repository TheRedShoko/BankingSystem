#pragma once
#include "HelpCommand.h"
#include "Services/IOService.h"

class UnloggedHelpCommand : public HelpCommand
{
public:
	void execute() override
	{
		IOService::WriteLine("Available commands:");
		IOService::WriteLine("exit - quit the application");
		IOService::WriteLine("help - displays the current menu");
		IOService::WriteLine("loginAsClient - log in as client");
		IOService::WriteLine("loginAsAdmin - log in as system administrator");
		IOService::WriteLine("loginAsEmployee - log in as bank employee");
	}
};