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
    Computer c1("xiaomi", 6666); 
    cout << "c1: " << endl;
    c1.print();
    cout << endl;

    Computer c2 = c1; // 调用拷贝构造函数
    cout << "c2: " << endl;
    c2.print();
}

int main()
{
    test0();
    return 0;
}