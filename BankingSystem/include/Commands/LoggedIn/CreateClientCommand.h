#pragma once
#include "LoggedInCommand.h"
#include <User/BankEmployee.h>

class CreateClientCommand : public LoggedInCommand
{
public:
	CreateClientCommand() : LoggedInCommand("createClient") {};
	virtual void execute(SystemAccount* acc)
	{
		BankEmployee* emp = dynamic_cast<BankEmployee*>(acc);
		emp->CreateClient();
	}
};