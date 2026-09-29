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

/////////////////////////////////////////////////////////////////////////////
// Step 3 : Create Vehicle Factory class
// It is used to centralise the creation of vehicle objects
// Concepts : Factory Design Pattern
/////////////////////////////////////////////////////////////////////////////

class VehicleFactory{
    // Creates and returns the desired class object
    public static Vehicle createVehicle(VehicleType type, String number){
        switch(type){
            case BIKE :
                return new Bike(number);
            case CAR :
                return new Car(number);
            case TRUCK :
                return new Truck(number);
            default :
                throw new IllegalArgumentException("Invalid Vehicle Type");        
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
// Step 4 : Create ParkingSpot Hierarchy
// It is used to create hierarchy of Parking Spots
// Concepts : Encapsulation,Abstraction,Inheritance,Polymorphism
/////////////////////////////////////////////////////////////////////////////

abstract class ParkingSpot{
    // Unique number for parking spot (primary key)
    private int spotNumber;

    // Type of parking spot
    private SpotType spotType;

    // indicates whether spot is currently occupied or not 
    private boolean occupied;

    // stores info about the vehicle
    private Vehicle vehicle;

    // Parameterized constructor
    public ParkingSpot(int spotNumber,SpotType spotType){
        this.spotNumber = spotNumber;
        this.spotType = spotType;

        // initialized with deafult values
        this.occupied = false;
        this.vehicle = null;
    }

    public int getSpotNumber(){
        return this.spotNumber;
    }

    public SpotType getSpotType(){
        return this.spotType;
    }

    public boolean isOccupied(){
        return this.occupied;
    }

    public Vehicle getVehicle(){
        return this.vehicle;
    }

    // It is used to park the vehicle
    public void parkVehicle(Vehicle vehicle){
        if(this.occupied == true){
            throw new RuntimeException("Parking Spot is alrready occupied");
        }
        else{
            this.vehicle = vehicle;
            this.occupied = true;
        }
    }

    public Vehicle removeVehicle(){
        if(this.occupied == true){
            Vehicle temp = vehicle;
            this.vehicle = null;
            this.occupied = false;

            return temp;
        }
        else{
            throw new RuntimeException("Parking spot is already empty");
        }
    }

    // This method decides whether we can park vehicle at spot or not 
    public abstract boolean canFitVehicle(Vehicle vehicle);

    public void display(){
        System.out.println("Spot : " +spotNumber + "["+ spotType +"]");

        if(this.occupied == true){
            System.out.println("Occupied by : " +vehicle.getVehicleNumber());
        }
        else{
            System.out.println("Spot is available");
        }
    }
} // End of ParkingSpot Class

class BikeSpot extends ParkingSpot{
    public BikeSpot(int spotNumber){
        super(spotNumber,SpotType.BIKE);
    }

    @Override 
    public boolean canFitVehicle(Vehicle vehicle){
        if(vehicle.getVehicleType() == VehicleType.BIKE){
            return true;
        }
        else{
            return false;
        }
    }
}

class CarSpot extends ParkingSpot{
    public CarSpot(int spotNumber){
        super(spotNumber,SpotType.CAR);
    }

    @Override 
    public boolean canFitVehicle(Vehicle vehicle){
        if(vehicle.getVehicleType() == VehicleType.CAR){
            return true;
        }
        else{
            return false;
        }
    }
}

class TruckSpot extends ParkingSpot{
    public TruckSpot(int spotNumber){
        super(spotNumber,SpotType.TRUCK);
    }

    @Override 
    public boolean canFitVehicle(Vehicle vehicle){
        if(vehicle.getVehicleType() == VehicleType.TRUCK){
            return true;
        }
        else{
            return false;
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
// Step 5 : ParkingObserver class
// It is used to automatically update display board when 
// the parking availability changes
// Concepts : Observer Pattern
////////////////////////////////////////////////////////////////////////////

interface ParkingObserver{
    void update();
}

/////////////////////////////////////////////////////////////////////////////
// Step 6 : ParkingFloor class
// It is used to manage parking floor 
// Concepts : Composition,ArrayList,Object Management
////////////////////////////////////////////////////////////////////////////

class ParkingFloor{
    // Unique floor number
    private int floorNumber;

    // Collection of all parking spots
    private List<ParkingSpot> parkingSpots;

    // Collection of observers registered for the floor 
    private List<ParkingObserver> observers;

    // Constructor
    public ParkingFloor(int floorNumber){
        this.floorNumber = floorNumber;

        this.parkingSpots = new ArrayList<>();

        this.observers = new ArrayList<>();
    }

    public int getFloorNumber(){
        return this.floorNumber;
    }

    public void addParkingSpot(ParkingSpot spot){
        parkingSpots.add(spot);
    }

    public void addObserver(ParkingObserver observer){
        observers.add(observer);
    }

    private void notifyObservers(){
        for(ParkingObserver observer : observers){
            observer.update();
        }
    }

    public ParkingSpot findAvailableSpot()
}

class program1000{
        public static void main(String A[]){

    }
}