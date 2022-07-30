#include <iostream>

using std::cout;
using std::endl;

class Base
{
public:
    Base(int base = 0)
    // Base(int base) // error
    : _base(base)
    { cout << "Base(int=0)" << endl; }
    
    void print() const
    { cout << "Base::_base: " << _base << endl; }
protected:
    int _base;
};

class Derived
// : Base // 不写继承方式时，默认继承方式是private
: public Base
{
public:
    // 1. 当派生类没有显式定义构造函数时，在初始化（派生类中的)基类部分时，会直接调用基类的默认构造函数
    // 如果基类没有提供默认构造函数，就会报错
private:
    int _derived;
};

void test0()
{
    Derived d;
    d.print();
}

int main()
{
    test0();
    return 0;
}