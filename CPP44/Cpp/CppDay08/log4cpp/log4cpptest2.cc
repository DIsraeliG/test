#include <iostream>

#include <log4cpp/Category.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/RollingFileAppender.hh>

using std::cout;
using std::endl;
using namespace log4cpp;

void test0()
{
    // 1. 设置布局
    auto ptnLayout = new PatternLayout();
    ptnLayout->setConversionPattern("%d [%c] [%p] %m%n");

    auto ptnLayout2 = new PatternLayout();
    ptnLayout2->setConversionPattern("%d [%c] [%p] %m%n");

    auto ptnLayout3 = new PatternLayout();
    ptnLayout3->setConversionPattern("%d [%c] [%p] %m%n");

    // 2. 设置日志的目的地
    auto posAppender = new OstreamAppender("console", &cout);
    posAppender->setLayout(ptnLayout);

    auto pFileAppender = new FileAppender("fileApp", "wd.log");
    pFileAppender->setLayout(ptnLayout2);

    auto pRollingFileAppender = new RollingFileAppender(
        "rollingfileApp", 
        "rollingwd.log",
        1000, 3
        );
    pFileAppender->setLayout(ptnLayout3);

    // 3. 创建日志来源对象
    Category & testModule = Category::getRoot().getInstance("TestModule");
    testModule.setPriority(Priority::DEBUG);
    testModule.setAppender(posAppender);
    testModule.setAppender(pFileAppender);
    testModule.setAppender(pRollingFileAppender);

    // 4. 记录日志
    int cnt = 100;
    while(cnt-- > 0){
        testModule.crit("this is a crit message");
        testModule.emerg("this is a emerg message");
        testModule.alert("this is a alert message");
        testModule.error("this is a error message");
        testModule.warn("this is a warn message");
        testModule.info("this is a info message");
        testModule.notice("this is a notice message");
        testModule.debug("this is a debug message");
    }

    Category::shutdown(); // 回收资源
}

int main()
{
    test0();
    return 0;
}