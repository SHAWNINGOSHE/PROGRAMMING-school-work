/* 
Author: Shawn Ingoshe.
Reg No: BSE-05-0199/2024.
Group: BSE Group 3.
GITHUB: SHAWNINGOSHE
*/

#include <stdio.h> // Include the standard input/output library for functions like printf and scanf
#include <string.h> // Include the string library for string manipulation functions

int main() { // Start of the main function, the programs entry point
    char name[50]; // Declare a character array named name to store the users name, with a maximum length of 50 characters
    int age; // Declare an integer variable named age to store the users age

    printf("Enter your name: "); // Print a message asking the user to enter their name
    scanf("%s", name); // Read the users name from the input and store it in the name array

    printf("Enter your age: "); // Print a message asking the user to enter their age
    scanf("%d", &age); // Read the users age from the input and store it in the age variable

    if (age >= 18) { // Check if the users age is greater than or equal to 18
        printf("%s, you can vote.\n", name); // If the age is 18 or older, print a message indicating that the user can vote
    } else { // If the age is less than 18
        printf("%s, you are not of the required age to vote.\n", name); // Print a message indicating that the user is not old enough to vote
    }

    return 0; // Indicate that the program executed successfully
}
