#pragma once
#include "Person.h"
#include "SystemAccount.h"

class Client :
    public Person, public SystemAccount
{
private:
    void parseClientFromString(std::string s);
public:
    Client(std::string clientString);
};

