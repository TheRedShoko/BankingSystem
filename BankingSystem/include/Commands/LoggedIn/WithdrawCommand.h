#pragma once
#include "LoggedInCommand.h"
#include <User/Client.h>

class WithdrawCommand : public LoggedInCommand
{
public:
	virtual std::string GetCommandName() { return "withdraw"; }
	virtual void execute(SystemAccount* acc)
	{
		Client* cl = dynamic_cast<Client*>(acc);
		cl->WithdrawAmount();
	}
};