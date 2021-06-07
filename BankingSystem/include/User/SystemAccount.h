#pragma once
#include <string>

class SystemAccount
{
protected:
	std::string authorizationKey;
	std::string authorizationPassword;
public:
	virtual ~SystemAccount() = default;
	SystemAccount() = default;
	SystemAccount(std::string username, std::string password);
	virtual std::string GetUsername() const;
};

inline SystemAccount::SystemAccount(std::string username, std::string password)
	:authorizationKey(username), authorizationPassword(password)
{
}

inline std::string SystemAccount::GetUsername() const
{
	return this->authorizationKey;
}