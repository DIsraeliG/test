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
        _totalPrice += _price;
    }

    Computer(const Computer & rhs)
    : _brand(new char[strlen(rhs._brand) + 1] ()) // 先申请空间
    , _price(rhs._price)
    {
        strcpy(_brand, rhs._brand); // 再复制内容，称为深拷贝
        cout << "Computer(const Computer &)" << endl;
    }
    
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
        cout << "totalPrice: " << _totalPrice << endl;
    }
    
    // 静态成员函数没有隐含的this指针
    static void printTotalPrice()
    {
        // cout << _brand; // error
        cout << "_totalPrice: " << _totalPrice << endl;
        // this->print(); // error 
    }

    ~Computer()
    {
        if(_brand){
            delete [] _brand;
            _brand = nullptr; // 释放完毕以后做赋空操作，防止出现野指针
        }
        cout << "~Computer()" << endl;
    }

private: 
    // 在类中要加上static关键字
    static double _totalPrice;

    char * _brand;
    double _price; 
};

double Computer::_totalPrice = 0;

void test0()
{
    Computer c1("xiaomiredmi", 6666); 
    cout << "c1: " << endl;
    c1.print();
    // c1.printTotalPrice();
    // 静态成员函数可以直接通过类名调用
    Computer::printTotalPrice();
    cout << endl;
    cout << "sizeof(Computer): " << sizeof(Computer) << endl;
    cout << "sizeof(c1): " << sizeof(c1) << endl;

    Computer c2("huaweimatebook", 8888);
    cout << "c2: " << endl;
    c2.print();
    // c2.printTotalPrice();
    Computer::printTotalPrice();

    // 对于静态私有数据,不能在类之外进行访问
    // cout << Computer::_totalPrice << endl; // error
}

int main()
{
    test0();
    return 0;
}