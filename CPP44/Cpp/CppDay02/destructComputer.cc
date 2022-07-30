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

// 全局对象
Computer c2("huawei", 9999);
static Computer c3("Lenovo", 7777);

void test0()
{
    cout << "sizeof(Computer): " << sizeof(Computer) << endl;
    Computer c1("xiaomi", 6666); 
    c1.print();
    static Computer c4("dell", 6777); //局部静态对象

    Computer *pc = new Computer("hp", 5555); // 堆对象

    delete pc;
}

int main()
{
    test0();
    return 0;
}