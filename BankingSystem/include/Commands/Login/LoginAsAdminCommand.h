#pragma once
#include <Commands/Invoker.h>

class LoginAsAdminCommand
{
public:
	void execute(Invoker* inv)
	{
		inv->loginService->LoginAsAdmin(inv);
	}
};