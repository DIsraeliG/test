#include <iostream>

using std::cout;
using std::endl;

class Point
{
public:
    Point() 
    : _ix(0)
    , _iy(0)
    {
        cout << "Point()" << endl;
    }
    
    Point(int ix, int iy)
    :_ix(ix)
    , _iy(iy)
    {
        cout << "Point(int, int)" << endl;
    
    }
    
    // 编译器自动提供
    Point(const Point & rhs)
    : _ix(rhs._ix)
    , _iy(rhs._iy) 
    {
        cout << "Point(const Point &)" << endl;
    }
    
    void print()
    {
        cout << "(" << _ix
             << ", " << _iy
             << ")" << endl;
    }
    
    ~Point() {cout << "~Point()" << endl;}
    
private:
    int _ix;
    int _iy;
};

void test0()
{
    int x = 1;
    int y = x;
    cout << "x: " << x <<endl;
    cout << "y: " << y <<endl;
    
    Point pt1(1, 2);
    cout << "pt1: ";
    pt1.print();
    cout << endl;
    
    // 用一个已经存在的对象初始化另一个新对象
    // Point pt2 = pt1; // 调用拷贝构造函数
    Point pt2(pt1); // 与上一句等价
    cout << "pt2: ";
    pt2.print();
}

void test1()
{
    int a = 1; // 初始化
    a = 2; // 赋值语句
    
    int b(1);
    cout << "b: " << b << endl;
}

int main()
{
    test0();
    test1();
    return 0;
}