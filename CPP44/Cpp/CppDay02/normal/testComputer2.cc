#include "Computer.hpp"

#include <iostream>

using std::cout;
using std::endl;

void test1()
{
    cout << "test1()" << endl;
    Computer c1;    
    
    c1.setBrand("huawei");
    c1.setPrice(8888);
    c1.print();
}