# Super Market Billing System
# Overview
This project is a simple supermarket billing system written in C++. The system allows users to add items to a database and print a bill based on the items added. The application uses basic file handling for data storage and retrieval.

# Features
# Add Item:
 Allows users to add items to the database with name, rate, and quantity.
# Print Bill:
 Allows users to print a bill by specifying the item and quantity they want to purchase.
# Exit: 
Exits the application.

# File Structure
# Bill.h: 
 Header file defining the Bill class.
# Bill.cpp:
 Implementation file for the Bill class.
# billsystem.h: 
Header file declaring functions for adding items and printing bills.
# billsystem.cpp: 
 Implementation file for the billing system functions.
# main.cpp:
 Main entry point for the application.
# CMakeLists.txt:
 CMake configuration file for building the project.
# Database.txt:
 File used to store item data (created at runtime).

# How to Build and Run
Clone the Repository:

git clone <repository-url>
cd <repository-directory>

# Build the Project:
```bash
    mkdir build
    cd build
    cmake ..
    make
```
# Run the Application:
```bash
    ./bill
```