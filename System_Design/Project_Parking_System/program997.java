/*
    ParkingLot Automation System

    Step 1 : Create required Enums
    Step 2 : Vehicle Hierarchy Creation
    Step 3 : Vehicle Factory Creation
    Step 4 : ParkingSpot Hierarchy
    Step 5 : ParkingObserver Class
    Step 6 : ParkingFloor Class
    Step 7 : ParkingDisplayBoard (Observer Pattern)
    Step 8 : ParkingStrategy Class (Strategy Pattern)
    Step 9 : PricingStrategy Class (Strategy Pattern)
    Step 10 : PaymentStrategy Class
    Step 11 : ParkingTicket Class
    Step 12 : EntryGate Class
    Step 13 : ExitGate Class
    Step 14 : ParkingLot class (Singelton Pattern)
    Step 15 : Main Class (Controller)
*/

import java.util.*;
import java.time.Duration;
import java.time.LocalDateTime;

/////////////////////////////////////////////////////////////////////////////
// Step 1 : Create Enums 
// It is used to create fixed constants which are required 
// throughout the project
/////////////////////////////////////////////////////////////////////////////


// Represents the different types of vehicle supported by the project
enum VehicleType{
    BIKE,
    CAR,
    TRUCK
}

// Represents the different types of parking spots
enum SpotType{
    BIKE,
    CAR,
    TRUCK
}

// Represent the current state of parking ticket
enum TicketStatus{
    ACTIVE,
    CLOSED
}

/////////////////////////////////////////////////////////////////////////////
// Step 2 : Create Vehicle Class Hierarchy
// It is used to create multiple rypes of classes 
// which represents the types of vehicles
// Concepts : Abstraction,Inheritance,Polymorphism,Encapsulation
/////////////////////////////////////////////////////////////////////////////

// Class which represents a generic vehicle type
abstract class Vehicle{

    // Abstarct(Hidden) characteristics of class
    private String vehicleNumber;
    private VehicleType vehicleType;

    // Parameeterized constructor
    public Vehicle(String vehicleNumber,VehicleType vehicleType){
        this.vehicleNumber = vehicleNumber;
        this.vehicleType = vehicleType;
    }

    // Concrete getter method
    public VehicleType getVehicleType(){
        return this.vehicleType;
    }

    // Concrete getter method
    public String getVehicleNumber(){
        return this.vehicleNumber;
    }

    // Every concrete class will provide its own definition
    public abstract void display();
} 

// Class which represents the vehicle type as Bike
class Bike extends Vehicle{
    public Bike(String vehicleNumber){
        // Calls vehicle class constructor
        super(vehicleNumber,VehicleType.BIKE);
    }

    // Method Overriding
    @Override 
    public void display(){
        System.out.println("Bike : " + getVehicleNumber());
    }
}

// Class which represents the vehicle type as Car
class Car extends Vehicle{
    public Car(String vehicleNumber){
        // Calls vehicle class constructor
        super(vehicleNumber,VehicleType.CAR);
    }

    // Method Overriding
    @Override 
    public void display(){
        System.out.println("Car : " + getVehicleNumber());
    }
}

// Class which represents the vehicle type as Truck
class Truck extends Vehicle{
    public Truck(String vehicleNumber){
        // Calls vehicle class constructor
        super(vehicleNumber,VehicleType.TRUCK);
    }

    // Method Overriding
    @Override 
    public void display(){
        System.out.println("Truck : " + getVehicleNumber());
    }
}

class program997{
        public static void main(String A[]){

    }
}