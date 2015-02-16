#ifndef _PROCESS_H_
#define _PROCESS_H_

#include <boost/function.hpp>
#include <boost/noncopyable.hpp>

namespace miniftp
{

class Process : boost::noncopyable
{
public:
    typedef boost::function<void()> ProcessFunc;
    explicit Process(const ProcessFunc&);

    ~Process();

    void start();
private:
    bool            m_started;
    
    ProcessFunc     m_func;
};

}

#endif
