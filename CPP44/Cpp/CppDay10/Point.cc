#include <iostream>

using std::cout;
using std::endl;

// 全局类，就在全局的位置
class Line{
public:
    // 内部类，嵌套类
    class Point
    {
    public:
        Point(int ix = 0, int iy = 0) // 有参构造函数
        {
            _ix = ix;
            _iy = iy;
            cout << "Point(int, int)" << endl;
        }
        // 当类中没有显示定义构造函数时，编译器会自动生成一个默认构造函数
        void print() const
        {
            cout << "(" << _ix
                << ", " << _iy
                << ")" << endl;
        }
        
    private:
        int _ix;
        int _iy;
    };
    
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
    Line::Point pt1(1, 2), pt2(3, 4);
    pt1.print();
    cout << endl;
    
    Line line(11, 12, 13, 14);
    line.printLine();
    cout << endl;
}

int main()
{
    test0();
    return 0;
}