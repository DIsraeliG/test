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
    
    // 以成员函数形式重载，第一个参数是隐含的this指针
    // 因此参数形式上只需要设置一个参数即可，该参数是一个右操作数
    Complex operator+(Complex & rhs)
    {
        cout << "Complex operator+(const Complex & rhs)" << endl;
        return Complex(this->_dreal + rhs._dreal, this->_dimag + rhs._dimag);
    }

private:
    double _dreal;
    double _dimag;
};

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
}

int main()
{
    test0();
    return 0;
}