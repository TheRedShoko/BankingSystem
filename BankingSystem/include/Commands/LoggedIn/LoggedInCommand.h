#pragma once
#include <User/SystemAccount.h>

class LoggedInCommand
{
public:
	LoggedInCommand(const char* name) : commandName(name) {};
	const std::string commandName;
	virtual void execute(SystemAccount* acc) = 0;
};