#pragma once
#include "LoggedInCommand.h"
#include <User/Client.h>

class CheckBalanceCommand : public LoggedInCommand
{
public:
	virtual std::string GetCommandName() { return "checkBalance"; }
	virtual void execute(SystemAccount* acc) 
	{
		Client* cl = dynamic_cast<Client*>(acc);
		cl->CheckBalance();
	}
};