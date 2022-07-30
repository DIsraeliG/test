#include <iostream>

using std::cout;
using std::endl;

class Point
{
public:
    Point() // 无参（默认）构造函数
    : _ix(0)
    , _iy(0) // 初始化表达式(初始化列表)
    {
        cout << "Point()" << endl;
        // _ix = 0; // 不是初始化，是一个赋值语句
        // _iy = 0;
    }
    // 当显式定义了有参构造函数之后，编译器不会再自动生成默认构造函数了
    // 此时需要显式定义默认构造函数才能生成相应的对象
    Point(int ix, int iy)
    : _ix(ix)
    , _iy(iy)
    {
        cout << "Point()" << endl;
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
    
    Point pt2(1, 2);
    cout << "pt2: ";
    pt2.print();
}

void test1()
{
    int a = 1; // 初始化
    a = 2; // 赋值语句 
    
    int b(1); // 初始化
    cout << "b: " << b << endl;
}

int main()
{
    // test0();
    test1();
    return 0;
}