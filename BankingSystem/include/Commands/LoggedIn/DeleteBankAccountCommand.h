#pragma once
#include "LoggedInCommand.h"
#include <User/BankEmployee.h>

class DeleteBankAccountCommand : public LoggedInCommand
{
public:
	DeleteBankAccountCommand() : LoggedInCommand("deleteBankAccount") {};
	virtual void execute(SystemAccount* acc)
	{
		BankEmployee* emp = dynamic_cast<BankEmployee*>(acc);
		emp->DeleteBankAccount();
	}
};