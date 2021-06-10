#pragma once
#include <User/SystemAccount.h>

class LoggedInCommand
{
public:
	virtual std::string GetCommandName() = 0;
	virtual void execute(SystemAccount* acc) = 0;
};