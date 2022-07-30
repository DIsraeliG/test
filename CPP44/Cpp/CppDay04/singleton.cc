#include <iostream>

using std::cout;
using std::endl;

class Singleton
{
public:
    Singleton(const Singleton &) = delete; // 声明该函数已经从本类中删除了
    Singleton & operator=(const Singleton &) = delete; 

    static Singleton * getInstance()
    {
        // 第一次调用该函数时，创建对象
        // 后续的调用都返回一个该对象的指针即可
        if(nullptr == _pInstance){
            _pInstance = new Singleton(); // 只能创建一个无参的
        }
        
        return _pInstance;
    }
     
    static void destroy()
    {
        if(_pInstance){
            delete _pInstance;
        }
    }
    
    void init(int ix, int iy)
    {
        _ix = ix;
        _iy = iy;
    }
    
    void print() const
    {
        cout << "void print()" << endl;
        cout << "(" << _ix 
             << "," << _iy
             << ")" << endl; 
    }

private:
    Singleton()
    : _ix(0)
    , _iy(0)
    {
        cout << "Singleton()" << endl;
    }
    ~Singleton(){ cout << "~Singleton()" << endl; }

private: 
    int _ix;
    int _iy;
    static Singleton * _pInstance;
};

Singleton * Singleton::_pInstance = nullptr;

// Singleton pt2(2, 3); // error

/*
void test0()
{
    Singleton pt1; // error
    // 在类之外要调用构造函数
    // Singleton pt(1, 2); // error
    // Singleton pt2(1, 2); // error
    
    // Singleton * pt = new Singleton(3, 4); // error
}
*/

void test1()
{
    // 1. 先创建对象
    Singleton * pt = Singleton::getInstance(); // 回到可以创建无数个对象
    // 2. 初始化数据成员
    pt->init(1, 2); // 有两步操作完成对象的初始化，因此称为二段式构造
    pt->print();
    cout << "&pt: " << &pt << endl;
    
    Singleton * pt2 = Singleton::getInstance();
    cout << "&pt2: " << &pt << endl;
    pt2->print();
    
    Singleton::destroy();
}

int main()
{
    test1();
    return 0;
} 