#pragma once
#include "LoggedInCommand.h"
#include <User/BankEmployee.h>

class IndividualReportCommand : public LoggedInCommand
{
public:
	IndividualReportCommand() : LoggedInCommand("individualReport") {};
	virtual void execute(SystemAccount* acc)
	{
		BankEmployee* emp = dynamic_cast<BankEmployee*>(acc);
		emp->IndividualClientReport();
	}
};