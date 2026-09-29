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

class program996{
        public static void main(String A[]){

    }
}