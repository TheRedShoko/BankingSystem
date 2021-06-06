#pragma once
#include <string>

class SystemAccount
{
protected:
	std::string authorizationKey;
	std::string authorizationPassword;
public:
	//virtual bool Login(std::string authorizationKey, std::string authorizationPassword) = 0;
};
