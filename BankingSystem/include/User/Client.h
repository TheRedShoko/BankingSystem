#pragma once
#include "Person.h"
#include "SystemAccount.h"
#include "BankAccount.h"

class Client :
    public virtual Person, public virtual SystemAccount
{
private:
    friend class DatabaseService;
    
    void parseClientFromString(std::string s);

    std::vector<BankAccount> bankAccounts;
public:
    Client(std::string clientString);
    
    void AddBankAccount(BankAccount account);
    void AddCardToAccount(std::string account, BankCard card);
};

