#include <iostream>

using std::cout;
using std::endl;

class Data
{
public:
    // Data()=default;
    Data() { cout << "Data()" << endl; }
    ~Data() { cout << "~Data()" << endl; }
    
    int getData() const { return _data; }
private:
    int _data = 10;
    
};

class MiddleLayer
{
public:
    MiddleLayer(Data *p)
    : _pointer(p)
    {
        cout << "MiddleLayer()" << endl;
    }
    
    // 一般情况下，这两个运算符是一起重载
    Data * operator->()
    {
        return _pointer;
    }
    
    Data & operator*()
    {
        return *_pointer;
    }
    
    ~MiddleLayer()
    {
        if(_pointer)
        {
            delete _pointer;
            _pointer = nullptr; // SAFE_DELETE
            cout << "~MiddleLayer()" << endl;
        }
    }
    
    Data * getPointer() { return _pointer; }
private:
    Data * _pointer; // 指向的是一个堆空间的数据
};

class ThirdLayer
{
public:
    ThirdLayer(MiddleLayer * ml)
    : _ml(ml)
    { cout << "ThirdLayer(MiddleLayer *)" << endl; }
    
    ~ThirdLayer()
    {
        if(_ml) {
            delete _ml;
            _ml = nullptr;
            cout << "~ThirdLayer()" << endl;
        }
    }
    
    // 箭头运算符的返回值可以为相应类型的指针
    // 或者是重载了箭头运算符的对象的引用
    MiddleLayer & operator->()
    {
        return *_ml;
    }
    
    MiddleLayer & operator*()
    {
        return *_ml;
    }
    
private:
    MiddleLayer * _ml;
};

void test0()
{
    Data data;
    cout << data.getData() << endl;
    
    // 当创建Data的堆对象交给了ml对象进行托管
    // 同时MiddleLayer提供了访问Data对象的方法
    // （重载了箭头运算符和解引用运算符）
    //
    // 之后当需要销毁Data堆对象时，不需要手动进行
    // 只要管理MiddleLayer对象的生命周期即可
    MiddleLayer ml(new Data()); // 局部对象，当函数执行结束时，是一定会被销毁，此时一定会执行其析构函数
    // 这种写法就是一个智能指针的雏形（智能指针本身是一个对象）
    
    ml.getPointer()->getData();
    ml->getData(); // ml对象内部本身没有getData()方法
                   // 有一个简写的过程
    // (ml.operator->())->getData(); //等价于该语句
    // cout << ml->getData() << endl;
    
    cout << (*ml).getData() << endl;
    // ml本身是一个对象，但用法更像一个指针
}

void test1()
{
    ThirdLayer tl(new MiddleLayer(new Data()));
    cout << tl->getData() << endl; // 简化其调用过程
    // 等价于
    ((tl.operator->()).operator->())->getData();
    cout << (*tl)->getData() << endl;
}

int main()
{
    // test0();
    test1();
    return 0;
}