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
    // 编译器自动提供
    // operator关键字
    // 将运算符泛化成一个函数时，必须要使用关键字
    // 将运算符看成是一个函数
    // Point & operator=(const Point & rhs)
    // {
    //     cout << "operator=(const Point &)" << endl;
    //     _ix = rhs._ix;
    //     _iy = rhs._iy;

    //     return *this;
    // }
    
    // this指针编译器自动填充
    void print(/* Point * const this */)
    {
        // this = 0x1000; // error: this指针是一个指针常量
        cout << "(" << this->_ix
             << ", " << this->_iy
             << ")" << endl;
    }
    
    ~Point() {cout << "~Point()" << endl;}
    
private:
    int _ix;
    int _iy;
};

void test1()
{
    int a = 1; // 初始化
    a = 2; // 赋值语句
    
    int b(1);
    cout << "b: " << b << endl;

    int c = a;

    a = b; // 复制，通过赋值的形式进行复制（副本）

    cout << "sizeof(Point): " << sizeof(Point) << endl;
    Point p1(1, 2);
    cout << "p1: ";
    p1.print(); // p1.print(&p1) ==> Point::print(&p1) 
    cout << endl;
    Point p2(3, 4);
    cout << "p2: ";
    p2.print(); // p2.print(&p2) ==> Point::print(&p1)

    // 正确的说法：将p1对象赋值给p2对象
    // 错误的说法：p2等于p1
    p2 = p1; // 这里调用了赋值运算符函数，简写
    // p2.operator=(p1); // 上一句等价于这句

    cout << "进行赋值操作之后：";
    cout << "p2: ";
    p2.print();
}

int main()
{
    // test0();
    test1();
    return 0;
}