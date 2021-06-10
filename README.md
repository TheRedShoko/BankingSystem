# BankingSystem
A project for the OOP course in FMI Sofia University

The project focuses on the implementation of banking software. The system has a console interface, and communication with the user is done through commands. The software allows the average user to check their account balance and make transactions. The software product also requires the bank's employees - to manage the accounts of ordinary users and to issue reports, and the system administrators - to manage the employees' accounts.

# Commands

###Available for everyone
**help** - displays information for all available commands

###Available when not logged in
**loginAsClient** - log in as client
**loginAsAdmin** - log in as system administrator");"logout - log out from the system
**loginAsEmployee** - log in as bank employee");"deposit - deposit given amount in your current bank account

###Available when logged in as client
**deposit** - deposit given amount in your current bank account
**withdraw** - withdraw from your current bank account
**checkBalance** - check the balance in your current bank account
**logout** - log out from the system

###Available when logged in as employee
**createClient** - registers new client to the system
**deleteClient** - deletes client from the system
**createBankAccount** - creates new bank account to existing client
**deleteBankAccount** - deletes existing bank account
**createCard** - adds new card to given bank account
**deleteCard** - deletes existing card
**getReport** - gives summary for all bank's clients
**individualReport** - gives all information about given client
**logout** - log out from the system

###Available when logged in as admin
**createEmployee** - registers new employee to the system
**deleteEmployee** - deletes employee from the system
**logout** - log out from the system