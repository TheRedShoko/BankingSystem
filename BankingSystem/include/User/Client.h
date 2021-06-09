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

    size_t totalNumberOfAccounts;
    size_t totalNumberOfCards;

    std::vector<BankAccount> bankAccounts;
public:
    Client(std::string clientString);
    Client(std::string idn, std::string firstName, std::string middleName, std::string lastName, std::string dateOfBirth, std::string phoneNumber, std::string address);
       
    void AddBankAccount(BankAccount account);
    void AddNewBankAccount(BankAccount account);
    void AddCardToAccount(std::string account, BankCard card);
    void AddNewCardToAccount(std::string account, BankCard card);

    std::string ToString() override;
};

