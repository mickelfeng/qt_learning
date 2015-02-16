#include <net/buffer.h>
#include <net/socketsops.h>

#include <errno.h>
#include <memory.h>
#include <sys/uio.h>

#include <boost/implicit_cast.hpp>

using namespace miniftp;

ssize_t Buffer::readFd(int fd, int *savedErrno)
{
    char extrabuf[65536];
    struct iovec vec[2];
    const size_t writable = writableBytes();
    vec[0].iov_base = begin() + m_writerIndex;
    vec[0].iov_len = writable;
    vec[1].iov_base = extrabuf;
    vec[1].iov_len = sizeof extrabuf;

    const ssize_t n = readv(fd, vec, 2);
    if(n < 0) {
        *savedErrno = errno;
    } else if ( boost::implicit_cast<size_t>(n) <= writable) { 
        m_writerIndex += n;
    } else {
        m_writerIndex = m_buffer.size();
        append(extrabuf, n - writable);
    }

    return n;
}
