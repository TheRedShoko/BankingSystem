#pragma once
#include "LoggedInCommand.h"
#include <User/BankEmployee.h>

class CreateBankAccountCommand : public LoggedInCommand
{
public:
	virtual std::string GetCommandName() { return "createBankAccount"; }
	virtual void execute(SystemAccount* acc)
	{
		BankEmployee* emp = dynamic_cast<BankEmployee*>(acc);
		emp->CreateBankAccount();
	}
};