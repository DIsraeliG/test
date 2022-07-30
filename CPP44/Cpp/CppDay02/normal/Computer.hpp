#ifndef __WD_COMPUTER_HPP__
#define __WD_COMPUTER_HPP__
#include <iostream>
#include <string.h>

using std::cout;
using std::endl;
// 类的声明
class Computer
{ // 大括号范围以内称为类内部
// 类默认情况下的访问权限是private
public: // 类对外提供的接口
    void setBrand(const char *brand);
    void setPrice(double price);
    
    void print();
    
private: // 放在私有区域的成员，都是不希望在类之外访问
    char _brand[20];
    double _price;
};


#endif