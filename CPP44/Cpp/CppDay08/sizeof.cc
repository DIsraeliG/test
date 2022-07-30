#include <iostream>

using std::cout;
using std::endl;

void test0()
{
    int length = sizeof(int);
    // 发生的时机是在编译时，已经经过计算得到了长度
    printf("%d\n", sizeof length); // 长度运算符
}

int main()
{
    test0();
    return 0;
}