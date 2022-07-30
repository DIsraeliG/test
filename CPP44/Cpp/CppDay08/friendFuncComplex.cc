#include <iostream>

using std::cout;
using std::endl;

class Complex
{
    friend Complex operator+(const Complex & lhs, const Complex & rhs);
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
    
    // 总结：三种形式从功能上来说，都是可以的，没有差别
    // 但从运算符重载的原则来说，从形式上与内置类型保持一致
    // 因此对于双目运算符来说，更趋向于在全局位置提供一个重载版本
    
    // 运算符重载之友元函数
    // Complex operator+(cos)   
    // // 从功能实现的角度来说，返回值可以设置为对象
    // Complex & operator+(const Complex & rhs)
    // {
    //     this->_dreal += rhs._dreal;
    //     this->_dimag += rhs._dimag;
    //     return *this;
    // }
private:
    double _dreal; 
    double _dimag;
};

Complex operator+(const Complex & lhs, const Complex & rhs)
{
    cout << "friend Complex operator+(lhs, rhs)" << endl;
    return Complex(lhs._dreal + rhs._dreal, lhs._dimag + rhs._dimag);
}

void test0()
{
    Complex c1(1, 2), c2(2, 3);
    cout << "c1: ";
    c1.display();
    cout << "c2: ";
    c2.display();
    cout << "operating add: ";
    Complex c3 = c1 + c2; 
    c3.display();
    
    // 复合赋值运算符
    // c1 += c2;
    // 当表达式执行完毕之后，c1本身的值已经发生了变化
}

int main()
{
    test0();
    return 0;
}