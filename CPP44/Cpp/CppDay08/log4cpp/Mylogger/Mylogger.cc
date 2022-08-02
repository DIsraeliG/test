#include "Mylogger.hpp" 

#include <iostream>

#include <log4cpp/Priority.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/FileAppender.hh>

using std::cout;
using std::endl;

namespace wd
{

Mylogger * Mylogger::_pInstance = nullptr;

Mylogger * Mylogger::getInstance()
{
    if(nullptr == _pInstance){
        _pInstance = new Mylogger();
    }
    return _pInstance;
}

void Mylogger::destroy()
{
    if(_pInstance){
        delete _pInstance;
        _pInstance = nullptr;
    }
}

Mylogger::Mylogger()
: _myCat(Category::getRoot().getInstance("myCat"))
{
    // 设置日志布局
    auto ptnLayout1 = new PatternLayout();
    auto ptnLayout2 = new PatternLayout();
    ptnLayout1->setConversionPattern("%d %c [%p] %m%n");
    ptnLayout2->setConversionPattern("%d %c [%p] %m%n");
    
    auto pOstreamApp = new OstreamAppender("console", &cout);
    auto pFileApp = new FileAppender("fileApp", "wd.log");
    pOstreamApp->setLayout(ptnLayout1);
    pFileApp->setLayout(ptnLayout2);

    _myCat.addAppender(pOstreamApp);
    _myCat.addAppender(pFileApp);
    _myCat.setPriority(Priority::DEBUG);

    cout << "Mylogger()" << endl;
}

Mylogger::~Mylogger()
{
    cout << "~Mylogger()" << endl;
    Category::shutdown();
}

void Mylogger::warn(const char *msg)
{ _myCat.warn(msg); }

void Mylogger::error(const char *msg)
{ _myCat.error(msg); }

void Mylogger::debug(const char *msg)
{ _myCat.debug(msg); }

void Mylogger::info(const char *msg)
{ _myCat.info(msg); }

}