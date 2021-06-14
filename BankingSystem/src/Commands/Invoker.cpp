#include "Commands/Invoker.h"
#include "Commands/Login/LogoutCommand.h"
#include "Commands/Login/LoginAsAdminCommand.h"
#include "Commands/Login/LoginAsClientCommand.h"
#include "Commands/Login/LoginAsEmployeeCommand.h"

Invoker::~Invoker()
{
	delete this->dbService;
	delete this->helpCommand;
	delete this->loginService;

	for (auto i = this->allowedCommands.begin(); i < this->allowedCommands.end(); i++)
	{
		delete (*i);
	}
}

void Invoker::Listen()
{
	std::string input;

	while (true)
	{
		IOService::ReadLine(">", input);

		try
		{
			if (input == "exit")
			{
				return;
			}
			else if (input == "help")
			{
				this->helpCommand->execute();
			}
			else if (this->currentAccount == nullptr)
			{
				if (input == "loginAsAdmin")
				{
					LoginAsAdminCommand().execute(this);
				}
				else if (input == "loginAsEmployee")
				{
					LoginAsEmployeeCommand().execute(this);
				}
				else if (input == "loginAsClient")
				{
					LoginAsClientCommand().execute(this);
				}
			}
			else if (this->currentAccount != nullptr)
			{
				if (input == "logout")
				{
					LogoutCommand().execute(this);
				}
				else
				{
					for (auto it = this->allowedCommands.begin(); it < this->allowedCommands.end(); it++)
					{
						if ((*it)->commandName == input)
						{
							(*it)->execute(this->currentAccount);
							break;
						}
					}
				}
			}
		}
		catch (std::exception ex)
		{
			IOService::WriteLine(ex.what());
		}
	}
}
