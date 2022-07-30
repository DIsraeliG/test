#include <stdlib.h>
#include <pthread.h>

#include <iostream>

using std::endl;
using std::cout;

// 自动释放
class Singleton
{
public:
    Singleton(const Singleton &) = delete;
    Singleton & operator=(const Singleton &) = delete;

    // 在多线程环境下，并不是线程安全的
    static Singleton * getInstance()
    {
        pthread_once(& _once, init); 
        return _pInstance;
    }

    static void init()
    {
        atexit(destroy);
        _pInstance = new Singleton();
    }

    static void destroy()
    {
        if(_pInstance){
            delete _pInstance;
            _pInstance == nullptr;
        }
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
    static Singleton * _pInstance;
    static pthread_once_t _once;
};

// 在进入main函数之前进行初始化
Singleton * Singleton::_pInstance = nullptr; // 懒（饱）汉模式（懒加载，延迟加载）
// Singleton * Singleton::_pInstance = getInstance(); // 饿汉模式是线程安全的
pthread_once_t Singleton::_once = PTHREAD_ONCE_INIT;

void test0()
{
    Singleton * p1 = Singleton::getInstance();
    p1->init(1, 2);
    p1->print();
    cout << "p1: " << p1 << endl;

    Singleton * p2 = Singleton::getInstance();
    cout << "p2: " << p2 << endl;
    p2->print();

    // Singleton::destroy();
}

int main()
{
    test0();
    return 0;
}