#pragma once
#include <Commands/Invoker.h>

class LogoutCommand
{
public:
	void execute(Invoker* inv)
	{
		inv->loginService->Logout(inv);
	}
};