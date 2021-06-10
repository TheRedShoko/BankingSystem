#pragma once
#include "LoggedInCommand.h"
#include <User/BankEmployee.h>

class DeleteCardCommand : public LoggedInCommand
{
public:
	virtual std::string GetCommandName() { return "deleteCard"; }
	virtual void execute(SystemAccount* acc)
	{
		BankEmployee* emp = dynamic_cast<BankEmployee*>(acc);
		emp->DeleteCard();
	}
};