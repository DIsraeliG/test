#include <fstream>
#include <iostream>
using std::cerr;
using std::cout;
using std::endl;
using std::string;
using std::ifstream;

void readFile(const string & filename)
{
    ifstream ifs(filename, std::ios::in|std::ios::ate);
    if(!ifs.good()){
        cerr << "ifstream open file error\n";
        return;
    }

    size_t length = ifs.tellg();
    cout << "length: " << length << endl;

    // 如果申请的空间大于函数栈空间，会直接栈溢出
    // char buff[100000000];

    // std::ios::beg/end/cur
    ifs.seekg(std::ios::beg);

    char * pbuff = new char[length + 1]();
    // ifs.read(pbuff, length); // 其返回值为流对象
    size_t ret = ifs.readsome(pbuff, length); 
    cout << "ret: " << ret << endl;

    // cout << pbuff;

    delete [] pbuff;
    pbuff = nullptr; // 防御性措施，SAFE DELETE操作

    cout << "000" << endl;
    if(pbuff){
        cout << pbuff; // 当cout一个值为nullptr的char*的指针时，程序会崩溃
        cout << "001" << endl;
    }

    ifs.close();
}

void test0()
{
    string filename("test.txt");
    readFile(filename);
}

int main()
{
    test0();
    return 0;
}