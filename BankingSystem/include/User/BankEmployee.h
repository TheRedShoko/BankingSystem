#pragma once
#include "Person.h"
#include "SystemAccount.h"

class BankEmployee : public Person, public SystemAccount
{
public:
	std::string ToString() override;
};