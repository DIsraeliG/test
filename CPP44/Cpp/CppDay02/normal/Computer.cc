#include "Computer.hpp"
#include <iostream>

using std::cout;
using std::endl;

void Computer::setBrand(const char *brand)
{
    strcpy(_brand, brand);
}
    
void Computer::setPrice(double price)
{
    _price = price;
}

void Computer::print()
{
    cout << "brand: " << _brand << endl;
    cout << "price: " << _price << endl;
}