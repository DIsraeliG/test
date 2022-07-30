#include <iostream>

using std::cout;
using std::endl;

class Empty{
    
};

void test0()
{
    // 空类产生的对象占据1个字节的空间，并不是0
    cout << "sizeof(Empty): " << sizeof(Empty) << endl;
    Empty e1; // 默认构造
    Empty e2 = e1; // 拷贝构造
    
    Empty e3;
    e3 = e1; // 调用赋值运算符函数
    
    cout << "sizeof(e1): " << sizeof(e1) << endl;
}

int main()
{
    test0();
    return 0;
}
// 输出：sizeof(Empty): 1