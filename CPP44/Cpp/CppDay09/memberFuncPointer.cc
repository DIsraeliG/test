#include <functional>
#include <iostream>

using std::cout;
using std::endl;

void print()
{ cout << "print()" << endl; }

void show()
{
    cout << "show()" << endl;
    // 局部静态对象
    static int count = 0; // 只有一个
    ++count;
}

class Example
{
public:
    void print(){
        cout << "Example::print()" << endl;
    }

    void show(){
        cout << "Example::show()" << endl;
        // cout << _count << endl; // error
    }

    int _count;
};

typedef void(*Function)(); // 函数指针
typedef void(Example::*func)(); // 成员函数指针

void test0()
{
    Function f1 = print;
    f1();
    f1 = show;
    f1();

    Example e;
    // 对于成员函数的使用需要在类作用域前加上取地址符号
    func f2 = &Example::print;
    // 加上*号使表示指针要进行解引用操作
    (e.*f2)(); // .* 成员指针访问运算符（通过对象调）

    // e.f2(); // error: 如果不加解引用*号，就会将f2当成是对象的数据成员或函数成员
               // 而实际上f2是一个指针

    // 为什么空指针还可以调用函数?
    // 当this指针并不访问数据成员时，它存不存在无所谓，代码可以正常运行
    // 一旦this需要访问具体的数据成员，它就必须要是一个有效的地址值，否则报错
    Example * pe = nullptr;
    f2 = &Example::show;
    (pe->*f2)(); // ->* 成员指针访问运算符（通过指针调）
}

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

    int _count = 0; // 函数调用运算符被调用的次数
};

void test1()
{
    // 成员函数指针访问的调用与函数指针的调用在形式上差异很大
    // 为后续的使用带来很大的麻烦
    // 因此C++11提出std::function
    // std::function是一个函数容器

    Function f0 = print;
    
    std::function<void()> f;
    f = f0; // 用函数指针赋值
    f();

    f = print;
    f();
    f = show; // 用普通函数赋值
    f();

    Example * p = nullptr;
    f = std::bind(&Example::print, p);
    f();

    Example e;
    f = std::bind(&Example::print, p); // 用成员函数赋值
    f();

    Display disp;
    f = disp; // 用函数对象赋值
    f(); 
}

int main()
{
    // test0();
    test1();
    return 0;
}