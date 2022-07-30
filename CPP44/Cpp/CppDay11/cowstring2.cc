#include <string.h>
#include <iostream>

using std::cout;
using std::endl;
using std::ostream;

class CowString
{
public:
    class CharProxy
    {
    public:
        // 1. 对于外部类的非静态成员，要访问，首先就要传参
        // 2. 对于外部类的静态成员，在内部类的成员函数中可以直接拿到，不需要传参
        CharProxy(CowString & self, size_t idx);
        char & operator=(const char & ch);

        operator char()
        { 
            cout << "operator char()" << endl;
            return _self._pstr[_idx]; 
        }

    private:
        CowString & _self; // 如果不传引用就会进行复制
                           // 要操作的就是字符串本身，因此要保存一个引用而不是对象
        size_t _idx;
    };
    
public:
    // 无参构造函数
    CowString() // 开辟的空间前4个字节记录refcount，从第五个字节起才是字符串的内容
    : _pstr(new char[kRefcountCapacity + 1]() + kRefcountCapacity) 
    {
        // 初始化引用计数
        init_use_count();
    }

    // 有参构造函数
    CowString(const char * pstr)
    : _pstr(new char[strlen(pstr) + kRefcountCapacity + 1]() + kRefcountCapacity)
    {
        strcpy(_pstr, pstr);
        init_use_count();
    }

    // 拷贝构造函数
    CowString(const CowString & rhs)
    : _pstr(rhs._pstr) // 此时只用执行浅拷贝，不用重新开辟空间
    {
        // 多了一个指向字符串的指针，refcount加1
        increase();
    }

    ~CowString() { release(); }

    void release()
    {
        // 1. 先将引用计数减1
        decrease();
        // 2. 如果引用计数为0，则释放堆对象
        if(use_count() == 0){
            // -kRefcountCapacity是为了释放refcount所在空间
            delete [] (_pstr - kRefcountCapacity); 
            cout << "free heap space" << endl;
        }
    }
    
    // 拷贝构造和赋值函数时间复杂度均为O(1)
    CowString & operator=(const CowString & rhs)
    {
        if(this != &rhs){ // 1. 自复制(&rhs是取地址)
            release(); // 2. 回收左操作数空间（回收str4一开始指向的字符串）
            _pstr = rhs._pstr; // 3. 浅拷贝（将str4指向str1指向的字符串）
            increase(); // 4. 引用计数加1（给str4此时指向的字符串的引用计数加1）
        }
        return *this; // 5. 返回
    }

    CharProxy operator[](size_t idx)
    { return CharProxy(*this, idx); }

#if 0  
    // 下标访问运算符
    // bug: 该运算符无法判断做的是读操作还是写操作
    char & operator[](size_t idx)
    {
        // 如果发现其引用计数大于1的情况下，需要进行深拷贝   
        if(idx < length()){
            if(use_count() > 1){
                decrease();
                char * ptmp = new char[length() + kRefcountCapacity + 1]() + kRefcountCapacity; // 深拷贝
                strcpy(ptmp, _pstr);
                _pstr = ptmp;
                init_use_count();
            }
            return _pstr[idx];
        }else{
            static char nullchar = '\0';
            return nullchar;
        }
    }
#endif
    
    size_t length() const { return strlen(_pstr); }

    // 获取引用计数
    int use_count() const 
    {
        // 强制类型转换: 将char*转换成int*
        return *reinterpret_cast<int *>(_pstr - kRefcountCapacity); 
    }

private:
    void init_use_count()
    { *reinterpret_cast<int *>(_pstr - kRefcountCapacity) = 1; }

    void increase()
    { ++*reinterpret_cast<int *>(_pstr - kRefcountCapacity); }

    void decrease()
    { --*reinterpret_cast<int *>(_pstr - kRefcountCapacity); }

    char * calloc(const char * pstr) // 在类内部定义的，会优先使用
    {
        if(pstr) {
            return new char[strlen(pstr) + kRefcountCapacity + 1]() + kRefcountCapacity;
        } else {
            return new char[kRefcountCapacity + 1]() + kRefcountCapacity;
        }
    }
    
    friend std::ostream & operator<<(std::ostream & os, const CowString & rhs);
private:
    char * _pstr;
    static const int kRefcountCapacity = 4;
};

std::ostream & operator<<(std::ostream & os, const CowString & rhs)
{
    os << rhs._pstr;
    return os;
}

CowString::CharProxy::CharProxy(CowString & self, size_t idx)
: _self(self)
, _idx(idx)
{
    // 非静态成员只与对象在一起，因此必须要有对象
    
}

// 写操作的实现
char & CowString::CharProxy::operator=(const char & ch)
{
    if(_idx < _self.length()){
        if(_self.use_count() > 1){
            _self.decrease();
            char * ptmp = _self.calloc(_self._pstr); // 深拷贝
            strcpy(ptmp, _self._pstr);
            _self._pstr = ptmp;
            _self.init_use_count();
        }
        _self._pstr[_idx] = ch; // 执行写操作
        return _self._pstr[_idx];
    }else{
        static char nullchar = '\0';
        return nullchar;
    }
}

void test0()
{
    CowString str0;
    cout << "str0: " << str0 << endl;
    cout << "str0's use_count: " << str0.use_count() << endl;

    CowString str1("hello, world"); // 各自创建的字符串
    CowString str2("hello, world"); // 没有深拷贝
    cout << "str1: " << str1 << endl;
    cout << "str1's use_count: " << str1.use_count() << endl;

    cout << "str2: " << str2 << endl; 
    cout << "str2's use_count: " << str2.use_count() << endl;

    // 需要优化的部分
    CowString str3 = str1; // 浅拷贝
    cout << "\n执行拷贝构造函数之后: " << endl;
    cout << "str3: " << str3 << endl; 
    cout << "str3's use_count: " << str3.use_count() << endl;

    cout << "str1: " << str1 << endl;
    cout << "str1's use_count: " << str1.use_count() << endl;
    
    CowString str4("hello, wangdao");
    cout << "\nstr4: " << str4 << endl; 
    cout << "str4's use_count: " << str4.use_count() << endl;
    CowString str5 = str4;
    cout << "\nstr5: " << str5 << endl; 
    cout << "str5's use_count: " << str5.use_count() << endl;
    str4 = str1; // 浅拷贝
    // str4.operator=(str1);
    cout << "str1: " << str1 << endl;
    cout << "str1's use_count: " << str1.use_count() << endl;
    cout << "str3: " << str3 << endl; 
    cout << "str3's use_count: " << str3.use_count() << endl;
    cout << "\nstr5: " << str5 << endl; 
    cout << "str5's use_count: " << str5.use_count() << endl;

    cout << "\n执行写操作: " << endl;
    str4[0] = 'X'; // 写操作，此时需要进行深拷贝（写时复制）
    cout << "\nstr4: " << str4 << endl; 
    cout << "str4's use_count: " << str4.use_count() << endl;

    // cout << "str3: " << str3 << endl; 
    // cout << "str3's use_count: " << str3.use_count() << endl;

    cout << "\n执行读操作: " << endl;
    cout << str1[0] << endl; // 把CharProxy类型转换成char类型
    cout << "str1: " << str1 << endl;
    cout << "str1's use_count: " << str1.use_count() << endl;
    cout << "str3: " << str3 << endl; 
    cout << "str3's use_count: " << str3.use_count() << endl;
}

int main()
{
    test0();
    return 0;
}