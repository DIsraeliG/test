#include <iostream>

using std::cout;
using std::endl;

class Complex
{
public:
    Complex(double dreal = 0, double dimag = 0)
    : _dreal(dreal)
    , _dimag(dimag)
    {
        cout << "Complex(double=0, double=0)" << endl;
    }

    ~Complex(){ cout << "~Complex()" << endl; }

    void display() const
    {
        cout << _dreal << " + " 
             << _dimag << "i" << endl;
    }

    // get系列函数
    double real() const { return _dreal; }
    double imag() const { return _dimag; }

    // set系列函数
    void setReal(double real) { _dreal = real; }
    void setImage(double image) { _dimag = image; }  

private:
    double _dreal;
    double _dimag;
};

// 运算符重载之普通函数形式
Complex operator+(const Complex & lhs, const Complex & rhs)
{
    return Complex(lhs.real() + rhs.real(), lhs.imag() + rhs.imag());
}

// 内置类型的运算符不可以重载
// int operator+(int x, int y)
// { return x - y; } // error：参数类型必须是自定义类的类型或枚举类型


void test0()
{
    Complex c1(1, 2), c2(2, 3);
    cout << "c1: ";
    c1.display();
    cout << "c2: ";
    c2.display();
    cout << "operating add:\n ";
    Complex c3 = c1 + c2; // 没有重载+时，这里编译报错
    c3.display();
}

int main()
{
    test0();
    return 0;
}