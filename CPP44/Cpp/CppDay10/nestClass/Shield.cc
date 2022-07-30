#include <iostream>

using std::cout;
using std::endl;

int num = 1;

namespace wd
{

int num = 2;

class Example
{
public:
    Example() = default;

    // 就近原则
    void display(int num)
    {
        // 发生了屏蔽现象
        cout << "number: " << num << endl;
        cout << "数据成员number: " << this->num << endl;
        cout << "数据成员number: " << Example::num << endl;
        cout << "wd::number: " << wd::num << endl;
        cout << "全局变量number: " << ::num << endl;
    }
private:
    int num = 3;
};
} // end of namespace wd

void test0()
{
    wd::Example e;
    int num = 11;
    e.display(num);
}

int main()
{
    test0();
    return 0;
}