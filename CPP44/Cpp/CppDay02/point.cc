#include <iostream>

using std::cout;
using std::endl;

class Point
{
public:
    // Point() // 无参（默认）构造函数
    // {
    //     cout << "Point()" << endl;
    //     _ix = 0;
    //     _iy = 0;
    // }
    // 当显式定义了有参构造函数之后，编译器不会再自动生成默认构造函数了
    // 此时需要显式定义默认构造函数才能生成相应的对象
    Point(int ix = 0, int iy = 0) // 有参构造函数
    {
        _ix = ix;
        _iy = iy;
        cout << "Point(int, int)" << endl;
    }
    // 当类中没有显示定义构造函数时，编译器会自动生成一个默认构造函数
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
    Point pt; // 自动调用无参构造函数
    pt.print();
    
    Point pt2(1, 2); // 显式调用有参构造函数
    cout << "pt2: ";
    pt2.print();
}

int main()
{
    test0();
    return 0;
}