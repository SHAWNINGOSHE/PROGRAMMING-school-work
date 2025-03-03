/*Author:Shawn Douglas
Reg No:BSE-05-0199/2024
Group:Group 3
*/
#include <iostream>
using namespace std;

#define CREATE_2D_ARRAY(rows, cols) new int*[rows]; for(int i = 0; i < rows; i++) array[i] = new int[cols]

int main() {
    int rows, cols;

    // Ask user for the number of rows and columns
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    // Create a 2D array with the given rows and columns using the macro
    int** array = CREATE_2D_ARRAY(rows, cols);

    // Ask the user to input elements for the array
    cout << "Enter elements for the array:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Element [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> array[i][j];
        }
    }

    // Display the elements entered by the user
    cout << "The elements in the array are:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }

    // Free the allocated memory
    for (int i = 0; i < rows; i++) {
        delete[] array[i];
    }
    delete[] array;

    return 0;
}
