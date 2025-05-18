#include <iostream>
#include <string>

// Base class: Vehicle
class Vehicle
{
private:
    std::string make;
    std::string model;

protected:
    std::string vehicleID; // Protected member

public:
    std::string registrationNumber; // Public member

public:
    // Function to set vehicle details
    Vehicle() : make("N.A."), model("N.A."), vehicleID("N.A."), registrationNumber("N.A."){}
    Vehicle(std::string ip1, std::string ip2, std::string ip3, std::string ip4)  : make(ip1), model(ip2), vehicleID(ip3), registrationNumber(ip4){}
    Vehicle(const Vehicle& ref) : make(ref.make), model(ref.model), vehicleID(ref.vehicleID), registrationNumber(ref.registrationNumber) {}  

    // setter function to set Vehicle details
    void setMakeModel(std::string ip1, std::string ip2){
        make = ip1;
        model = ip2;
    }
    void setVehicle(std::string ip1, std::string ip2, std::string ip3, std::string ip4){
        make = ip1;
        model = ip2;                // private members accessible in Base class functions
        vehicleID = ip3;            // protected members accessible in Base class functions
        registrationNumber = ip4;   // public members accessible in Base class functions
    }

    // Function to display vehicle details
    void display()
    {
        std::cout << "Make: " << make << ", Model: " << model
            << ", Vehicle ID: " << vehicleID << ", Registration No: " << registrationNumber << std::endl;
    }
};

// Derived class: Car inheriting from Vehicle
class Car : public Vehicle
{
private:
    // footprint of Vehicle class data members
    int numDoors;

public:
    // footprint of Vehicle class member functions
    // Different constructors to set Car details including base class detail
    Car() : Vehicle(), numDoors(4){}
    Car(int ip1) : Vehicle(), numDoors(ip1){}
    Car(std::string ip1, std::string ip2, std::string ip3, std::string ip4, int ip5) : Vehicle(ip1, ip2, ip3, ip4), numDoors(ip5){}
    Car(const Car& ref) : Vehicle(ref), numDoors(ref.numDoors) {}

    // setter function to set Car details
    void setNumDoors(int ip1){
        numDoors = ip1;
    }
    void setCar(std::string ip1, std::string ip2, std::string ip3, std::string ip4, int ip5){
        setMakeModel(ip1, ip2);     // private members of Base not accessible in Derived class functions
        vehicleID = ip3;            // protected members of Base accessible in Derived class functions
        registrationNumber = ip4;   // public members Base accessible in Derived class functions
        numDoors = ip5;             // private members accessible in Derived class functions
    }

    // Function to display Car details including base class details
    void displayCarDetails()
    {
        display(); // Reusing base class function
        std::cout << "Doors: " << numDoors << std::endl;
    }
    // Additional functionalities specific to Car can be added here
};

// Further derived class: ElectricCar inheriting from Car
class ElectricCar : public Car
{
private:
    // footprint of Vehicle and Car class data members
    int batteryCapacity;

public:    
    // footprint of Vehicle and Car class member functions
    // Different constructors to set ElectricCar details including base class detail
    ElectricCar() : Car(), batteryCapacity(100){}
    ElectricCar(std::string ip1, std::string ip2, std::string ip3, std::string ip4, int ip5, int ip6) : Car(ip1, ip2, ip3, ip4, ip5), batteryCapacity(ip6){}
    ElectricCar(const ElectricCar& ref) : Car(ref), batteryCapacity(ref.batteryCapacity) {}

    // setter function to set Electric Car details
   
    void setElectricVehicle(std::string ip1, std::string ip2, std::string ip3, std::string ip4, int ip5, int ip6){
        setMakeModel(ip1, ip2);     // private members of Base not accessible in Derived Most class functions
        vehicleID = ip3;            // protected members of Base accessible in Derived Most class functions
        registrationNumber = ip4;   // public members of Base accessible in Derived Most class functions
        setNumDoors(ip5);           // private members of Derived not accessible in Derived Most class functions
        batteryCapacity = ip6;      // private members accessible in Derived Most class functions
    }

    // Function to display ElectricCar details including base class and Car class details
    void displayElectricCarDetails()
    {
        displayCarDetails(); // Reusing Car class function
        std::cout << "Battery Capacity: " << batteryCapacity << " kWh" << std::endl;
    }

    // Additional functionalities specific to ElectricCar can be added here
};

// Main function
int main()
{
    ElectricCar ECar1("BMW", "X3", "01BH0001AA", "4Y1SL65848Z411439", 4, 120);
    // std::cout << ECar1.make << "\n"; // private member not accessible in main()
    // std::cout << ECar1.model << "\n"; // private member not accessible in main()
    // std::cout << ECar1.numDoors << "\n"; // private member not accessible in main()
    // std::cout << ECar1.batteryCapacity << "\n"; // private member not accessible in main()
    // std::cout << ECar1.vehicleID << "\n"; // protected member not accessible in main()
    std::cout << ECar1.registrationNumber << "\n"; // public member accessible in main()
    ECar1. displayElectricCarDetails();

    return 0;
}