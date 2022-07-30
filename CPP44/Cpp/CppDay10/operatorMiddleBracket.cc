#include <string.h>

#include <vector>
#include <iostream>

using std::cout;
using std::endl;

class CharArray
{
public:
    typedef char * iterator; 
    iterator begin() { return _data; }
    iterator end() { return _data + size(); }
    CharArray(int capacity = 10)
    : _capacity(capacity)
    , _data(new char[capacity]())
    {
        cout << "CharArray(int)" << endl;
    }
    
    size_t size() const { return strlen(_data); }
    size_t capacity() const { return _capacity; }
    
    char & operator[](size_t idx)
    {
        // cout << "char & operator[](size_t)" << endl;
        if(idx < _capacity){
            return _data[idx];
        }else{
            std::cerr << "the idx of char array is out of range\n";
            static char ch = '\0';
            return ch;
        }
    }
    
    // const对象调用的时候才使用这个版本
    const char & operator[](size_t idx) const
    {
        // cout << "const char & operator[](size_t) const" << endl;
        return _data[idx];
    }
    
    ~CharArray()
    {
        if(_data){
            delete [] _data;
            _data = nullptr;
        }
    }
    
private:
    size_t _capacity;
    char * _data;
};

void display(const CharArray & ca)
{
    for(size_t idx = 0; idx < ca.capacity(); ++idx)
    {
        cout << ca[idx];
    }
}

void test0()
{
    char buff[] = "hello,world";
    CharArray carr(strlen(buff) + 1);
    for(size_t idx = 0; idx < carr.capacity(); ++idx){
        carr[idx] = buff[idx];
    }
    
    for(size_t idx = 0; idx < carr.capacity(); ++idx){
        cout << carr[idx] << " ";
    }
    
    cout << endl;
    
    display(carr);
    
    // 增强for循环其底层实现依赖于迭代器（指针）
    cout << "增强for循环" << endl;
    for(auto & ch : carr){
        cout << ch << " ";   
    }
}

void test1()
{
    // vector内部重载了下标访问运算符
    std::vector<int> nums{1, 1, 1, 1, 1};
    for(size_t idx = 0; idx < nums.size(); ++idx)
    {
        cout << "nums[idx]" << " "; 
    }
    cout << endl;
}

void test2()
{
    std::string str1("hello,world");
    for(size_t idx = 0; idx < str1.size(); ++idx)
    {
        cout << "str1[idx]" << " "; 
    }
    cout << endl;
}
    
int main()
{
    test0();
    // test1();
    // test2();
    return 0;
}