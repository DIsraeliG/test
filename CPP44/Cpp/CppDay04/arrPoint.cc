#include <iostream>

using std::cout;
using std::endl;

class Point
{
public:
    // const成员只能在初始化表达式中进行初始化
    Point(int ix = 0, int iy = 0)
    : _ix(ix)
    , _iy(iy)
    {
        cout << "Point(int=0, int=0)" << endl;
    }
    
    ~Point(){ cout << "~Point()" << endl; }
    
    void print() const
    {
        cout << "void print() const" << endl;
        cout << "(" << _ix 
             << "," << _iy
             << ")" << endl; 
    }
    
private:
    int _ix;
    int _iy;
};

void test0()
{
    // Point points[5];
    // cout << "points[0]: ";
    // points[0].print();

    Point points[5] = {
        Point(1,2), 
        Point(3,4), 
        Point(5,6)
    };

    for(int i = 0; i < 5; i++){
        cout << "points[" << i << "]";
        points[i].print();
        cout << endl;
    }
}

int main()
{
    test0();
    return 0;
}