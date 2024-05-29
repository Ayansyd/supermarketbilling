#ifndef BILL_H
#define BILL_H

#include <string>

class Bill
{
private:
    std::string Item;
    int Rate, Quantity;

public:
    Bill() : Item(""), Rate(0), Quantity(0) {}

    void setItem(const std::string &item)
    {
        Item = item;
    }

    void setRate(int rate)
    {
        Rate = rate;
    }

    void setQuant(int quant)
    {
        Quantity = quant;
    }

    std::string getItem() const
    {
        return Item;
    }

    int getRate() const
    {
        return Rate;
    }

    int getQuant() const
    {
        return Quantity;
    }
};

#endif // BILL_H
