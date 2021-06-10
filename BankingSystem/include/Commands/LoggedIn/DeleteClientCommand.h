#pragma once
#include "LoggedInCommand.h"
#include <User/BankEmployee.h>

class DeleteClientCommand : public LoggedInCommand
{
public:
	virtual std::string GetCommandName() { return "deleteClient"; }
	virtual void execute(SystemAccount* acc)
	{
		BankEmployee* emp = dynamic_cast<BankEmployee*>(acc);
		emp->DeleteClient();
	}
};