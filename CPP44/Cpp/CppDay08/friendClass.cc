#include <math.h>
#include <iostream>

using std::cout;
using std::endl;

class Point; // 类的前向声明，告诉编译器这是一个class
             // 至于类中有什么数据成员是不确定的
             // 因此类所占据的空间是不知道的	

class Line
{
public:
    // 在一个成员函数内部访问类的私有成员
    // 参数传递时，写Point是不行的，因为不知道Point的类型大小
    // 参数传递时，写Point&是可行的，因为引用占据的空间是确定的，就是一个指针的大小
    double distance(const Point & lhs, const Point & rhs);
    void setPoint(Point & pt, int ix, int iy);
    void displayPoint(const Point & pt);
};

class Point 
{
    // friend double Line::distance(const Point & lhs, const Point & rhs);
    // friend void Line::setPoint(Point & pt, int ix, int iy);
    // friend void Line::displayPoint(const Point & pt);
    friend Line; // 整个line类都是Point的友元，即所有的成员函数都可以直接访问私有数据成员
public:
    Point(int ix = 0, int iy = 0)
    :_ix(ix)
    ,_iy(iy)
    {
        cout << "Point(int=0, int=0)" << endl;
    }
    
    ~Point(){ cout << "~Point()" << endl; }
    
    void print() const{
        cout << "(" << _ix
             << "," << _iy
             << ")";
    }
private:
    int _ix;
    int _iy;
};

double Line::distance(const Point & lhs, const Point & rhs)
{
    return sqrt((lhs._ix - rhs._ix) * (lhs._ix - rhs._ix) + 
                (lhs._iy - rhs._iy) * (lhs._iy - rhs._iy));
}

void Line::setPoint(Point & pt, int ix, int iy)
{
    pt._ix = ix;
    pt._iy = iy;
}

void Line::displayPoint(const Point & pt)
{
    cout << "(" << pt._ix
         << "," << pt._iy
         << ")";
}

void test0()
{
    Point pt1(1, 2), pt2(3, 4);
    pt1.print();
    cout << "===>";
    pt2.print();
    cout << "的距离：" << Line().distance(pt1, pt2) << endl;

    Line().setPoint(pt1, 11, 12);
    cout << "pt1: ";
    pt1.print();
    cout << endl;
}

int main()
{
    test0();
    return 0;
}