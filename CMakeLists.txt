cmake_minimum_required(VERSION 3.16.3)

# Project name and version
project(Bill_system VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable target
add_executable(bill
   main.cpp
   Bill.cpp
   # printbill.cpp
   # additem.cpp
   billsystem.cpp
)

# Include the current directory to find header files
target_include_directories(bill PUBLIC "${PROJECT_SOURCE_DIR}")