#include <iostream>
#include <string>

class Car {
public:
    /* Public data members*/
    std::string brand;
    std::string model;
    float price;
    int mileage;

    /* Member function to display car details*/
    void display() {
        std::cout << "Car Brand: " << brand << std::endl;
        std::cout << "Car Model: " << model << std::endl;
        std::cout << "Car Price: $" << price << std::endl;
        std::cout << "Car Mileage: " << mileage << " miles" << std::endl;
    }

    /* Member function to drive the car*/
    void drive(int distance) {
        mileage += distance;
        std::cout << "Updated Mileage: " << mileage << " miles" << std::endl;
    }
};

int main() {
    /* Creating a Car object*/
    Car myCar;
    myCar.brand = "mercedes benz";
    myCar.model = "GLE";
    myCar.price = 85000;
    myCar.mileage = 600;

    /* Displaying the car's details*/
    myCar.display();

    /* Simulating driving the car for 375 miles*/
    std::cout << "\nDriving the car for 375 miles..." << std::endl;
    myCar.drive(375);

    /* Simulating driving the car for 80 miles*/
    std::cout << "\nDriving the car for 80 miles..." << std::endl;
    myCar.drive(80);

    return 0;
}
