#include "Computer.hpp"

#include <iostream>

using std::cout;
using std::endl;

void test0()
{
    int a; // a也可以称为对象
    Computer c; // c是一个对象
    
    // 在类的大括号之外的地方，都称为类之外
    // 在类之外只能访问public的成员
    c.setBrand("xiaomi");
    c.setPrice(6666);
    c.print();
    
    // c._price = 8888; // error: 在类之外对成员进行保护，实现信息隐藏
}

void test1();

int main()
{
    test0();
    test1();
    return 0;
}