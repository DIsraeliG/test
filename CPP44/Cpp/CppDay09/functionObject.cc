#include <iostream>
using std::cout;
using std::endl;

// 重载了函数调用运算符的类创建的对象，称为函数对象
class Display
{
public:
    int operator()(){
        cout << "Display::operator()()" << endl;
        ++_count;
        return 0;
    }

    int operator()(int x, int y, int z){
        cout << "Display::operator()(int, int, int)" << endl;
        ++_count;
        return x + y + z;
    }

    int getCount() const { return _count; }

// 数据成员可以保存函数的状态
// 有状态的函数
    int _count = 0; // 函数调用运算符被调用的次数
};

// 函数类型就是具有相同的返回值，具有相同的形参列表的就是同一类函数
// 在面向对象的世界中，一切皆对象
typedef void(*Function)(); // 函数指针

// 成员函数指针

// 普通函数/自由函数
// 无状态的函数
void print()
{ cout << "print()" << endl; }

void show()
{
    cout << "show()" << endl;
    // 局部静态对象
    static int count = 0; // 只有一个
    ++count;
}

void test0()
{
    Function pf = print; // print就是一个具体的对象
    pf();

    pf = show; // show就是一个具体的对象

    // 函数本身也可以当成一个对象来看待
    print(); // 函数对象
    show();

    Display display; // 可以有无数个
    Display d1; // 又有了新的count
    cout << display() << endl;
    cout << display(1, 2, 3) << endl;
    cout << "display._count: " << display._count << endl;
}

int main(void)
{
    test0();
    return 0;
}