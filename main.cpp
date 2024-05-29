#include <iostream>
#include <fstream>
#include <sstream>
#include <chrono>
#include <thread>
#include "Bill.h"
#include "billsystem.h"

int main()
{
    Bill b;  // Declare Bill object

    bool exit = false;
    while (!exit)
    {
        system("clear"); // Use "clear" for Linux
        int val;

        std::cout << "\tWelcome To Super Market Billing System" << std::endl;
        std::cout << "\t**************************************" << std::endl;
        std::cout << "\t\t1. Add Item." << std::endl;
        std::cout << "\t\t2. Print Bill." << std::endl;
        std::cout << "\t\t3. Exit." << std::endl;
        std::cout << "\t\tEnter Choice: ";
        std::cin >> val;

        if (val == 1)
        {
            system("clear");
            addItem(b);
            std::this_thread::sleep_for(std::chrono::seconds(2)); // Sleep for 2 seconds
        }
        else if (val == 2)
        {
            printBill();
        }
        else if (val == 3)
        {
            exit = true;
            std::cout << "\tGood Luck!" << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(2)); // Sleep for 2 seconds
        }
    }
}
