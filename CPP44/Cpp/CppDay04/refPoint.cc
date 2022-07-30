#include <iostream>

using std::cout;
using std::endl;

class Point
{
public:
    // 引用成员只能在初始化表达式中进行初始化
    Point(int ix = 0, int iy = 0)
    : _ix(ix)
    , _iy(iy)
    , _iz(ix)
    {
        cout << "Point(int=0, int=0)" << endl;
        // _ix = ix; // error: 赋值语句
        // _iy = iy;
    }
    
    ~Point(){ cout << "~Point()" << endl; }
    void print()
    {
        cout << "(" << _ix 
             << "," << _iy
             << "," << _iz
             << ")" << endl; 
    }
private:
    int _ix;
    int _iy;
    int & _iz; // 占据一个指针的大小
};

void test0()
{
    cout << "sizeof(Point): " << sizeof(Point) << endl;
    Point pt(1, 2);
    pt.print();
}

int main()
{
    test0();
    return 0;
}