#include <iostream>

using std::endl;
using std::cout;

// 自动释放
class Singleton
{// AutoRelease类型只为Singleton服务
// 因此设计成private，不需要在外部创建
    class AutoRelease
    {
    public:
        AutoRelease()
        { cout << "AutoRelease()" << endl; }

        // 析构函数的实现相当于是在Singleton的类内部
        // 因此可以直接拿到静态变量_pInstance，这是嵌套类的优势
        ~AutoRelease()
        {
            // cout << _ix << endl; // error: 这是非静态的Singleton数据成员，AutoRelease无法直接拿到
                                    // 非静态的数据成员无法直接访问，需要this指针才能访问
            cout << "~AutoRelease()" << endl;
            if(Singleton::_pInstance){
                delete _pInstance;
            }
        }
    private:
        Singleton * _p;
    };
public:
    Singleton(const Singleton &) = delete;
    Singleton & operator=(const Singleton &) = delete;

    static Singleton * getInstance()
    {
        if(nullptr == _pInstance){
            _pInstance = new Singleton();
        }
        return _pInstance;
    }

    void init(int ix, int iy)
    {
        _ix = ix;
        _iy = iy;
    }

    void print() const
    {
        cout << "(" << _ix
             << "," << _iy
             << ")" << endl;
    }

private:
    Singleton() { cout << "Singleton()" << endl; }
    ~Singleton() { cout << "~Singleton()" << endl; }

private:
    int _ix;
    int _iy;
    // 如果不加static，那么_ar就和_ix,_iy一样变成了对象的一部分，而非指向对象的指针（_pInstance）
    static AutoRelease _ar;
    static Singleton * _pInstance;
};

Singleton * Singleton::_pInstance = nullptr;
Singleton::AutoRelease Singleton::_ar;

void test0()
{
    // Singleton::AutoRelease ar(Singleton::getInstance());
    Singleton * p1 = Singleton::getInstance();
    p1->init(1, 2);
    p1->print();
    cout << "p1: " << p1 << endl;

    Singleton * p2 = Singleton::getInstance();
    cout << "p2: " << p2 << endl;
    p2->print();
} 

int main()
{
    test0();
    return 0;
}