#include "billsystem.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <chrono>
#include <thread>

void addItem(Bill &b) // Pass by reference
{
    bool close = false;
    while (!close)
    {
        int choice;
        std::cout << "\t1. Add." << std::endl;
        std::cout << "\t2. Close." << std::endl;
        std::cout << "\tEnter Choice: ";
        std::cin >> choice;

        if (choice == 1)
        {
            system("clear"); 
            std::string item;
            int rate, quant;

            std::cout << "\tEnter Item Name: ";
            std::cin >> item;
            b.setItem(item);

            std::cout << "\tEnter Rate Of Item: ";
            std::cin >> rate;
            b.setRate(rate);

            std::cout << "\tEnter Quantity Of Item: ";
            std::cin >> quant;
            b.setQuant(quant);

            std::ofstream out("Database.txt", std::ios::app);
            if (!out)
            {
                std::cout << "\tError: File Can't Open!" << std::endl;
            }
            else
            {
                out << "\t" << b.getItem() << " : " << b.getRate() << " : " << b.getQuant() << std::endl;
            }
            out.close();
            std::cout << "\tItem Added Successfully" << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(2)); 
        }
        else if (choice == 2)
        {
            system("clear"); 
            close = true;
            std::cout << "\tBack To Main Menu!" << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(2)); 
        }
    }
}

void printBill()
{
    system("clear"); 
    int count = 0;
    bool close = false;
    while (!close)
    {
        system("clear"); 
        int choice;
        std::cout << "\t1. Add Bill." << std::endl;
        std::cout << "\t2. Close Session." << std::endl;
        std::cout << "\tEnter Choice: ";
        std::cin >> choice;

        if (choice == 1)
        {
            std::string item;
            int quant;
            std::cout << "\tEnter Item: ";
            std::cin >> item;
            std::cout << "\tEnter Quantity: ";
            std::cin >> quant;

            std::ifstream in("Database.txt");
            std::ofstream out("Database Temp.txt");

            std::string line;
            bool found = false;

            while (getline(in, line))
            {
                std::stringstream ss(line);
                std::string itemName;
                int itemRate, itemQuant;
                char delimiter;
                ss >> itemName >> delimiter >> itemRate >> delimiter >> itemQuant;

                if (item == itemName)
                {
                    found = true;
                    if (quant <= itemQuant)
                    {
                        int amount = itemRate * quant;
                        std::cout << "\t Item | Rate | Quantity | Amount" << std::endl;
                        std::cout << "\t" << itemName << "\t " << itemRate << "\t " << quant << "\t " << amount << std::endl;
                        int newQuant = itemQuant - quant;
                        itemQuant = newQuant;
                        count += amount;

                        out << "\t" << itemName << " : " << itemRate << " : " << itemQuant << std::endl;
                    }
                    else
                    {
                        std::cout << "\tSorry, " << item << " Ended!" << std::endl;
                    }
                }
                else
                {
                    out << line << std::endl;
                }
            }
            if (!found)
            {
                std::cout << "\tItem Not Available!" << std::endl;
            }
            out.close();
            in.close();
            remove("Database.txt");
            rename("Database Temp.txt", "Database.txt");
        }
        else if (choice == 2)
        {
            close = true;
            std::cout << "\tCounting Total Bill" << std::endl;
        }
        std::this_thread::sleep_for(std::chrono::seconds(2)); 
    }
    system("clear"); 
    std::cout << std::endl << std::endl;
    std::cout << "\t Total Bill ----------------- : " << count << std::endl << std::endl;
    std::cout << "\tThanks For Shopping!" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(5)); 
}