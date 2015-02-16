bin_PROGRAMS = miniftp

miniftp_SOURCES = log.cc \
		net/acceptor.cc \
		net/ftpserver.cc \
		net/inetaddress.cc \
		net/worker.cc \
		net/workerprocess.cc \
		net/buffer.cc \
		net/tcpconnection.cc \
		net/socket.cc	\
		net/socketsops.cc \
		ftpcmd.cc \
		main.cc \
		readconfig.cc \
		lib/event.cc \
		lib/eventloop.cc \
		lib/process.cc \
		lib/epoll.cc

include_HEADERS = utils.h \
		net/callbacks.h \
		net/socketsops.h \
		net/socket.h	\
		net/ftpserver.h \
		net/worker.h \
		net/tcpconnection.h \
		net/acceptor.h \
		net/buffer.h \
		net/workerprocess.h \
		net/inetaddress.h \
		log.h \
		simpleserver.h \
		readconfig.h \
		ftpcmd.h \
		lib/event.h \
		lib/process.h \
		lib/mutex.h \
		lib/epoll.h \
		lib/eventloop.h \
		userinfo.h

INCLUDES = -I${top_srcdir} 

LDFLAGS = -lcrypt -lpthread

AUTOMAKE_OPTIONS = foreign
