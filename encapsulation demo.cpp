
/* 
Author: Shawn Ingoshe.
Reg No: BSE-05-0199/2024.
Group: BSE Group 3.
GITHUB: SHAWNINGOSHE
*/

#include <iostream>
using namespace std;

class employee { // Define a class named employee to represent an employee

private: // Private members are accessible only within the class
    string name; // String variable to store the employees name
    int salary; // Integer variable to store the employees salary

public: // Public members are accessible from outside the class
    // Setter function to set the salary
    void setsalary(int s) {
        salary = s; // Assign the given salary to the salary member
    }

    // Getter function to get the salary
    int getsalary() {
        return salary; // Return the value of the salary member
    }

    // Setter function to set the name (with a minor fix)
    void setname(string n) { // The parameter should be a string
        name = n; // Assign the given name to the name member
    }

    // Getter function to get the name
    string getname() {
        return name; // Return the value of the name member
    }
};

int main() {
    employee el; // Create an instance of the employee class named el
    el.setsalary(99000000); // Set the salary of the employee
    cout << "salary is:" << el.getsalary() << endl; // Print the salary of the employee

    return 0; // Indicate that the program executed successfully
}
