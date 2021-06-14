#pragma once
#include "Person.h"
#include "SystemAccount.h"
#include "BankAccount.h"

class Client :
    public Person, public SystemAccount
{
private:
    friend class DatabaseService;
    
    void parseClientFromString(const std::string& s);

    size_t totalNumberOfAccounts;
    size_t totalNumberOfCards;

    BankAccount* loggedInAccount = nullptr;
    std::vector<BankAccount> bankAccounts;
public:
    Client(const std::string& clientString);
    Client(const std::string& idn, const std::string& firstName, const std::string& middleName, const std::string& lastName, const std::string& dateOfBirth, const std::string& phoneNumber, const std::string& address);

    void DepositAmount();
    void WithdrawAmount();
    void CheckBalance();


    std::string ToEscapedString() override;
    std::string ToString() override;
};

