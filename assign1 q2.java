/*Author:Shawn Douglas
Reg No:BSE-05-0199/2024
Group:Group 3
*/
// LoginProgram.java
// Implements a simple login system with limited attempts.

import java.util.Scanner;

public class LoginProgram {

    // Correct username and password for validation.
    private static final String CORRECT_USERNAME = "admin";
    private static final String CORRECT_PASSWORD = "password";
    private static final int MAX_TRIES = 3; // Maximum allowed login attempts.

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Initialize scanner for input.

        System.out.println("--- User Login System ---");

        // Loop through allowed login attempts.
        for (int tryCount = 1; tryCount <= MAX_TRIES; tryCount++) {
            System.out.println("\nAttempt " + tryCount + " of " + MAX_TRIES);

            System.out.print("Enter username: ");
            String username = scanner.nextLine();

            System.out.print("Enter password: ");
            String password = scanner.nextLine();

            // Validate credentials.
            if (username.equals(CORRECT_USERNAME) && password.equals(CORRECT_PASSWORD)) {
                System.out.println("Login Successful! Welcome, " + username + ".");
                scanner.close(); // Close scanner.
                return; // Exit on success.
            } else {
                System.out.println("Login Failed: Incorrect username or password.");
                // Prompt for retry if attempts remain.
                if (tryCount < MAX_TRIES) {
                    System.out.println("Please try again.");
                }
            }
        }

        // Message if all attempts are exhausted.
        System.out.println("\nMaximum login attempts exceeded. Your account may be locked.");
        scanner.close(); // Ensure scanner is closed.
    }
}
