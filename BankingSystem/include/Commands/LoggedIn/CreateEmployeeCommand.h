#pragma once
#include "LoggedInCommand.h"
#include <User/Administrator.h>

class CreateEmployeeCommand : public LoggedInCommand
{
public:
	virtual std::string GetCommandName() { return "createEmployee"; }
	virtual void execute(SystemAccount* acc)
	{
		Administrator* adm = dynamic_cast<Administrator*>(acc);
		adm->CreateEmployee();
	}
};