#include <iostream>

#include <log4cpp/Category.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/RollingFileAppender.hh>

using namespace std;

class Mylogger
{
    Mylogger(const Mylogger &) = delete;
    Mylogger & operator=(const Mylogger &) = delete;
public:
    static Mylogger * getInstance()
    {
        if(_pMylogger == nullptr){
            _pMylogger = new Mylogger();
        }
        return _pMylogger;
    }

    static void destroy()
    {
        if(_pMylogger){
            delete _pMylogger;
        }
    }

	void warn(const char *msg);
	void error(const char *msg);
	void debug(const char *msg);
	void info(const char *msg);
	
private:
	Mylogger() { cout << "Mylogger()" << endl; }
	~Mylogger() { cout << "~Mylogger()" << endl; }
    
private:
    static Mylogger * _pMylogger;
    static log4cpp::Category & fileCategory;
    static log4cpp::Category & coutCategory;
};

Mylogger *log = Mylogger::getInstance();
log4cpp::Category & fileCategory = log4cpp::Category::getInstance("fileCategory");

log->info("The log is info message");
log->error("The log is error message");
log->fatal("The log is fatal message");
log->crit("The log is crit message");


int main(void)
{
	cout << "hello,world" << endl;
	
	logInfo("The log is info message");	//或者   
	logError("The log is error message");
	logWarn("The log is warn message");
	logDebug("The log is debug message");

}

//输出的日志信息中最好能有文件的名字，函数的名字及其所在的行号(这个在C/C++里面有对应的宏，可以查一下)

