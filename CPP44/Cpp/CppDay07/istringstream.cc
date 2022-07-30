#include <fstream>
#include <sstream>
#include <iostream>
using std::cerr;
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::istringstream;
using std::ostringstream;

void readConfig(const string & confile)
{
    ifstream ifs(confile);
    if(!ifs.good()){
        cerr << "ifstream open file " << confile << " error\n";
        return;
    }

    string line;
    string key, value;
    while(std::getline(ifs, line)){
        // 将istringstream看成是一个容器
        istringstream iss(line); // 把一行看成一个单位
        // 在知道这一行的格式的情况下，就可以用以下方式解析
        // 输入流运算符默认情况下用空格/制表符/换行作为分隔符
        iss >> key >> value;
        cout << key << "-->" << value << endl;
    }

    ifs.close();
}

void test0()
{
    string filename("server.conf");
    readConfig(filename);
}

string mysprintf(int num)
{
    string str1("hello");
    ostringstream oss;
    oss << num << "-" << str1;
    return oss.str();
}

void test1()
{
    int num = 12345678;
    cout << mysprintf(num) << endl;
}

int main()
{
    // test0();
    test1();
    return 0;
}