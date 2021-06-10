#pragma once
#include "LoggedInCommand.h"
#include <User/BankEmployee.h>

class IndividualReportCommand : public LoggedInCommand
{
public:
	virtual std::string GetCommandName() { return "individualReport"; }
	virtual void execute(SystemAccount* acc)
	{
		BankEmployee* emp = dynamic_cast<BankEmployee*>(acc);
		emp->IndividualClientReport();
	}
};