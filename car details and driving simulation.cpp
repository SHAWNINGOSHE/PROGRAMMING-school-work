/* 
Author: Shawn Ingoshe.
Reg No: BSE-05-0199/2024.
Group: BSE Group 3.
GITHUB: SHAWNINGOSHE
*/

#include <iostream> // Include the input/output stream library for functions like cout and cin
#include <string> // Include the string library for working with strings

class Car { // Define a class named Car to represent a car object
public:
    // Public data members
    std::string brand; // String variable to store the cars brand
    std::string model; // String variable to store the cars model
    float price; // Float variable to store the cars price
    int mileage; // Integer variable to store the cars mileage

    // Member function to display car details
    void display() { // Function to display the cars information
        std::cout << "Car Brand: " << brand << std::endl; // Print the cars brand
        std::cout << "Car Model: " << model << std::endl; // Print the cars model
        std::cout << "Car Price: $" << price << std::endl; // Print the cars price
        std::cout << "Car Mileage: " << mileage << " miles" << std::endl; // Print the cars mileage
    }

    // Member function to drive the car
    void drive(int distance) { // Function to simulate driving the car
        mileage += distance; // Update the mileage by adding the distance driven
        std::cout << "Updated Mileage: " << mileage << " miles" << std::endl; // Print the updated mileage
    }
};

int main() { // Start of the main function, the programs entry point
    // Creating a Car object
    Car myCar; // Create an instance of the Car class named myCar
    myCar.brand = "mercedes benz"; // Set the brand of the car
    myCar.model = "GLE"; // Set the model of the car
    myCar.price = 85000; // Set the price of the car
    myCar.mileage = 600; // Set the initial mileage of the car

    // Displaying the cars details
    myCar.display(); // Display the cars details using the display function

    // Simulating driving the car for 375 miles
    std::cout << "\nDriving the car for 375 miles..." << std::endl; // Print a message indicating driving
    myCar.drive(375); // Simulate driving the car for 375 miles using the drive function

    // Simulating driving the car for 80 miles
    std::cout << "\nDriving the car for 80 miles..." << std::endl; // Print a message indicating driving
    myCar.drive(80); // Simulate driving the car for 80 miles using the drive function

    return 0; // Indicate that the program executed successfully
}
