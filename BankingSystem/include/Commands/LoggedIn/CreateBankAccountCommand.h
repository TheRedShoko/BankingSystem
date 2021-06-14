#pragma once
#include "LoggedInCommand.h"
#include <User/BankEmployee.h>

class CreateBankAccountCommand : public LoggedInCommand
{
public:
	CreateBankAccountCommand() : LoggedInCommand("createBankAccount") {};
	virtual void execute(SystemAccount* acc)
	{
		BankEmployee* emp = dynamic_cast<BankEmployee*>(acc);
		emp->CreateBankAccount();
	}
};