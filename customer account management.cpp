/*
Author;Shawn Douglas
Reg No;BSE-05-0199/2024
GROUP;BSE group3
*/
#include <iostream>
#include <string>
using namespace std;

// Define the Customer structure
struct Customer {
    string name;
    double accountBalance;
    string lastTransaction;
};

// Function to display customer account details
void displayCustomer(const Customer& c) {
    cout << "Name: " << c.name << endl;
    cout << "Account Balance: " << c.accountBalance << endl;
    cout << "Last Transaction: " << c.lastTransaction << endl;
}

int main() {
    Customer customer1, customer2;

    // Input customer1 details
    cout << "Enter details for Customer 1:" << endl;
    cout << "Name: ";
    getline(cin, customer1.name);
    cout << "Account Balance: ";
    cin >> customer1.accountBalance;
    cin.ignore(); // To ignore the newline character
    cout << "Last Transaction: ";
    getline(cin, customer1.lastTransaction);

    // Input customer2 details
    cout << "Enter details for Customer 2:" << endl;
    cout << "Name: ";
    getline(cin, customer2.name);
    cout << "Account Balance: ";
    cin >> customer2.accountBalance;
    cin.ignore(); // To ignore the newline character
    cout << "Last Transaction: ";
    getline(cin, customer2.lastTransaction);

    // Display their details
    displayCustomer(customer1);
    displayCustomer(customer2);

    return 0;
}
