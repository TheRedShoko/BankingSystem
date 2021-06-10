#include "Services/LoginService.h"
#include "Commands/Invoker.h"
#include "Services/IOService.h"
#include "Commands/Help/AdminHelpCommand.h"
#include "Commands/Help/ClientHelpCommand.h"
#include "Commands/Help/EmployeeHelpCommand.h"
#include "Commands/LoggedIn/CreateEmployeeCommand.h"
#include "Commands/LoggedIn/CreateBankAccountCommand.h"
#include "Commands/LoggedIn/DeleteBankAccountCommand.h"
#include "Commands/LoggedIn/CreateCardCommand.h"
#include "Commands/LoggedIn/CreateClientCommand.h"
#include "Commands/LoggedIn/DeleteCardCommand.h"
#include "Commands/LoggedIn/DeleteClientCommand.h"
#include "Commands/LoggedIn/GetReportCommand.h"
#include "Commands/LoggedIn/IndividualReportCommand.h"
#include "Commands/LoggedIn/WithdrawCommand.h"
#include "Commands/LoggedIn/DepositCommand.h"
#include "Commands/LoggedIn/CheckBalanceCommand.h"
#include "Commands/LoggedIn/DeleteEmployeeCommand.h"

void LoginService::deleteAllUserData(Invoker* inv)
{
	inv->currentAccount = nullptr;

	for (auto it = inv->allowedCommands.begin(); it < inv->allowedCommands.end(); it++)
	{
		delete (*it);
	}

	inv->allowedCommands.clear();
	delete inv->helpCommand;
}

void LoginService::LoginAsAdmin(Invoker* inv)
{
	std::string username, password;
	IOService::ReadLine("Username:", username);
	IOService::ReadLine("Password:", password);

	Administrator* a = inv->dbService->GetAdministratorByUsername(username);

	if (a == nullptr || a->GetPassword() != password)
	{
		throw std::exception("Invalid username or password!");
	}

	this->deleteAllUserData(inv);

	inv->currentAccount = a;
	a->InjectDbService(inv->dbService);

	inv->helpCommand = new AdminHelpCommand();

	inv->allowedCommands.push_back(new CreateEmployeeCommand());
	inv->allowedCommands.push_back(new DeleteEmployeeCommand());

	IOService::WriteLine("Successfully logged in as admin!");
}

void LoginService::LoginAsEmployee(Invoker* inv)
{
	std::string username, password;
	IOService::ReadLine("Username:", username);
	IOService::ReadLine("Password:", password);

	BankEmployee* emp = inv->dbService->GetEmployeeByUsername(username);

	if (emp == nullptr || emp->GetPassword() != password)
	{
		throw std::exception("Invalid username or password!");
	}

	this->deleteAllUserData(inv);

	inv->currentAccount = emp;
	emp->InjectDbService(inv->dbService);

	inv->helpCommand = new EmployeeHelpCommand();

	inv->allowedCommands.push_back(new CreateBankAccountCommand());
	inv->allowedCommands.push_back(new DeleteBankAccountCommand());
	inv->allowedCommands.push_back(new CreateCardCommand());
	inv->allowedCommands.push_back(new CreateClientCommand());
	inv->allowedCommands.push_back(new DeleteCardCommand());
	inv->allowedCommands.push_back(new DeleteClientCommand());
	inv->allowedCommands.push_back(new GetReportCommand());
	inv->allowedCommands.push_back(new IndividualReportCommand());

	IOService::WriteLine("Successfully logged in as employee!");
}

void LoginService::LoginAsClient(Invoker* inv)
{
	std::string cardNumber, pin;
	IOService::ReadLine("Card number:", cardNumber);
	IOService::ReadLine("PIN:", pin);

	Client* cl = inv->dbService->GetClientByCardNumber(cardNumber);

	if (cl == nullptr || cl->GetPassword() != pin)
	{
		throw std::exception("Invalid card number or PIN!");
	}

	this->deleteAllUserData(inv);

	inv->currentAccount = cl;
	cl->InjectDbService(inv->dbService);

	inv->helpCommand = new ClientHelpCommand();

	inv->allowedCommands.push_back(new CheckBalanceCommand());
	inv->allowedCommands.push_back(new DepositCommand());
	inv->allowedCommands.push_back(new WithdrawCommand());

	IOService::WriteLine("Successfully logged in as client!");
}

void LoginService::Logout(Invoker* inv)
{
	this->deleteAllUserData(inv);
	inv->helpCommand = new UnloggedHelpCommand();
}
