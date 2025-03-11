/*
Author; Shawn Douglas
Reg no;BSE-05-0199/2024
GROUP; BSE group3
*/
#include <iostream>
#include <string>

using namespace std;

// Define the Patient structure
struct Patient {
    string Name;
    int Age;
    string Diagnosis;
};

// Function to display patient records
void displayPatients(const Patient& p) {
    cout << "Name: " << p.Name << endl;
    cout << "Age: " << p.Age << endl;
    cout << "Diagnosis: " << p.Diagnosis << endl;
}

int main() {
    Patient p1, p2;  // Create two patient objects

    // Get input for the first patient
    cout << "Enter details for Patient 1:" << endl;
    cout << "Name: ";
    getline(cin, p1.Name);  // Use getline to handle spaces in names
    cout << "Age: ";
    cin >> p1.Age;
    cin.ignore();  // Clear the buffer after reading an integer
    cout << "Diagnosis: ";
    getline(cin, p1.Diagnosis);

    // Get input for the second patient
    cout << "\nEnter details for Patient 2:" << endl;
    cout << "Name: ";
    getline(cin, p2.Name);
    cout << "Age: ";
    cin >> p2.Age;
    cin.ignore();
    cout << "Diagnosis: ";
    getline(cin, p2.Diagnosis);

    // Display the patient records
    cout << "\nPatient 1 Details:\n";
    displayPatients(p1);
    cout << "\nPatient 2 Details:\n";
    displayPatients(p2);

    return 0;
}