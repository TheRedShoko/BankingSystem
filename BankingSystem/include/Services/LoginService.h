#pragma once
#include "DatabaseService.h"

class Invoker;

class LoginService
{
private:
	void deleteAllUserData(Invoker* inv);
public:
	void LoginAsAdmin(Invoker* inv);
	void LoginAsEmployee(Invoker* inv);
	void LoginAsClient(Invoker* inv);
	void Logout(Invoker* inv);
};