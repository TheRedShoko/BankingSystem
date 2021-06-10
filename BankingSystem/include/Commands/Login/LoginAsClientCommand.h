#pragma once
#include <Commands/Invoker.h>

class LoginAsClientCommand
{
public:
	void execute(Invoker* inv)
	{
		inv->loginService->LoginAsClient(inv);
	}
};