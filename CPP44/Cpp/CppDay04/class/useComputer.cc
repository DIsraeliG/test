#include "Computer.hpp"
#include <iostream>
using std::cout;
using std::endl;

void test1()
{
    cout << "test1() enter" << endl;
    Computer c1("xiaomiredmi", 6666); 
    cout << "c1: " << endl;
    c1.print();
    cout << endl;
    cout << "test1() exit" << endl;
}