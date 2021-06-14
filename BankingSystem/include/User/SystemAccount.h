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
	SystemAccount(const std::string& username, const std::string& password);
	void InjectDbService(DatabaseService* service);
	const std::string& GetUsername() const;
	const std::string& GetPassword() const;
};