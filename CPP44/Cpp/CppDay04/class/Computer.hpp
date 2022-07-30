#ifndef __WD_COMPUTER_HPP__
#define __WD_COMPUTER_HPP__

#include <string.h>

#include <iostream>
using std::cout;
using std::endl;

class Computer
{ 
public:
    // inline函数
    // 在类内部实现的所有函数都是inline函数
    // 
    // 如果函数实现比较简单的,就可以设置为inline函数
    // 如果实现比较复杂,就应该拿到实现文件进行定义
    Computer(const char * brand, double price)
    : _brand(new char[strlen(brand) + 1] ())
    , _price(price)
    {
        cout << "Computer(const char *, double)" << endl;
        strcpy(_brand, brand);
        _totalPrice += _price;
    }

    Computer(const Computer & rhs)
    : _brand(new char[strlen(rhs._brand) + 1] ()) // 先申请空间
    , _price(rhs._price)
    {
        strcpy(_brand, rhs._brand); // 再复制内容，称为深拷贝
        cout << "Computer(const Computer &)" << endl;
    }
    
    Computer & operator=(const Computer & rhs);
    
    void print() // 一个类的实现就是成员函数的实现的过程
    {
        cout << "brand: " << _brand << endl;
        cout << "price: " << _price << endl;
        cout << "totalPrice: " << _totalPrice << endl;
    }

    ~Computer()
    {
        if(_brand){
            delete [] _brand;
            _brand = nullptr; // 释放完毕以后做赋空操作，防止出现野指针
        }
        cout << "~Computer()" << endl;
    }

private: 
    // 在类中要加上static关键字
    static double _totalPrice;

    char * _brand;
    double _price; 
};


#endif