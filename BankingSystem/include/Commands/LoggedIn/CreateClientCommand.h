#pragma once
#include "LoggedInCommand.h"
#include <User/BankEmployee.h>

class CreateClientCommand : public LoggedInCommand
{
public:
	virtual std::string GetCommandName() { return "createClient"; }
	virtual void execute(SystemAccount* acc)
	{
		BankEmployee* emp = dynamic_cast<BankEmployee*>(acc);
		emp->CreateClient();
	}
};