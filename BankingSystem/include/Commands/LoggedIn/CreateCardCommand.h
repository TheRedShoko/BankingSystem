#pragma once
#include "LoggedInCommand.h"
#include <User/BankEmployee.h>

class CreateCardCommand : public LoggedInCommand
{
public:
	CreateCardCommand() : LoggedInCommand("createCard") {};
	virtual void execute(SystemAccount* acc)
	{
		BankEmployee* emp = dynamic_cast<BankEmployee*>(acc);
		emp->CreateCard();
	}
};