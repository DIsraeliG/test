#include <iostream>
using namespace std;

int arr[5] = {1, 2, 3, 4, 5};

// 引用作为函数的返回值，不会进行复制
// 节省开销
// int & getVal(int idx){
//     return arr[idx];
// }

// 不能返回一个局部变量的引用
// int & func1(){
//     // num是一个局部变量，放在栈空间
//     // 返回值是一个引用
//     // 当return完成，func函数退出时
//     // num已经被销毁，实体消失，引用没有意义了
//     int num = 1;
//     return num;
// }

// 不要轻易返回一个堆空间变量的引用
// 除非已经做好了内存回收的策略
int & func2(){
    int *pint = new int(10);
    return *pint;
}

void test0()
{
    // cout << func1() << endl; // error
    
    // cout << getVal(1) << endl;
    // getVal(1) = 10;
    // cout << "arr[1]: " << arr[1] << endl; // arr[1]: 10
    
    int a = 1, b = 2;
    // 完全救不回来，一定会发生内存泄漏
    // cout << func2() << endl;
    // 没有绑定,调用一次就泄露一次
    int c = a + func2() + b;
    
    // 可以救得回来
    // int & ref = func2(); // 对func2函数引用
    // cout << "ref:" << ref << endl;
    // delete (&ref); // 这里&是取地址
}

// void test1()
// {
//     int num = 1;
//     // 非const引用无法绑定到右值
//     // 右值的特点就是不能取地址
//     &func2(); // func2的返回值是一个临时变量，不会持久化存储在内存上，所以无法取地址
//     int & ref2 = 1; // 1是字面值，立即数，不会存储在内存上
//     // const引用可以绑定到右值
//     const int & ref2 = 1;
//     int & ref3 = num; // 非const引用只能绑定到左值
// }

int main()
{
    test0();
    return 0;
}