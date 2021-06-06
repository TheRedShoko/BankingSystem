#include "User/Administrator.h"

std::string Administrator::ToString() const
{
	return this->authorizationKey + " " + this->authorizationPassword;
}
