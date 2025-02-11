/* 
Author: Shawn Ingoshe.
Reg No: BSE-05-0199/2024.
Group: BSE Group 3.
GITHUB: SHAWNINGOSHE
*/

#include <iostream> // Include the input/output stream library for functions like cout and cin
#include <cmath> // Include the math library for mathematical functions like pow

using namespace std; // Use the standard namespace to avoid writing std before cout, cin, etc.

// Function to calculate the volume of a cylinder
double calculateCylinderVolume(double radius, double height) {
    return M_PI * pow(radius, 2) * height; // Calculate the volume using the formula: π * radius² * height
}

int main() { // Start of the main function, the programs entry point
    double radius, height; // Declare variables to store the radius and height of the cylinder

    cout << "Enter the radius of the cylinder: "; // Prompt the user to enter the radius
    cin >> radius; // Read the radius from the input and store it in the radius variable

    cout << "Enter the height of the cylinder: "; // Prompt the user to enter the height
    cin >> height; // Read the height from the input and store it in the height variable

    double volume = calculateCylinderVolume(radius, height); // Calculate the volume using the calculateCylinderVolume function
    cout << "The volume of the cylinder is: " << volume << endl; // Print the calculated volume

    return 0; // Indicate that the program executed successfully
}
