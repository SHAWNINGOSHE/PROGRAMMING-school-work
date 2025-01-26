#include <iostream>
#include <cmath>

using namespace std;

double calculateCylinderVolume(double radius, double height) {
    return M_PI * pow(radius, 2) * height;
}

int main() {
    double radius, height;
    cout << "Enter the radius of the cylinder: ";
    cin >> radius;
    cout << "Enter the height of the cylinder: ";
    cin >> height;

    double volume = calculateCylinderVolume(radius, height);
    cout << "The volume of the cylinder is: " << volume << endl;

    return 0;
}