#include <iostream>

using std::cout;
using std::endl;

void test0()
{
    bool b1 = 0;
    bool b2 = 1;
    bool b3 = 3;
    bool b4 = -1;
    bool b5 = true;
    bool b6 = false;
    cout << "sizeof(bool):" << sizeof(bool) << endl;
    cout << "b1:" << b1 << endl;
    cout << "b2:" << b2 << endl;
    cout << "b3:" << b3 << endl;
    cout << "b4:" << b4 << endl;
    cout << "b5:" << b5 << endl;
    cout << "b6:" << b6 << endl;
}

int main()
{
    test0();
    return 0;
}