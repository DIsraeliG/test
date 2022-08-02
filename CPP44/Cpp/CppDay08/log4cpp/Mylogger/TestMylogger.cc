#include "Mylogger.hpp"
#include <iostream>

using std::cout;
using std::endl;
using std::string;

void test0()
{
    wd::Mylogger::getInstance()->error("This is an error message");
    wd::Mylogger::getInstance()->warn("This is a warn message");
    wd::Mylogger::getInstance()->info("This is an info message");
    wd::Mylogger::getInstance()->debug("This is a debug message");
}

void test1()
{
    // 有了定位信息之后，只需要将其与字符串做拼接操作
    cout << __FILE__ << endl;
    cout << __FUNCTION__ << endl;
    cout << __LINE__ << endl;
}

void test2()
{
    wd::Mylogger::getInstance()->error(addprefix("This is an error message"));
    wd::Mylogger::getInstance()->warn(addprefix("This is a warn message"));
    wd::Mylogger::getInstance()->info(addprefix("This is an info message"));
    wd::Mylogger::getInstance()->debug(addprefix("This is a debug message"));
}

void test3()
{
    logInfo("The log is info message");
	logError("The log is error message");
	logWarn("The log is warn message");
	logDebug("The log is debug message");
}

int main()
{
    // test0();
    // test1();
    // test2();
    test3();

    wd::Mylogger::destroy(); // 手动释放
    return 0;
}