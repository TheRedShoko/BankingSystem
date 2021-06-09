#pragma once
#include <string>

class DatabaseService;

class SystemAccount
{
protected:
	DatabaseService* dbContext = nullptr;

	std::string authorizationKey;
	std::string authorizationPassword;
public:
	virtual ~SystemAccount() = default;
	SystemAccount() = default;
	SystemAccount(std::string username, std::string password);
	void InjectDbService(DatabaseService& service);
	virtual std::string GetUsername() const;
};