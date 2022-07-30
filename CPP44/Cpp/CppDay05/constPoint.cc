#include <iostream>

using std::cout;
using std::endl;

class Point
{
public:
    // const成员只能在初始化表达式中进行初始化
    explicit // 告诉编译器该函数只能显式调用，不能隐式调用
    Point(int ix = 0, int iy = 0)
    :_ix(ix)
    ,_iy(iy)
    {
        cout << "Point(int=0, int=0)" << endl;
    }
    
    ~Point(){ cout << "~Point()" << endl; }
    
    // 非const版本
    // void print(/*Point * const this*/)
    // {
    //     cout << "void print()" << endl;
    //     _ix = 10;
    //     cout << "(" << _ix 
    //          << "," << _iy
    //          << ")" << endl; 
    // }
    
    // const成员函数
    // 加上const之后，其实是对this指针的形态进行了修改
    // this指针是双重限定，在其*的左右两边都有const
    void print(/* const Point * const this */) const
    {
        // 不能修改数据成员的值，因为this指针发生了变化
        // _ix = 10; // error
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
    // 当类中同时提供const和非const版本的成员函数时，是交给不同的对象进行调用的
    // const对象调用const版本的成员函数
    // 非const对象调用非const版本的成员函数
    Point pt(1, 2);
    pt.print(); // 调用的是非const版本
    
    cout << "\n" << endl;
    cout << "pt2: ";
    const Point pt2(3, 4);
    pt2.print(); // pt.print() const
}

void test1()
{
    // Point = int
    // 从逻辑上来说，不能执行
    Point pt = 1; // 这里发生了隐式转换 // error
    // 上面等价于Point pt = Point(1);
    cout << "pt: ";
    pt.print();
}

int main()
{
    // test0();
    test1();
    return 0;
}