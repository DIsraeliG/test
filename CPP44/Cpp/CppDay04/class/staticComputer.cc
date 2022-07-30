#include "Computer.hpp"

#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

void test0()
{
    cout << "test0() enter" << endl;
    Computer c1("xiaomiredmi", 6666); 
    cout << "c1: " << endl;
    c1.print();
    cout << endl;
    cout << "sizeof(Computer): " << sizeof(Computer) << endl;
    cout << "sizeof(c1): " << sizeof(c1) << endl;

    Computer c2("huaweimatebook", 8888);
    cout << "c2: " << endl;
    c2.print();
    cout << "test0() exit" << endl;
}

void test1();

int main()
{
    test0();
    test1();
    return 0;
}