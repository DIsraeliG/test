#ifndef __WD_MYLOGGER_HPP__
#define __WD_MYLOGGER_HPP__

#include <log4cpp/Category.hh>

using namespace log4cpp;
using namespace std;

namespace wd
{

class Mylogger
{
public:
    static Mylogger * getInstance();
    static void destroy();

    void warn(const char *msg);
	void error(const char *msg);
	void debug(const char *msg);
	void info(const char *msg);

private:
    Mylogger();
	~Mylogger();

private:
    Category & _myCat;
    static Mylogger * _pInstance;
};

// [file:test1:25]
// 字符串的替换
#define addprefix(msg) string ("[")\
       .append(__FILE__).append(":")\
       .append(__FUNCTION__).append(":")\
       .append(std::to_string(__LINE__)).append("]")\
       .append(msg).c_str()

#define logError(msg) wd::Mylogger::getInstance()->error(addprefix(msg))
#define logWarn(msg) wd::Mylogger::getInstance()->warn(addprefix(msg))
#define logInfo(msg) wd::Mylogger::getInstance()->info(addprefix(msg))
#define logDebug(msg) wd::Mylogger::getInstance()->debug(addprefix(msg))

} // end of namespace wd

#endif