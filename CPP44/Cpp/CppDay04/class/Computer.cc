#include "Computer.hpp"
#include <iostream>
using std::cout;
using std::endl;

double Computer::_totalPrice = 0;

Computer & Computer::operator=(const Computer & rhs)
{
    cout << "operator=(const Computer &)" << endl;
    if(this != &rhs){ // 自复制
        delete [] _brand; // 回收左操作数申请的空间
        _brand = new char[strlen(rhs._brand) + 1](); // 深拷贝
        strcpy(_brand, rhs._brand);
        _price = rhs._price;
    }
    return *this;
}