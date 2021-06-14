#pragma once
#include "LoggedInCommand.h"
#include <User/BankEmployee.h>

class GetReportCommand : public LoggedInCommand
{
public:
	GetReportCommand() : LoggedInCommand("getReport") {};
	virtual void execute(SystemAccount* acc)
	{
		BankEmployee* emp = dynamic_cast<BankEmployee*>(acc);
		emp->AllClientsReport();
	}
};