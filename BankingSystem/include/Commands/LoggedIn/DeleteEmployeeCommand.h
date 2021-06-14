#pragma once
#include "LoggedInCommand.h"
#include <User/Administrator.h>

class DeleteEmployeeCommand : public LoggedInCommand
{
public:
	DeleteEmployeeCommand() : LoggedInCommand("deleteEmployee") {};
	virtual void execute(SystemAccount* acc)
	{
		Administrator* emp = dynamic_cast<Administrator*>(acc);
		emp->DeleteEmployee();
	}
};