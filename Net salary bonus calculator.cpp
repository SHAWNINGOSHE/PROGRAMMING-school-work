/*
Author;Douglas Ingoshe
Reg no;BSE-05-0199/2024
Group;BSE Group3
Net salary bonus calculator.
*/
#include <iostream>
using namespace std;

int main() {
    float salary, bonus;
    int years;

    // Ask user for their salary and years of service
    cout << "Enter your salary: ";
    cin >> salary;

    if (salary <= 0) {
        cout << "Invalid salary. Please enter a positive value." << endl;
        return 1;
    }

    cout << "Enter your years of service: ";
    cin >> years;

    if (years < 0) {
        cout << "Invalid input for years of service. Please enter a non-negative value." << endl;
        return 1;
    }

    // Compute bonus amount based on years of service
    if (years > 10) {
        bonus = 0.12 * salary;
    } else if (years >= 6 && years <= 10) {
        bonus = 0.10 * salary;
    } else {
        bonus = 0.08 * salary;
    }

    // Print the net bonus amount
    cout << "Your net bonus amount is: " << bonus << endl;

    return 0;
}
