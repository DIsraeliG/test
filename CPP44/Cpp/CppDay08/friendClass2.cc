#include <math.h>
#include <iostream>

using std::cout;
using std::endl;

class Point; // 类的前向声明，告诉编译器这是一个class
             // 至于类中有什么数据成员是不确定的
             // 因此类所占据的空间是不知道的	

class Line
{
    // 友元关系是单向的
    // 如果要变成双向的关系，必须要相互声明为对方的友元
    friend Point; // Point此时才能在Line类之外访问Line类中的私有成员
public:
    double distance(const Point & lhs, const Point & rhs);
    void setPoint(Point & pt, int ix, int iy);
    void displayPoint(const Point & pt);
private:
    int _iz;
};

class Point 
{
    // 提出问题：Point是否是Line的友元？
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

    void setX(Line & line, int iz)
    {
        // 在Point的成员函数想要访问Line类的私有成员
        line._iz = iz; 
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