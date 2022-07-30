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
    Point(const Point & rhs) // error：非法
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

// 值传递
void getPoint(Point pt)
{
    cout << "pt: ";
    pt.print();
}

// 返回值是对象
Point func()
{
    Point p(3, 4);
    cout << "func: p";
    p.print();
    return p; // 执行return语句时，发生了复制
}

void test3()
{
    // &1; // error: 无法对字面值1取地址，称为右值
    // int & ref = 1; // error: 非const引用不能绑定到右值rvalue

    // 非const引用只能绑定到左值lvalue
    int num = 1; // num是左值，可以取地址就称为左值
    int & ref2 = num;
    &ref2; // 左值

    // &func(); // error: 不能取地址，右值
    // Point & rhs = func(); // 临时对象，即将被销毁的对象
    // Point pt = func(); // error：调用拷贝构造函数，但func()是右值
    {
    cout << "test3()" << endl;
    Point (2, 3); // 匿名对象，即将被销毁的对象，也是右值
    cout << "block" << endl;
    }

    // const引用称为万能引用
    // 它既可以绑定到左值，又可以绑定到右值
    const Point & rhs = Point(1, 2);
    &rhs; // 左值

    Point pt = Point(1, 2); // 调用拷贝构造函数
}

void test2()
{
    Point p(1, 2);
    getPoint(p);
}

int main()
{
    // test0();
    // test1();
    // test2();
    test3();
    return 0;
}