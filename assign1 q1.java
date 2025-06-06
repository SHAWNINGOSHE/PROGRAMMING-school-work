/*Author:Shawn Douglas
Reg No:BSE-05-0199/2024
Group:Group 3
*/
// CarRentalSystemSingleFile.java
// This file consolidates all classes for the Car Rental System into a single Java file.

import java.time.LocalDate;
import java.util.ArrayList;
import java.util.List;
import java.util.UUID;

// Main class to demonstrate the Car Rental System.
public class Main {

    // Car class: Represents a car in the rental system.
    public static class Car {
        private String make;
        private String model;
        private String licensePlate;
        private int year;
        private boolean isAvailable;

        public Car(String make, String model, String licensePlate, int year) {
            this.make = make;
            this.model = model;
            this.licensePlate = licensePlate;
            this.year = year;
            this.isAvailable = true; // New car is available by default
        }

        public String getMake() { return make; }
        public String getModel() { return model; }
        public String getLicensePlate() { return licensePlate; }
        public int getYear() { return year; }
        public boolean isAvailable() { return isAvailable; }

        public void setAvailable(boolean available) { this.isAvailable = available; }

        @Override
        public String toString() {
            return "Car [License Plate: " + licensePlate +
                   ", Make: " + make +
                   ", Model: " + model +
                   ", Year: " + year +
                   ", Available: " + (isAvailable ? "Yes" : "No") + "]";
        }
    }

    // Customer class: Represents a customer in the rental system.
    public static class Customer {
        private String customerId;
        private String name;
        private String contactInfo;

        public Customer(String customerId, String name, String contactInfo) {
            this.customerId = customerId;
            this.name = name;
            this.contactInfo = contactInfo;
        }

        public String getCustomerId() { return customerId; }
        public String getName() { return name; }
        public String getContactInfo() { return contactInfo; }

        public void setName(String name) { this.name = name; }
        public void setContactInfo(String contactInfo) { this.contactInfo = contactInfo; }

        @Override
        public String toString() {
            return "Customer [ID: " + customerId +
                   ", Name: " + name +
                   ", Contact: " + contactInfo + "]";
        }
    }

    // RentalTransaction class: Represents a single car rental transaction.
    public static class RentalTransaction {
        private String transactionId;
        private Car rentedCar;
        private Customer rentingCustomer;
        private LocalDate rentalDate;
        private LocalDate returnDate;

        public RentalTransaction(String transactionId, Car rentedCar, Customer rentingCustomer, LocalDate rentalDate, LocalDate returnDate) {
            this.transactionId = transactionId;
            this.rentedCar = rentedCar;
            this.rentingCustomer = rentingCustomer;
            this.rentalDate = rentalDate;
            this.returnDate = returnDate;
        }

        public String getTransactionId() { return transactionId; }
        public Car getRentedCar() { return rentedCar; }
        public Customer getRentingCustomer() { return rentingCustomer; }
        public LocalDate getRentalDate() { return rentalDate; }
        public LocalDate getReturnDate() { return returnDate; }

        public void setReturnDate(LocalDate returnDate) { this.returnDate = returnDate; }

        @Override
        public String toString() {
            return "Rental Transaction [ID: " + transactionId +
                   ", Car: " + rentedCar.getLicensePlate() + " (" + rentedCar.getMake() + " " + rentedCar.getModel() + ")" +
                   ", Customer: " + rentingCustomer.getName() + " (ID: " + rentingCustomer.getCustomerId() + ")" +
                   ", Rented On: " + rentalDate +
                   ", Due/Returned On: " + returnDate + "]";
        }
    }

    // RentalAgency class: Manages the collection of cars, customers, and rental transactions.
    public static class RentalAgency {
        private List<Car> cars;
        private List<Customer> customers;
        private List<RentalTransaction> transactions;

        public RentalAgency() {
            this.cars = new ArrayList<>();
            this.customers = new ArrayList<>();
            this.transactions = new ArrayList<>();
        }

        public void addCar(Car car) {
            for (Car existingCar : cars) { // Check for duplicate license plates
                if (existingCar.getLicensePlate().equals(car.getLicensePlate())) {
                    System.out.println("Error: Car with license plate " + car.getLicensePlate() + " already exists.");
                    return;
                }
            }
            cars.add(car);
            System.out.println("Car added: " + car.getMake() + " " + car.getModel() + " (" + car.getLicensePlate() + ")");
        }

        public boolean removeCar(String licensePlate) {
            for (int i = 0; i < cars.size(); i++) {
                if (cars.get(i).getLicensePlate().equals(licensePlate)) {
                    if (!cars.get(i).isAvailable()) { // Check if car is currently rented
                        System.out.println("Error: Cannot remove car " + licensePlate + " as it is currently rented.");
                        return false;
                    }
                    cars.remove(i);
                    System.out.println("Car with license plate " + licensePlate + " removed.");
                    return true;
                }
            }
            System.out.println("Car with license plate " + licensePlate + " not found.");
            return false;
        }

        public void displayAllCars() {
            if (cars.isEmpty()) {
                System.out.println("No cars in the agency's fleet.");
                return;
            }
            System.out.println("\n--- All Cars ---");
            for (Car car : cars) {
                System.out.println(car);
            }
        }

        public void displayAvailableCars() {
            System.out.println("\n--- Available Cars ---");
            boolean foundAvailable = false;
            for (Car car : cars) {
                if (car.isAvailable()) {
                    System.out.println(car);
                    foundAvailable = true;
                }
            }
            if (!foundAvailable) {
                System.out.println("No cars currently available for rent.");
            }
        }

        public void addCustomer(Customer customer) {
            for (Customer existingCustomer : customers) { // Check for duplicate customer IDs
                if (existingCustomer.getCustomerId().equals(customer.getCustomerId())) {
                    System.out.println("Error: Customer with ID " + customer.getCustomerId() + " already exists.");
                    return;
                }
            }
            customers.add(customer);
            System.out.println("Customer registered: " + customer.getName() + " (ID: " + customer.getCustomerId() + ")");
        }

        public Customer findCustomerById(String customerId) {
            for (Customer customer : customers) {
                if (customer.getCustomerId().equals(customerId)) {
                    return customer;
                }
            }
            return null;
        }

        public void rentCar(String customerId, String licensePlate, int rentalDurationDays) {
            Customer customer = findCustomerById(customerId);
            if (customer == null) {
                System.out.println("Rental Failed: Customer ID " + customerId + " not found.");
                return;
            }

            Car carToRent = null;
            for (Car car : cars) {
                if (car.getLicensePlate().equals(licensePlate)) {
                    carToRent = car;
                    break;
                }
            }

            if (carToRent == null) {
                System.out.println("Rental Failed: Car " + licensePlate + " not found.");
                return;
            }

            if (!carToRent.isAvailable()) {
                System.out.println("Rental Failed: Car " + licensePlate + " is not available.");
                return;
            }

            carToRent.setAvailable(false); // Mark car as unavailable

            // Record the transaction
            String transactionId = UUID.randomUUID().toString();
            LocalDate rentalDate = LocalDate.now();
            LocalDate returnDate = rentalDate.plusDays(rentalDurationDays);

            RentalTransaction transaction = new RentalTransaction(transactionId, carToRent, customer, rentalDate, returnDate);
            transactions.add(transaction);

            System.out.println("\n--- Rental Successful ---");
            System.out.println("Transaction ID: " + transaction.getTransactionId());
            System.out.println("Customer: " + customer.getName());
            System.out.println("Car: " + carToRent.getMake() + " " + carToRent.getModel() + " (" + carToRent.getLicensePlate() + ")");
            System.out.println("Rental Date: " + transaction.getRentalDate());
            System.out.println("Expected Return Date: " + transaction.getReturnDate());
        }

        public void returnCar(String licensePlate) {
            Car carToReturn = null;
            for (Car car : cars) {
                if (car.getLicensePlate().equals(licensePlate)) {
                    carToReturn = car;
                    break;
                }
            }

            if (carToReturn == null) {
                System.out.println("Return Failed: Car " + licensePlate + " not found.");
                return;
            }

            if (carToReturn.isAvailable()) {
                System.out.println("Return Failed: Car " + licensePlate + " was not marked as rented.");
                return;
            }

            carToReturn.setAvailable(true); // Mark car as available again

            // Find and update the corresponding rental transaction
            RentalTransaction activeTransaction = null;
            for (int i = transactions.size() - 1; i >= 0; i--) {
                if (transactions.get(i).getRentedCar().getLicensePlate().equals(licensePlate)) {
                    activeTransaction = transactions.get(i);
                    break;
                }
            }

            if (activeTransaction != null) {
                activeTransaction.setReturnDate(LocalDate.now()); // Set actual return date
                System.out.println("\n--- Car Returned Successfully ---");
                System.out.println("Car: " + carToReturn.getMake() + " " + carToReturn.getModel() + " (" + carToReturn.getLicensePlate() + ")");
                System.out.println("Transaction ID: " + activeTransaction.getTransactionId());
                System.out.println("Actual Return Date: " + activeTransaction.getReturnDate());
            } else {
                System.out.println("Error: Could not find active rental transaction for car " + licensePlate);
            }
        }

        public void displayAllTransactions() {
            if (transactions.isEmpty()) {
                System.out.println("No rental transactions recorded.");
                return;
            }
            System.out.println("\n--- All Rental Transactions ---");
            for (RentalTransaction transaction : transactions) {
                System.out.println(transaction);
            }
        }
    }

    // Main method: The entry point for the Car Rental System application.
    public static void main(String[] args) {
        System.out.println("--- Car Rental System Demo ---");

        RentalAgency agency = new RentalAgency();

        // Add 2 Cars to the fleet
        System.out.println("\n--- Adding Cars ---");
        Car car1 = new Car("Toyota", "Camry", "KCD 456Y", 2020);
        Car car2 = new Car("Honda", "Civic", "KBE 789A", 2018);

        agency.addCar(car1);
        agency.addCar(car2);
        agency.addCar(new Car("Ford", "Focus", "KCD 456Y", 2015)); // Attempt duplicate plate

        agency.displayAllCars();
        agency.displayAvailableCars();

        // Register some Customers
        System.out.println("\n--- Registering Customers ---");
        Customer cust1 = new Customer("C001", "Alice Smith", "alice@example.com");
        Customer cust2 = new Customer("C002", "Bob Johnson", "bob@example.com");

        agency.addCustomer(cust1);
        agency.addCustomer(cust2);

        // Test Cases for Rental and Return
        System.out.println("\n--- Testing Rentals and Returns ---");

        // Test Case 1: Successful rental of car1
        System.out.println("\nTest Case 1: Renting car KCD 456Y to Alice Smith (C001) for 5 days.");
        agency.rentCar("C001", "KCD 456Y", 5);
        agency.displayAvailableCars();

        // Test Case 2: Attempt to rent an unavailable car
        System.out.println("\nTest Case 2: Attempting to rent car KCD 456Y again (should fail).");
        agency.rentCar("C002", "KCD 456Y", 3);

        // Test Case 3: Successful rental of car2
        System.out.println("\nTest Case 3: Renting car KBE 789A to Bob Johnson (C002) for 2 days.");
        agency.rentCar("C002", "KBE 789A", 2);
        agency.displayAvailableCars();

        // Display all transactions
        agency.displayAllTransactions();

        // Test Case 4: Returning car KCD 456Y
        System.out.println("\nTest Case 4: Returning car KCD 456Y.");
        agency.returnCar("KCD 456Y");
        agency.displayAvailableCars();

        // Test Case 5: Attempt to return a car that wasn't rented (or already returned)
        System.out.println("\nTest Case 5: Attempting to return an already available car.");
        agency.returnCar("KCD 456Y");

        // Display all transactions after returns
        agency.displayAllTransactions();

        // Test Car Removal
        System.out.println("\n--- Testing Car Removal ---");
        agency.removeCar("KCD 456Y"); // Should successfully remove
        agency.removeCar("KBE 789A"); // Should successfully remove

        agency.displayAllCars(); // Show remaining cars
        System.out.println("\n--- End of Car Rental System Demo ---");
    }
}
