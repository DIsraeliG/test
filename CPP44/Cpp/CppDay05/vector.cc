#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

void displayVector(const vector<int> & vec)
{
    cout << "size: " << vec.size() << endl;
    cout << "capacity: " << vec.capacity() << endl;
    for(auto & elem : vec){
        cout << elem << " ";
    }
    cout << endl << endl;
}

void test0()
{
    // std::vector会自动进行扩容操作，不需要担心内存不够
    // 扩容的步骤：
    // 1. 当 size == capacity时，如果还需要添加新的元素，此时要进行扩容，直接申请2 * capacity的新空间
    // 2. 将原来空间中的元素拷贝到新空间中
    // 3. 释放原来的空间
    // 4. 在新空间中添加新的元素
    vector<int> nums;
    nums.reserve(10); // 让nums预留10个元素的空间，只开辟空间，不创建元素
    
    for(int idx = 0; idx < 11; ++idx){
        nums.emplace_back(idx);
        displayVector(nums);
        cout << "sizeof(nums): "<< sizeof(nums) << endl;
    }
    // sizeof: 24 正好是三个指针的大小
}

void test1()
{
    vector<int> nums(10, 1); // 开辟空间的同时，添加了元素
    displayVector(nums); // size: 10, capacity: 10
}

class Point
{
public:
    Point(int ix = 0, int iy = 0)
    :_ix(ix)
    ,_iy(iy)
    {
        cout << "Point(int=0, int=0)" << endl;
    }
    
    ~Point(){ cout << "~Point()" << endl; }

    Point(const Point & rhs)
    : _ix(rhs._ix)
    , _iy(rhs._iy)
    {
        cout << "Point(const Point &)" << endl;
    }

    void print() const
    {
        cout << "(" << _ix 
             << "," << _iy
             << ")"; 
    }
private:
    int _ix;
    int _iy;
};

void displayVector(const vector<Point> & vec)
{
    cout << "size: " << vec.size() << endl;
    cout << "capacity: " << vec.capacity() << endl;
    for(auto it = vec.begin(); it != vec.end(); ++it){
        it->print();
        cout << " ";
    }
    cout << endl << endl;
}

void test2()
{
    vector<Point> points(10);
    displayVector(points);
}

void test3()
{
    // 放入vector中的元素会进行复制
    // size就是10，capacity也是10
    // size并不是0
    vector<Point> points(10, Point(1, 2));
    cout << endl;
    // points.emplace_back(Point(11, 12));
    // emplace_back可以传递可变参数
    // 根据存放在容器中元素的类型的构造函数形式进行对象的创建
    //
    // 用emplace_back替换push_back的作用
    // points.emplace_back(11, 12);
    // points.emplace_back(11);
    points.emplace_back();
    displayVector(points);
}

void test4()
{
    vector<Point> points = 
    {
        Point(1, 1),
        Point(2, 2),
        Point(3, 3),
        Point(4, 4),
        Point(5, 5),
    };
    
    // vector<Point> points
    // {
    //     (1, 1); // 一个括号代表一个对象
    //     (2, 2);
    //     (3, 3);
    //     (4, 4);
    //     (5, 5);
    // };
    displayVector(points);
}

int main()
{
    // test0();
    // test1();
    // test2();
    // test3();
    test4();
    
    return 0;
}