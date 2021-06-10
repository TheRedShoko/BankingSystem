#pragma once
#include "LoggedInCommand.h"
#include <User/Administrator.h>

class DeleteEmployeeCommand : public LoggedInCommand
{
public:
	virtual std::string GetCommandName() { return "deleteEmployee"; }
	virtual void execute(SystemAccount* acc)
	{
		Administrator* emp = dynamic_cast<Administrator*>(acc);
		emp->DeleteEmployee();
	}
};