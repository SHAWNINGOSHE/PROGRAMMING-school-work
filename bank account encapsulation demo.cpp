#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string accountHolder;
    double balance;

public:
    // Constructor
    BankAccount(const string &name, double initialBalance) {
        accountHolder = name;
        balance = (initialBalance >= 0) ? initialBalance : 0;
    }

    // Getter for accountHolder
    string getAccountHolder() const {
        return accountHolder;
    }

    // Setter for accountHolder
    void setAccountHolder(const string &name) {
        accountHolder = name;
    }

    // Getter for balance
    double getBalance() const {
        return balance;
    }

    // Setter for balance
    void setBalance(double amount) {
        if (amount >= 0) {
            balance = amount;
        }
    }
};

int main() {
    // Creating a bank account with an initial balance
    BankAccount myAccount("Shawn", 1000.0);

    // Displaying account details
    cout << "Account Holder: " << myAccount.getAccountHolder() << endl;
    cout << "Initial Balance: $" << myAccount.getBalance() << endl;

    // Modifying account details
    myAccount.setAccountHolder("Jane Doe");
    myAccount.setBalance(1500.0);

    // Displaying updated account details
    cout << "Updated Account Holder: " << myAccount.getAccountHolder() << endl;
    cout << "Updated Balance: $" << myAccount.getBalance() << endl;

    return 0;
}
