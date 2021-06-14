#pragma once
#include "LoggedInCommand.h"
#include <User/BankEmployee.h>

class DeleteClientCommand : public LoggedInCommand
{
public:
	DeleteClientCommand() : LoggedInCommand("deleteClient") {};
	virtual void execute(SystemAccount* acc)
	{
		BankEmployee* emp = dynamic_cast<BankEmployee*>(acc);
		emp->DeleteClient();
	}
};