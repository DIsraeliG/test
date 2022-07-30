#include <iostream>

using std::cout;
using std::endl;

class Point
{
public:
    Point(const Point &) = delete; // 声明该函数已经从本类中删除了
    Point & operator=(const Point &) = delete; 

    static Point * getInstance()
    {
        // 第一次调用该函数时，创建对象
        // 后续的调用都返回一个该对象的指针即可
        if(nullptr == _pInstance){
            _pInstance = new Point(); // 只能创建一个无参的
        }
        
        return _pInstance;
    }
     
    static void destroy()
    {
        if(_pInstance){
            delete _pInstance;
        }
    }
    
    void init(int ix, int iy)
    {
        _ix = ix;
        _iy = iy;
    }
    
    void print() const
    {
        cout << "void print()" << endl;
        cout << "(" << _ix 
             << "," << _iy
             << ")" << endl; 
    }

private:
    Point()
    : _ix(0)
    , _iy(0)
    {
        cout << "Point()" << endl;
    }
    ~Point(){ cout << "~Point()" << endl; }

private: 
    int _ix;
    int _iy;
    static Point * _pInstance;
};

Point * Point::_pInstance = nullptr;

// Point pt2(2, 3); // error

/*
void test0()
{
    Point pt1; // error
    // 在类之外要调用构造函数
    // Point pt(1, 2); // error
    // Point pt2(1, 2); // error
    
    // Point * pt = new Point(3, 4); // error
}
*/

void test1()
{
    // 1. 先创建对象
    Point * pt = Point::getInstance(); // 回到可以创建无数个对象
    // 2. 初始化数据成员
    pt->init(1, 2); // 有两步操作完成对象的初始化，因此称为二段式构造
    pt->print();
    cout << "&pt: " << &pt << endl;
    
    Point * pt2 = Point::getInstance();
    cout << "&pt2: " << &pt << endl;
    pt2->print();

    Point::getInstance()->print();
    
    Point::destroy();
}

int main()
{
    test1();
    return 0;
} 