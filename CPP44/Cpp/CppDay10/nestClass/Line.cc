#include "Line.hpp"
#include <iostream>

using std::cout;
using std::endl;

class Line::LineImpl
{
private:
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
    LineImpl(int x1, int y1, int x2, int y2)
    : _p1(x1, y1)
    , _p2(x2, y2)
    {cout << "LineImpl(int, int, int, int)" << endl; }

    void printLine() const
    {
        _p1.print();
        cout << "--->";
        _p2.print();
    }

    ~LineImpl()
    { cout << "~LineImpl()" << endl; }

private:
    Point _p1;
    Point _p2;
};

Line::Line(int x1, int y1, int x2, int y2)
: _pimpl(new LineImpl(x1, y1, x2, y2))
{
    cout << "Line(int, int, int, int)" << endl;
}

Line::~Line()
{
    cout << "~Line()" << endl;
    if(_pimpl){
        delete _pimpl;
        _pimpl = nullptr; // SAFE DELETE
    }
}

void Line::printLine() const
{
    _pimpl->printLine();
}