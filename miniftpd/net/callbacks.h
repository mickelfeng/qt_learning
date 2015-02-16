#ifndef _CALLBACKS_H_
#define _CALLBACKS_H_

#include <boost/function.hpp>
#include <boost/shared_ptr.hpp>

namespace miniftp 
{

class TcpConnection;
class Buffer;

typedef boost::shared_ptr<TcpConnection>    TcpConnectionPtr;

typedef boost::function<void (const TcpConnectionPtr&)> ConnectionCallback;
typedef boost::function<void (const TcpConnectionPtr&, Buffer *buf)> MessageCallback;
typedef boost::function<void (const TcpConnectionPtr&)> CloseCallback;
typedef boost::function<void (const TcpConnectionPtr&)> WriteCompleteCallback;

};

#endif
