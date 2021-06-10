#pragma once
#include "LoggedInCommand.h"
#include <User/BankEmployee.h>

class DeleteBankAccountCommand : public LoggedInCommand
{
public:
	virtual std::string GetCommandName() { return "deleteBankAccount"; }
	virtual void execute(SystemAccount* acc)
	{
		BankEmployee* emp = dynamic_cast<BankEmployee*>(acc);
		emp->DeleteBankAccount();
	}
};