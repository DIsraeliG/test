#include <string.h>
#include <iostream>

using std::cout;
using std::endl;

class Student
{
public:
    Student(const char * name, int id)
    : _name(new char[strlen(name) + 1]())
    , _id(id)
    {
        cout << "Student(const char*, int)" << endl;
        strcpy(_name, name);
    }
    ~Student()
    {
        if(_name){
            delete [] _name;
        }
        cout << "~Student()" << endl;
    }
    
    void print() const
    {
        cout << "_name: " << _name << endl;
        cout << "_id: " << _id << endl;
    }
    // 在类student中重载operator new/delete库函数
    void * operator new(size_t sz)
    { // 作用：申请未类型化的堆空间
        cout << "void * operator new(size_t)" << endl;
        return malloc(sz);
    }
    
    void operator delete(void * pret)
    { // 作用：回收对象所在的空间
        cout << "void operator delete(void *)" << endl;
        free(pret);
    }
private:
    char * _name; // 8
    int _id; // 4
};

void test0()
{
    cout << "sizeof(Student): " << sizeof(Student) << endl;
    Student * pstu = new Student("Rose", 100);
    pstu->print();
    
    // delete pstu;
    
    // 要调用构造函数
    // 要调用析构函数
    Student s1("Jack", 101);
}

int main()
{
    test0();
    return 0;
}