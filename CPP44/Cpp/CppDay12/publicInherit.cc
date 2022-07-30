#include <iostream>

using std::cout;
using std::endl;

class Point
{
public:
    Point(int ix = 0, int iy = 0)
    : _ix(ix)
    , _iy(iy)
    { cout << "Point(int=0, int=0)" << endl; }

    void print() const
    {
        cout << "(" << _ix
             << "," << _iy
             << ")" << endl;
    }

protected: // 只能在派生类内部访问
    int _ix;
    int getY() const { return _iy; }

private: // 只能在本类内部访问，限制最严格
    int _iy;
};

class Point3D
: public Point // 公有继承，对于基类的非私有成员，在派生类内部访问权限不变
               // 公有继承又叫接口继承
{
public:
    Point3D(int ix, int iy, int iz)
    : Point(ix, iy)
    , _iz(iz)
    { cout << "Point3D(int, int, int)" << endl; }

    void display() const
    {
        cout << "(" << _ix // protected
            //  << "," << _iy // error
             << "," << getY() // protected
             << "," << _iz
             << ")" << endl;
    }
private:
    int _iz;
};

void test0()
{
    Point pt(1, 2);
    // cout << pt._ix << endl; // error

    cout << "sizeof(Point): " << sizeof(Point) << endl; 
    cout << "sizeof(Point3D): " << sizeof(Point3D) << endl; 

    Point3D pt2(1, 2, 3);
    cout << "pt2.print(): ";
    pt2.print(); // public
    cout << endl;
    cout << "pt2.display()";
    pt2.display();
}

int main()
{
    test0();
    return 0;
}