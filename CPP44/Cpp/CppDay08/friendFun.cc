#include <math.h>
#include <iostream>

using std::cout;
using std::endl;

class Point 
{
    friend double distance(const Point & lhs, const Point & rhs);
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

// 在一个普通函数内部访问类的私有成员
double distance(const Point & lhs, const Point & rhs)
{
    return sqrt((lhs._ix - rhs._ix) * (lhs._ix - rhs._ix) + 
                (lhs._iy - rhs._iy) * (lhs._iy - rhs._iy));
}

void test0()
{
    Point pt1(1, 2), pt2(3, 4);
    pt1.print();
    cout << "===>";
    pt2.print();
    cout << "的距离：" << distance(pt1, pt2) << endl;
}

int main()
{
    test0();
    return 0;
}