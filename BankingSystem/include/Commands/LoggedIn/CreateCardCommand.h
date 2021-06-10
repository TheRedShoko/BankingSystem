#pragma once
#include "LoggedInCommand.h"
#include <User/BankEmployee.h>

class CreateCardCommand : public LoggedInCommand
{
public:
	virtual std::string GetCommandName() { return "createCard"; }
	virtual void execute(SystemAccount* acc)
	{
		BankEmployee* emp = dynamic_cast<BankEmployee*>(acc);
		emp->CreateCard();
	}
};