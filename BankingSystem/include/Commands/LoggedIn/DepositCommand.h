#pragma once
#include "LoggedInCommand.h"
#include <User/Client.h>

class DepositCommand : public LoggedInCommand
{
public:
	DepositCommand() : LoggedInCommand("deposit") {};
	virtual void execute(SystemAccount* acc)
	{
		Client* cl = dynamic_cast<Client*>(acc);
		cl->DepositAmount();
	}
};