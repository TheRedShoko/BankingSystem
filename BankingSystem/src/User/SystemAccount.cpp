#include "User/SystemAccount.h"

SystemAccount::SystemAccount(const std::string& username, const std::string& password)
	:authorizationKey(username), authorizationPassword(password)
{
}

void SystemAccount::InjectDbService(DatabaseService* service)
{
	this->dbContext = service;
}

const std::string& SystemAccount::GetUsername() const
{
	return this->authorizationKey;
}

const std::string& SystemAccount::GetPassword() const
{
	return this->authorizationPassword;
}
