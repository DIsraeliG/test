#include <stdlib.h>
#include <iostream>

using std::cout;
using std::endl;

void display()
{ cout << "display()" << endl; }

void show()
{ cout << "show()" << endl; }

void test0()
{
    
}

int main()
{
    cout << "enter main func" << endl;
    test0();
    atexit(display); // 注册display函数，这样在main终止时会调用display函数
                     // 存储的函数是一个栈结构（先登记的后调用）
    atexit(show); // 注册几次就执行几次，不会覆盖
    atexit(show); 
    cout << "exit main func" << endl;
    return 0;
}