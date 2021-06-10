#pragma once
#include "Services/DatabaseService.h"
#include "Services/LoginService.h"
#include "Help/HelpCommand.h"
#include "Help/UnloggedHelpCommand.h"
#include <Commands/LoggedIn/LoggedInCommand.h>

class Invoker
{
	friend class LogoutCommand;
	friend class LoginService;
	friend class LoginAsAdminCommand;
	friend class LoginAsEmployeeCommand;
	friend class LoginAsClientCommand;
private:
	DatabaseService* dbService = new DatabaseService();
	LoginService* loginService = new LoginService();

	SystemAccount* currentAccount = nullptr;

	HelpCommand* helpCommand = new UnloggedHelpCommand();

	std::vector<LoggedInCommand*> allowedCommands;
public:
	~Invoker();

	void Listen();
};