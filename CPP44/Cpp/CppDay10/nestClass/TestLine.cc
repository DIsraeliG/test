#include "Line.hpp"
#include <iostream>

using std::cout;
using std::endl;

void test0()
{   
    Line line(11, 12, 13, 14);
    line.printLine();
    cout << endl;
}

int main()
{
    test0();
    return 0;
}