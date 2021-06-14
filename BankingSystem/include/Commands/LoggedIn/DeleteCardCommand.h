#pragma once
#include "LoggedInCommand.h"
#include <User/BankEmployee.h>

class DeleteCardCommand : public LoggedInCommand
{
public:
	DeleteCardCommand() : LoggedInCommand("deleteCard") {};
	virtual void execute(SystemAccount* acc)
	{
		BankEmployee* emp = dynamic_cast<BankEmployee*>(acc);
		emp->DeleteCard();
	}
};