#include "User/SystemAccount.h"

SystemAccount::SystemAccount(std::string username, std::string password)
	:authorizationKey(username), authorizationPassword(password)
{
}

void SystemAccount::InjectDbService(DatabaseService* service)
{
	this->dbContext = service;
}

std::string SystemAccount::GetUsername() const
{
	return this->authorizationKey;
}

std::string SystemAccount::GetPassword() const
{
	return this->authorizationPassword;
}
