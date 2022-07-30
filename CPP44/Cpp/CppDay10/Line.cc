#include <iostream>

using std::cout;
using std::endl;

// 全局类，就在全局的位置
class Line // 外部类
{
    // 成员类型
    // 数据成员
    // 成员函数
// public:
private:
    class PointPimpl; // 设计模式：PIMPL
    PointPimpl * _p; // 编译防火墙
    // 内部类，嵌套类，达到信息隐藏的目的
    class Point // 内部类只为外部类进行服务
    {
    public:
        Point(int ix = 0, int iy = 0) // 有参构造函数
        {
            _ix = ix;
            _iy = iy;
            cout << "Point(int=0, int=0)" << endl;
        }

        ~Point() { cout << "~Point()" << endl; }

        void print() const
        {
            cout << "(" << _ix
                << ", " << _iy
                << ")";
        }
        
    private:
        int _ix;
        int _iy;
    };
public:    
    Line(int x1, int y1, int x2, int y2)
    : _p1(x1, y1)
    , _p2(x2, y2)
    {cout << "Line(int, int, int, int)" << endl; }

    void printLine() const
    {
        _p1.print();
        cout << "--->";
        _p2.print();
    }

private:
    Point _p1;
    Point _p2;
};

void test0()
{
    // Point是Line类中私有的成员类型
    // 只能在类内部访问
    // Line::Point pt1(1, 2), pt2(3, 4);
    // pt1.print();
    // cout << endl;
    
    Line line(11, 12, 13, 14);
    line.printLine();
    cout << endl;
}

int main()
{
    test0();
    return 0;
}