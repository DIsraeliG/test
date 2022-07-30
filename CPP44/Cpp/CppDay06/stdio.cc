#include <unistd.h>
#include <limits>
#include <iostream>

using std::cout;
using std::endl;
using std::cin;
using std::istream;
using std::ostream;
using std::string;

void readStreamStatus(istream & is) // 获取(输入)流状态的函数
{
    cout << "is's goodbit: " << is.good() << endl;
    cout << "is's badbit: " << is.bad() << endl;
    cout << "is's eofbit: " << is.eof() << endl;
    cout << "is's failbit: " << is.fail() << endl;
}

// std::cin的测试
// 每一个流对象都会有缓冲区对应
void test0()
{
    int num = -1;
    readStreamStatus(cin);
    cin >> num; // 从流中获取数据
    cout << "num: " << num << endl;
    readStreamStatus(cin);

    if(cin.fail()){
        // 重置流的状态
        cin.clear();
        // cin.ignore(1024, '\n'); // 最多丢弃1024个字节的数据，\n是分隔符，直到碰到该字符就停下来
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "\n重置流的状态之后: " << endl;
        readStreamStatus(cin);
    }

    string line;
    // 如果需要等待输入，就需要清空缓冲区
    cin >> line;
    cout << "line: " << line << endl; // 流的状态变成failbit，则无法正常工作
}

// 对于输入的健壮实现
void readInteger(int & num){
    cout << "pls input an integer: ";
    // 逗号表达式
    while(cin >> num, !cin.eof()){
        if(cin.bad()){
            cout << "cin has corrupted\n";
            return;
        }else if(cin.fail()){
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "pls input a vaild integer: ";
            continue;
        }else{
            cout << "num: " << num << endl;
            break;
        }
    }
}

void test1()
{
    int num = -1;
    readInteger(num);
    readStreamStatus(cin);
}

void test2()
{
    cout << "hello, cout" << endl; // 1
    std::cerr << "hello, cerr" << endl; // 2
    std::clog << "hello, clog" << endl; // 2
}

void test3()
{
    // cout << "hello, world" << endl; // 行缓冲
    for(int idx = 0; idx < 1025; ++idx){ // 全缓冲
        cout << 'a';
    }
    sleep(3);
    cout << 'b'; // 刷新缓冲区
}

int main()
{
    // test0();
    test1();
    // test2();
    // test3();
    return 0;
}