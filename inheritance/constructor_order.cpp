#include <iostream>
#include <string>
 
// Base class: Vehicle
class Vehicle {
private:    // data members of Vehicle class
    std::string make;
    std::string model;
 
public:
    // Function to set vehicle details
    Vehicle() : make("N.A."), model("N.A.") { std::cout << "Vehicle Constructor called\n"; }
    Vehicle(std::string ip1, std::string ip2)  : make(ip1), model(ip2) { std::cout << make << " Vehicle Constructor called\n"; }
    Vehicle(const Vehicle& ref) : make(ref.make), model(ref.model) { std::cout << "Vehicle Constructor called\n"; }  
    // Function to display vehicle details
    void display() {
        std::cout << "Make: " << make << ", Model: " << model << std::endl;
    }
    ~Vehicle() { std::cout << make << " Vehicle Destructor called\n"; }
};
 
// Derived class: Car inheriting from Vehicle
class Car : public Vehicle {
private:
    // footprint of Vehicle class data members    // data members of Car class
    int numDoors;
 
public:
    // footprint of Vehicle class member functions
    // Derived constructors making explicit call to Base class constructors
    Car() : Vehicle(), numDoors(4){ std::cout << "Car Constructor called\n"; }
    Car(int ip1) : Vehicle(), numDoors(ip1){ std::cout << "Car Constructor called\n"; }
    Car(std::string ip1, std::string ip2, int ip3) : Vehicle(ip1, ip2), numDoors(ip3) { std::cout << ip1 << " Car Constructor called\n"; }
    Car(const Car& ref) : Vehicle(ref), numDoors(ref.numDoors) { std::cout << "Car Constructor called\n"; }
    // Function to display Car details including base class details
    void displayCarDetails() {  // specialization
        display(); // Reusing base class function
        std::cout << "Doors: " << numDoors << std::endl;
    }
    // Additional functionalities specific to Car can be added here
    ~Car() { std::cout << "Car Destructor called\n"; }
};
 
Car myCar1("Global Volvo", "XC60", 4);


// Main function
int main() {
 
    // Creating an instance of Car
    Car myCar1("Local BMW", "X3", 4);

    Car* ptr = new Car("Dinamically Lamborghini", "Gallardo", 2);
    delete ptr;

    return 0;
}