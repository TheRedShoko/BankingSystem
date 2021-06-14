#pragma once
#include "LoggedInCommand.h"
#include <User/Administrator.h>

class CreateEmployeeCommand : public LoggedInCommand
{
public:
	CreateEmployeeCommand() : LoggedInCommand("createEmployee") {};
	virtual void execute(SystemAccount* acc)
	{
		Administrator* adm = dynamic_cast<Administrator*>(acc);
		adm->CreateEmployee();
	}
};