/*Author:Shawn Douglas
Reg No:BSE-05-0199/2024
Group:Group 3
*/
#include <iostream>
using namespace std;

#define CREATE_3D_ARRAY(x, y, z) new int**[x]; for(int i = 0; i < x; i++) { array[i] = new int*[y]; for(int j = 0; j < y; j++) { array[i][j] = new int[z]; }}

int main() {
    int x, y, z;

    // Ask user for the dimensions of the 3D array
    cout << "Enter the number of rows (x): ";
    cin >> x;
    cout << "Enter the number of columns (y): ";
    cin >> y;
    cout << "Enter the depth (z): ";
    cin >> z;

    // Create a 3D array with the given dimensions using the macro
    int*** array = CREATE_3D_ARRAY(x, y, z);

    // Ask the user to input elements for the array
    cout << "Enter elements for the array:" << endl;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            for (int k = 0; k < z; k++) {
                cout << "Element [" << i + 1 << "][" << j + 1 << "][" << k + 1 << "]: ";
                cin >> array[i][j][k];
            }
        }
    }

    // Display the elements entered by the user
    cout << "The elements in the array are:" << endl;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            for (int k = 0; k < z; k++) {
                cout << array[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    // Free the allocated memory
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            delete[] array[i][j];
        }
        delete[] array[i];
    }
    delete[] array;

    return 0;
}
