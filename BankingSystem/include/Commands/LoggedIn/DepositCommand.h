#pragma once
#include "LoggedInCommand.h"
#include <User/Client.h>

class DepositCommand : public LoggedInCommand
{
public:
	virtual std::string GetCommandName() { return "deposit"; }
	virtual void execute(SystemAccount* acc)
	{
		Client* cl = dynamic_cast<Client*>(acc);
		cl->DepositAmount();
	}
};