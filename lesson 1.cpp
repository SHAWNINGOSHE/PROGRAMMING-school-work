#include <iostream>
#include <string>

using namespace std;

int main() {
    string name;
    int age;

    cout << "Enter your name: ";
    cin >> name;

    cout << "Enter your age: ";
    cin >> age;

    if (age >= 18) {
        cout << name << ", you can vote." << endl;
    } else {
        cout << name << ", you are not of the required age to vote." << endl;
    }

    return 0;
}