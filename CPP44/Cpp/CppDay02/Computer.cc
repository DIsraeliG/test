#include <iostream>
#include <string.h>

using std::cout;
using std::endl;
// 自定义类的类型
class Computer
{ // 大括号范围以内称为类内部
// 类默认情况下的访问权限是private
public: // 类对外提供的接口
    void setBrand(const char *brand);
    void setPrice(double price);
    
    void print();
    
private: // 放在私有区域的成员，都是不希望在类之外访问
    char _brand[20];
    double _price;
};

void Computer::setBrand(const char *brand)
{
    strcpy(_brand, brand);
}
    
void Computer::setPrice(double price)
{
    _price = price;
}

void Computer::print()
{
    cout << "brand: " << _brand << endl;
    cout << "price: " << _price << endl;
}

void test0()
{
    int a; // a也可以称为对象
    Computer c; // c是一个对象
    
    // 在类的大括号之外的地方，都称为类之外
    // 在类之外只能访问public的成员
    c.setBrand("xiaomi");
    c.setPrice(6666);
    c.print();
    
    // c._price = 8888; // error: 在类之外对成员进行保护，实现信息隐藏
}

int main()
{
    test0();
    return 0;
}