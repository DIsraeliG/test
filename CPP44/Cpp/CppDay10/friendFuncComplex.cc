#include <limits>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

class Complex
{
    friend std::ostream & operator<<(std::ostream & os, const Complex & rhs);
    friend std::istream & operator>>(std::istream & is, Complex & rhs);
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
     
    // 从功能实现的角度来说，返回值可以设置为对象
    // 但会发生拷贝构造，效率低
    // 因此一般情况下，返回引用即可 
    Complex & operator+=(const Complex & rhs)
    {
        cout << "Complex & operator+=(const Complex &)" << endl;
        this->_dreal += rhs._dreal;
        this->_dimag += rhs._dimag;
        return *this;
    }

    // 前置形式，其返回值应该是引用
    Complex & operator++(/* 这里参数是隐含的this指针 */)
    {
        cout << "Complex operator++()" << endl;
        ++this->_dreal; // 针对的是double类型的数据
        ++this->_dimag;
        return *this;
    }

    // 后置形式的自增或自减运算符必须添加一个int参数
    // 该参数并不用来传递具体的值，只是用来与前置形式区分
    // 其返回值形式是对象，return时会执行拷贝构造
    Complex operator++(int)
    {
        cout << "Complex operator++(int)" << endl;
        Complex tmp(*this);
        ++this->_dreal;
        ++this->_dimag;
        return tmp;
    }

private:
    double _dreal; 
    double _dimag;
};

// 总结：三种形式从功能上来说，都是可以的，没有差别
// 但从运算符重载的原则来说，从形式上与内置类型保持一致
// 因此对于双目运算符来说，更趋向于在全局位置提供一个重载版本

// 运算符重载之友元函数
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
    
    // 复合赋值运算符 -= *= /= %=
    c1 += c2;
    cout << "执行完 += 操作之后：";
    // 当表达式执行完毕之后，c1本身的值已经发生了变化
    // 并且c1对象没有被销毁
    cout << "c1: ";
    c1.display();
    cout << endl;

    // 自增自减运算符
    // &(c1++); // error: 右值
    cout << "(c1++): ";
    (c1++).display();
    cout << "c1: ";
    c1.display();
    cout << endl;

    cout << "(++c1): ";
    (++c1).display();
    &(++c1); // 左值
    cout << "c1: ";
    c1.display();
    cout << endl;
}

void test1()
{
    int num = 1;
    cout << &(++num) << endl; // 左值：该表达式在执行过程中不需要申请额外的空间
                              // 前置表达式的效率会更高 
    cout << "&num: " << &num << endl;
    cout << "expr ++number: (++number) = " << (++num) << endl;
    cout << "number: " << num << endl;

    // &(num++); // error: 右值，不能取地址
    cout << "expr number++: (number++) = " << (num++) << endl;
    cout << "number: " << num << endl;
}

std::ostream & operator<<(std::ostream & os, const Complex & rhs)
{
    os << rhs._dreal << " + " << rhs._dimag << "i";
    return os;
}

void readDouble(std::istream & is, double & num){
    cout << "pls input an double number: ";
    // 逗号表达式
    while(is >> num, !is.eof()){
        if(is.bad()){
            cout << "cin has corrupted\n";
            return;
        }else if(is.fail()){
            is.clear();
            is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "pls input a vaild double number: ";
            continue;
        }else{
            cout << "num: " << num << endl;
            break;
        }
    }
}

std::istream & operator>>(std::istream & is, Complex & rhs)
{
    // is >> rhs._dreal;
    readDouble(is, rhs._dreal);
    
    // is >> rhs._dimag;   
    readDouble(is, rhs._dimag);
    
    return is;
}

void test2()
{
    Complex c1(1, 2);
    cout << "c1: " << c1 << endl;
    
    std::cin >> c1;
    cout << "c1: " << c1 << endl;
}

int main()
{
    // test0();
    // test1();
    test2();
    return 0;
}