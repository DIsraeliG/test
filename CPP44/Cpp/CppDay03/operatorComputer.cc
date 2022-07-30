#include <iostream>
#include <string.h>

using std::cout;
using std::endl;
// 自定义类的类型
class Computer
{ 
public:
    Computer(const char * brand, double price)
    : _brand(new char[strlen(brand) + 1] ())
    , _price(price)
    {
        cout << "Computer(const char *, double)" << endl;
        strcpy(_brand, brand);
    }

    // 系统提供的拷贝构造函数（浅拷贝）
    // Computer(const Computer & rhs)
    // : _brand(rhs._brand)
    // , _price(rhs._price)
    // {
    //     cout << "Computer(const Computer &)" << endl;
    // }

    Computer(const Computer & rhs)
    : _brand(new char[strlen(rhs._brand) + 1] ()) // 先申请空间
    , _price(rhs._price)
    {
        strcpy(_brand, rhs._brand); // 再复制内容，称为深拷贝
        cout << "Computer(const Computer &)" << endl;
    }

    // 系统提供的赋值运算符函数,不能满足需求
    // Computer & operator=(const Computer & rhs)
    // {
    //     cout << "operator=(const Computer &)" << endl;
    //     _brand = rhs._brand; // 浅拷贝
    //     _price = rhs._price;
    //     return *this;
    // }
    
    void operator=(const Computer & rhs)
    {
        cout << "operator=(const Computer &)" << endl;
        if(this != &rhs){ // 自复制
            delete [] _brand; // 回收左操作数申请的空间
            _brand = new char[strlen(rhs._brand) + 1](); // 深拷贝
            strcpy(_brand, rhs._brand);
            _price = rhs._price;
        }
        // return *this;
    }
    
    void print() // 一个类的实现就是成员函数的实现的过程
    {
        cout << "brand: " << _brand << endl;
        cout << "price: " << _price << endl;
    }

    // 编译器自动提供的析构函数不够用了
    ~Computer()
    {
        if(_brand){
            delete [] _brand;
            _brand = nullptr; // 释放完毕以后做赋空操作，防止出现野指针
        }
        cout << "~Computer()" << endl;
    }

private: // 放在私有区域的成员，都是不希望在类之外访问
    char * _brand; // 8
    double _price; // 8
};

void test0()
{
    cout << "sizeof(Computer): " << sizeof(Computer) << endl;
    Computer c1("xiaomiredmi", 6666); 
    cout << "c1: " << endl;
    c1.print();
    cout << endl;

    Computer c2 = c1; // 调用拷贝构造函数
    cout << "c2: " << endl;
    c2.print();

    Computer c3("huaweimacbook", 8888);
    c3 = c1; // 调用赋值运算符函数，默认情况下用的是浅拷贝
    // c3.operator=(c1); // 是一个成员函数
    cout << "\n执行赋值操作之后：" << endl;
    cout << "c3：";
    c3.print();

    c3 = c3; // 自复制
    // c3 = c2 = c1; // error

    int a = 1, b = 2, c = 3;
    c = a = b;
    cout << "c: " << c << endl;
}

int main()
{
    test0();
    return 0;
}