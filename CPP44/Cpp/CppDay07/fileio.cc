#include <limits>
#include <vector>
#include <fstream>
#include <iostream>

using std::cout;
using std::cin;
using std::cerr;
using std::endl;
using std::vector;
using std::string;
using std::fstream;
using std::ifstream;
using std::ofstream;

vector<string> lines;

void test0()
{
    ifstream ifs("fileio.cc");
    if(!ifs.good()){
        cerr << "ifs open file error";
        return;
    }

    string word;
    // 输入流运算符会以空格或换行符或制表符（\t）作为分隔符
    while(ifs >> word){
        cout << word << endl;
        break;
    }

    ifs.close(); // 关闭文件流
}

void test1()
{
    ifstream ifs; // 确保流对象创建成功了
    ifs.open("fileio.cc"); // 二段式构造
    if(!ifs.good()){
        cerr << "ifs open file error";
        return;
    }

    char buff[100] = {0};
    // 没有读进\n换行符
    // ifstream自带的getline函数没有办法扩容
    while(ifs.getline(buff, 100)){
        cout << buff << '\n';
    }
    cout << endl;

    ifs.close(); // 关闭文件流
}

void test2()
{
    ifstream ifs; // 确保流对象创建成功了
    ifs.open("fileio.cc"); // 二段式构造
    if(!ifs.good()){
        cerr << "ifs open file error";
        return;
    }

    string line;
    // std::getline位于<string>头文件中
    // 这是以后推荐使用的获取一行的方式
    cout << "lines'size: " << lines.size() << endl;
    cout << "lines'capacity: " << lines.capacity() << endl;
    lines.reserve(100); // 开辟空间
    cout << "lines'size: " << lines.size() << endl;
    cout << "lines'capacity: " << lines.capacity() << endl;
    while(getline(ifs, line)){
        // cout << line << endl;
        lines.emplace_back(line);
    }
    for(auto & line : lines){
        cout << line << endl;
    }
    cout << "lines'size: " << lines.size() << endl;
    cout << "lines'capacity: " << lines.capacity() << endl;

    // 回收vector中多余的空间
    lines.shrink_to_fit();
    cout << "lines'size: " << lines.size() << endl;
    cout << "lines'capacity: " << lines.capacity() << endl;

    ifs.close(); // 关闭文件流
}

void test3()
{
    string filename = "test.txt";
    ofstream ofs;
    // 1. 当打开的文件不存在时，会直接创建一个新文件
    // 2. 当打开的文件存在时，会直接清空文件流的内容
    ofs.open(filename);
    if(!ofs.good()){
        cerr << "ofstream ope" << endl;
        return;
    }
    
    for(auto & line: lines){
        ofs << line << "\n"; // 写入操作是通过输出流运算符完成
    }

    string word("hello");
    for(auto & ch : word){
        ofs.put(ch); // 通过put函数每次写一个字符
    }
    ofs.put('\n');
    // 写入一个字符串
    ofs.write(word.c_str(), word.length());
    ofs.put('\n');
    
    ofs.close(); // 关闭文件输出流
}  

// 需求：希望在文件的末尾写入新的数据（即不清空文件流）
void test4()
{
    // APP模式的特点：每次写入之前，都会将文件指针便宜到末尾，之后再写入
    // 不需要担心文件指针的位置
    ofstream ofs("test.txt", std::ios::out|std::ios::app);
    if(!ofs.good()){
        cerr << "ofs open file error\n";
        return;
    }

    size_t pos = ofs.tellp();
    cout << "pos: " << pos << endl;

    ofs.seekp(0); // 便宜到文件流的开始位置
    pos = ofs.tellp();
    cout << "pos: " << pos << endl;

    string line("this is a new line\n");
    // ofs.write(line.c_str(), line.size());
    ofs << line;

    ofs.close();
}

void readInteger(int & num){
    cout << "pls input an integer: ";
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

void test5()
{
    // fstream打开的文件必须要存在
    fstream fs("f1.txt");
    if(!fs.good()){
        cerr << "fstearm open error" << endl;
        return;
    }
    
    int num = -1;
    for(int idx = 0; idx < 5; ++idx){
        // cin >> num;
        // cout << num << endl;
        readInteger(num);
        fs << num << " ";
    }

    fs.seekg(0); // 将文件指针从末尾移动到开始位置

    for(int idx = 0; idx < 5; ++idx){
        fs >> num;
        cout << "num: " << num << endl;
    }

    fs.close();
}

int main()
{
    // test0();
    // test1();
    // test2();
    // test3();
    // test4();
    test5();
    return 0;
}