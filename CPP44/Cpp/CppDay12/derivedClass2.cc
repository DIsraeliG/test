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

    ~Base() { cout << "~Base()" << endl; }
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

    // 无参构造函数
    Derived()
    : Base() // 基类部分的初始化需要在派生类构造函数的初始化列表中进行
             // 即使不写，也会自动调用基类默认构造函数
    , _derived(0)
    { cout << "Derived()" << endl; }

    Derived(int base, int derived)
    : Base(base) // 2. 如果不希望调用基类的默认构造函数，则必须要在派生类构造函数的初始化表达式中显式调用基类有参构造函数
    , _derived(derived)
    {
        cout << "Derived(int, int)" << endl;
    }

    // 当派生类对象被销毁时，派生类析构函数自动调用，完成派生类部分的销毁；
    // 之后会自动调用基类的析构函数，完成基类部分的销毁
    ~Derived() { cout << "~Derived()" << endl; }

    void display() const
    {
        print();
        cout << "Derived::_derived: " << _derived << endl;
    }
private:
    int _derived;
};

void test0()
{
    Derived d;
    d.print();

    cout << endl;
    d.display();

    Derived d1(11, 12);
    d1.display();
}

int main()
{
    test0();
    return 0;
}