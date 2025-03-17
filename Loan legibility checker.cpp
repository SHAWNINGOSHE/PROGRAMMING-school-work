/*
Author;Douglas Ingoshe
Reg no;BSE-05-0199/2024
Group;BSE group 3
loan legibility checker.
*/
#include <iostream>
using namespace std;

// Function to check loan eligibility
void checkLoanEligibility(int age, float income) {
    if (age >= 21 && income >= 21000) {
        cout << "Congratulations! You qualify for a loan." << endl;
    } else {
        cout << "Unfortunately, we are unable to offer you a loan at this time." << endl;
    }
}

int main() {
    int age;
    float income;

    // Prompts for age and income
    cout << "Enter your age: ";
    cin >> age;
    cout << "Enter your annual income in Sh: ";
    cin >> income;

    // Call the function
    checkLoanEligibility(age, income);

    return 0;
}
