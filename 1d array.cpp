/*Author:Shawn Douglas
Reg No:BSE-05-0199/2024
Group:Group 3
*/

#include <iostream>
using namespace std;

#define CREATE_ARRAY(size) new int[size]

int main() {
    int size;

    // Ask user for the size of the array
    cout << "Enter the size of the array: ";
    cin >> size;

    // Create an array with the given size using the macro
    int* array = CREATE_ARRAY(size);

    // Ask the user to input elements for the array
    cout << "Enter " << size << " elements:" << endl;
    for (int i = 0; i < size; i++) {
        cout << "Element " << i + 1 << ": ";
        cin >> array[i];
    }

    // Display the elements entered by the user
    cout << "The elements in the array are:" << endl;
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    // Free the allocated memory
    delete[] array;

    return 0;
}
