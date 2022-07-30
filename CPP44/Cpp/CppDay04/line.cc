// 子对象的初始化
#include <iostream>

using std::cout;
using std::endl;

class Point
{
public:
    Point(int ix = 0, int iy = 0)
    :_ix(ix)
    ,_iy(iy)
    {
        cout << "Point(int=0, int=0)" << endl;
    }
    
    ~Point(){ cout << "~Point()" << endl; }

    Point(const Point & rhs)
    : _ix(rhs._ix)
    , _iy(rhs._iy)
    {
        cout << "Point(const Point &)" << endl;
    }

    void print()
    {
        cout << "(" << _ix 
             << "," << _iy
             << ")"; 
    }
private:
    const int _ix;
    const int _iy;
};

class Line
{
public:
    Line(int x1, int y1, int x2, int y2)
    // 当子对象没有显式进行初始化时，也会自动调用相应类型的默认（无参）构造函数
    :_p1(x1, y1) // 如果不希望调用默认构造函数，就需要显式调用相应类型的有参构造函数
    ,_p2(x2, y2)
    {
        cout << "Line(int, int, int, int)" << endl;
    }
    void print()
    {
        _p1.print();
        cout << "---->";
        _p2.print();
        cout << endl;
    }
    
    Line(Point p1, Point p2)
    :_p1(p1) // 调用拷贝构造函数
    ,_p2(p2)
    {
        cout << "Line(Point, Point)" <<endl;
    }
    ~Line() { cout << "~Line()" << endl; }
private:
    Point _p1; // 子对象是一个自定义类型
    Point _p2;
};

void test0()
{
    Line line(1, 2, 3, 4);
    line.print();
    
    cout << endl;
    Line line2(Point(11, 12), Point(21, 22));
    line2.print();
}

int main()
{
    test0();
    return 0;
}