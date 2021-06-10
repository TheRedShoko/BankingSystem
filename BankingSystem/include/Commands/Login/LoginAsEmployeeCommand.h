#pragma once
#include <Commands/Invoker.h>

class LoginAsEmployeeCommand
{
public:
	void execute(Invoker* inv)
	{
		inv->loginService->LoginAsEmployee(inv);
	}
};