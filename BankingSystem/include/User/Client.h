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

    BankAccount* loggedInAccount = nullptr;
    std::vector<BankAccount> bankAccounts;
public:
    Client(std::string clientString);
    Client(std::string idn, std::string firstName, std::string middleName, std::string lastName, std::string dateOfBirth, std::string phoneNumber, std::string address);

    void DepositAmount();
    void WithdrawAmount();
    void CheckBalance();


    std::string ToEscapedString() override;
    std::string ToString() override;
};

