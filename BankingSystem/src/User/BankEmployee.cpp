#include "User/BankEmployee.h"

std::string BankEmployee::ToString()
{
	return this->authorizationKey + " " + this->authorizationPassword + " " + Person::ToString();
}