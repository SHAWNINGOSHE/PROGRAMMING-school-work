/*
Title:inheritance demonstration class time
Author:Shawn Ingoshe
Reg no:BSE-05-0199/2024
*/

#include <iostream>
#include <string>

//parent class: AccountHolder
class AccountHolder {
protected:
    std::string name;

public:
    void setName(std::string n) {
        name = n;
    }

    std::string getName() {
        return name;
    }
};

// Derived class: BankAccount
class BankAccount : public AccountHolder {
private:
    int accountNumber;
    double balance;

public:
    BankAccount(std::string n, int accNum, double bal) : accountNumber(accNum), balance(bal) {
        setName(n); // Call base class constructor
    }

    int getAccountNumber() {
        return accountNumber;
    }

    double getBalance() {
        return balance;
    }
};

// Derived class: SavingsAccount
class SavingsAccount : public BankAccount {
private:
    double interestRate;

public:
    SavingsAccount(std::string n, int accNum, double bal, double rate) : BankAccount(n, accNum, bal), interestRate(rate) {}

    double getInterestRate() {
        return interestRate;
    }
};

int main() {
    // Create a SavingsAccount object
    SavingsAccount savingsAcc("Shawn Douglas", 33333, 99000, 19%);

    // Access and print the account details
    std::cout << "Account Holder Name: " << savingsAcc.getName() << std::endl;
    std::cout << "Account Number: " << savingsAcc.getAccountNumber() << std::endl;
    std::cout << "Balance: $" << savingsAcc.getBalance() << std::endl;
    std::cout << "Interest Rate: " << savingsAcc.getInterestRate() << std::endl;

    return 0;
}