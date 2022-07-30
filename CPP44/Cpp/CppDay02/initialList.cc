#include <iostream>

using std::cout;
using std::endl;

class Example
{
public:
    Example(int x)
    : _iy(x)
    , _ix(_iy)
    { cout << "Example()" << endl; }
    
    void print()
    {
        cout << "(" << _ix
             << ", " << _iy
             << ")" << endl;
    }
private:
    int _ix;
    int _iy;
};

void test0()
{
    Example e(1);
    e.print(); // output: (22042, 1)
}

int main()
{
    test0();
    return 0;
}