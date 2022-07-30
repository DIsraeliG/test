#include <fstream>
#include <iostream>

using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::ifstream;

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

int main()
{
    test0();
    return 0;
}