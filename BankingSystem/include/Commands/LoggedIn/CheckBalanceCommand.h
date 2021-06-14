#pragma once
#include "LoggedInCommand.h"
#include <User/Client.h>

class CheckBalanceCommand : public LoggedInCommand
{
public:
	CheckBalanceCommand() : LoggedInCommand("checkBalance") {};
	virtual void execute(SystemAccount* acc) 
	{
		Client* cl = dynamic_cast<Client*>(acc);
		cl->CheckBalance();
	}
};