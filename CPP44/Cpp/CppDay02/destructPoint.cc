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
    
    void print()
    {
        cout << "(" << _ix
             << ", " << _iy
             << ")" << endl;
    }
    // 当没有显式提供析构函数时，编译器也会自动生成一个
    // ~Point(){}
    ~Point() {cout << "~Point()" << endl;}
    
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
    
    pt2.~Point(); // 析构函数可以显式调用，但是不推荐
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