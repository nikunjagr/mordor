ACLOCAL_AMFLAGS=-I m4
AUTOMAKE_OPTIONS=nostdinc subdir-objects
AM_CPPFLAGS=$(OPENSSL_INCLUDES) $(BOOST_CPPFLAGS) -I$(top_srcdir)
AM_CXXFLAGS=-Wall -Werror -fno-strict-aliasing

nobase_include_HEADERS=			\
	mordor/anymap.h			\
	mordor/assert.h			\
	mordor/atomic.h			\
	mordor/config.h			\
	mordor/coroutine.h		\
	mordor/daemon.h			\
	mordor/date_time.h		\
	mordor/endian.h			\
	mordor/eventloop.h		\
	mordor/exception.h		\
	mordor/fiber.h			\
	mordor/fibersynchronization.h	\
	mordor/future.h			\
	mordor/http/auth.h		\
	mordor/http/basic.h		\
	mordor/http/broker.h		\
	mordor/http/chunked.h		\
	mordor/http/client.h		\
	mordor/http/connection.h	\
	mordor/http/digest.h		\
	mordor/http/http.h		\
	mordor/http/multipart.h		\
	mordor/http/negotiate.h		\
	mordor/http/oauth.h		\
	mordor/http/parser.h		\
	mordor/http/proxy.h		\
	mordor/http/server.h		\
	mordor/iomanager_epoll.h	\
	mordor/iomanager.h		\
	mordor/iomanager_kqueue.h	\
	mordor/json.h			\
	mordor/log.h			\
	mordor/main.h			\
	mordor/parallel.h		\
	mordor/pq.h			\
	mordor/predef.h			\
	mordor/ragel.h			\
	mordor/scheduler.h		\
	mordor/semaphore.h		\
	mordor/sleep.h			\
	mordor/socket.h			\
	mordor/socks.h			\
	mordor/statistics.h		\
	mordor/streams/buffered.h	\
	mordor/streams/buffer.h		\
	mordor/streams/cat.h		\
	mordor/streams/deflate.h	\
	mordor/streams/duplex.h		\
	mordor/streams/fd.h		\
	mordor/streams/file.h		\
	mordor/streams/filter.h		\
	mordor/streams/gzip.h		\
	mordor/streams/hash.h		\
	mordor/streams/http.h		\
	mordor/streams/limited.h	\
	mordor/streams/memory.h		\
	mordor/streams/notify.h		\
	mordor/streams/null.h		\
	mordor/streams/pipe.h		\
	mordor/streams/progress.h	\
	mordor/streams/random.h		\
	mordor/streams/scheduler.h	\
	mordor/streams/singleplex.h	\
	mordor/streams/socket.h		\
	mordor/streams/ssl.h		\
	mordor/streams/std.h		\
	mordor/streams/stream.h		\
	mordor/streams/temp.h		\
	mordor/streams/test.h		\
	mordor/streams/throttle.h	\
	mordor/streams/timeout.h	\
	mordor/streams/transfer.h	\
	mordor/streams/zlib.h		\
	mordor/string.h			\
	mordor/test/antxmllistener.h	\
	mordor/test/stdoutlistener.h	\
	mordor/test/test.h		\
	mordor/thread.h			\
	mordor/thread_local_storage.h	\
	mordor/timer.h			\
	mordor/uri.h			\
	mordor/util.h			\
	mordor/version.h		\
	mordor/workerpool.h		\
	mordor/xml/parser.h		\
	mordor/zip.h

lib_LTLIBRARIES=mordor/libmordor.la mordor/test/libmordortest.la
mordor_libmordor_la_SOURCES=			\
	mordor/assert.cpp			\
	mordor/config.cpp			\
	mordor/daemon.cpp			\
	mordor/date_time.cpp			\
	mordor/exception.cpp			\
	mordor/fiber.cpp			\
	mordor/fibersynchronization.cpp		\
	mordor/http/auth.cpp			\
	mordor/http/basic.cpp			\
	mordor/http/broker.cpp			\
	mordor/http/chunked.cpp			\
	mordor/http/client.cpp			\
	mordor/http/connection.cpp		\
	mordor/http/digest.cpp			\
	mordor/http/http.cpp			\
	mordor/http/http_parser.cpp		\
	mordor/http/multipart.cpp		\
	mordor/http/oauth.cpp			\
	mordor/http/proxy.cpp			\
	mordor/http/server.cpp			\
	mordor/iomanager_epoll.cpp		\
	mordor/iomanager_kqueue.cpp		\
	mordor/json.cpp				\
	mordor/log.cpp				\
	mordor/parallel.cpp			\
	mordor/ragel.cpp			\
	mordor/scheduler.cpp			\
	mordor/semaphore.cpp			\
	mordor/sleep.cpp			\
	mordor/socket.cpp			\
	mordor/socks.cpp			\
	mordor/statistics.cpp			\
	mordor/streams/buffer.cpp		\
	mordor/streams/buffered.cpp		\
	mordor/streams/cat.cpp			\
	mordor/streams/fd.cpp			\
	mordor/streams/file.cpp			\
	mordor/streams/filter.cpp		\
	mordor/streams/hash.cpp			\
	mordor/streams/http.cpp			\
	mordor/streams/limited.cpp		\
	mordor/streams/memory.cpp		\
	mordor/streams/null.cpp			\
	mordor/streams/pipe.cpp			\
	mordor/streams/random.cpp		\
	mordor/streams/singleplex.cpp		\
	mordor/streams/socket.cpp		\
	mordor/streams/ssl.cpp			\
	mordor/streams/std.cpp			\
	mordor/streams/stream.cpp		\
	mordor/streams/temp.cpp			\
	mordor/streams/timeout.cpp		\
	mordor/streams/test.cpp			\
	mordor/streams/throttle.cpp		\
	mordor/streams/transfer.cpp		\
	mordor/streams/zlib.cpp			\
	mordor/string.cpp			\
	mordor/thread.cpp			\
	mordor/timer.cpp			\
	mordor/uri.cpp				\
	mordor/workerpool.cpp			\
	mordor/xml/xml_parser.cpp		\
	mordor/zip.cpp
mordor_libmordor_la_CPPFLAGS=-I$(top_srcdir) -include mordor/pch.h
mordor_libmordor_la_LDFLAGS=			\
	$(OPENSSL_LDFLAGS)			\
	$(BOOST_LDFLAGS)			\
	$(CORESERVICES_FRAMEWORK_LIBS)		\
	$(COREFOUNDATION_FRAMEWORK_LIBS)	\
	$(SECURITY_FRAMEWORK_LIBS)		\
	$(SYSTEMCONFIGURATION_FRAMEWORK_LIBS)	\
	-version-info $(LIBMORDOR_SO_VERSION)
mordor_libmordor_la_LIBADD=$(OPENSSL_LIBS) $(BOOST_REGEX_LIB) $(BOOST_THREAD_LIB)

pkgconfigdir=$(libdir)/pkgconfig
pkgconfig_DATA=mordor/libmordor.pc

SUFFIXES=.rl

.rl.cpp:
	$(RAGEL) $(RAGELFLAGS) -C $< -o $@

# Objects specifically depend on the PCH
$(mordor_libmordor_la_OBJECTS): mordor/pch.h.gch

MOSTLYCLEANFILES=mordor/pch.h.gch
CLEANFILES=				\
	mordor/http/http_parser.cpp	\
	mordor/json.cpp			\
	mordor/uri.cpp			\
	mordor/xml/xml_parser.cpp
EXTRA_DIST=				\
	mordor/pch.h			\
	mordor/http/http_parser.rl	\
	mordor/json.rl			\
	mordor/uri.rl			\
	mordor/xml/xml_parser.rl	\
	mordor/examples/netbench.h

mordor/pch.h.gch: mordor/pch.h
	$(CXXCOMPILE) $(pic_flag) -x c++-header $< -o $@

mordor_test_libmordortest_la_SOURCES=	\
	mordor/test/antxmllistener.cpp	\
	mordor/test/stdoutlistener.cpp	\
	mordor/test/test.cpp

check_PROGRAMS=mordor/tests/run_tests
mordor_tests_run_tests_SOURCES=			\
	mordor/tests/run_tests.cpp		\
	mordor/tests/buffer.cpp			\
	mordor/tests/buffered_stream.cpp	\
	mordor/tests/chunked_stream.cpp		\
	mordor/tests/coroutine.cpp		\
	mordor/tests/endian.cpp			\
	mordor/tests/fibers.cpp			\
	mordor/tests/fibersync.cpp		\
	mordor/tests/file_stream.cpp		\
	mordor/tests/fls.cpp			\
	mordor/tests/future.cpp			\
	mordor/tests/hmac.cpp			\
	mordor/tests/http_client.cpp		\
	mordor/tests/http_parser.cpp		\
	mordor/tests/http_server.cpp		\
	mordor/tests/iomanager.cpp		\
	mordor/tests/json.cpp			\
	mordor/tests/log.cpp			\
	mordor/tests/memory_stream.cpp		\
	mordor/tests/oauth.cpp			\
	mordor/tests/pipe_stream.cpp		\
	mordor/tests/scheduler.cpp		\
	mordor/tests/socket.cpp			\
	mordor/tests/ssl_stream.cpp		\
	mordor/tests/stream.cpp			\
	mordor/tests/string.cpp			\
	mordor/tests/temp_stream.cpp		\
	mordor/tests/thread.cpp			\
	mordor/tests/timeout_stream.cpp		\
	mordor/tests/timer.cpp			\
	mordor/tests/transfer_stream.cpp	\
	mordor/tests/uri.cpp			\
	mordor/tests/xml.cpp			\
	mordor/tests/zlib.cpp
mordor_tests_run_tests_LDADD=mordor/libmordor.la mordor/test/libmordortest.la

check:
	mordor/tests/run_tests

noinst_PROGRAMS=			\
	mordor/examples/cat		\
	mordor/examples/echoserver	\
	mordor/examples/iombench	\
	mordor/examples/simpleappserver	\
	mordor/examples/tunnel		\
	mordor/examples/udpstats	\
	mordor/examples/wget

mordor_examples_cat_SOURCES=mordor/examples/cat.cpp
mordor_examples_cat_LDADD=mordor/libmordor.la

mordor_examples_echoserver_SOURCES=mordor/examples/echoserver.cpp
mordor_examples_echoserver_LDADD=mordor/libmordor.la

mordor_examples_iombench_SOURCES=	\
	mordor/examples/iombench.cpp	\
	mordor/examples/netbench.cpp
mordor_examples_iombench_LDADD=mordor/libmordor.la

mordor_examples_simpleappserver_SOURCES=mordor/examples/simpleappserver.cpp
mordor_examples_simpleappserver_LDADD=mordor/libmordor.la

mordor_examples_tunnel_SOURCES=mordor/examples/tunnel.cpp
mordor_examples_tunnel_LDADD=mordor/libmordor.la

mordor_examples_udpstats_SOURCES=mordor/examples/udpstats.cpp
mordor_examples_udpstats_LDADD=mordor/libmordor.la

mordor_examples_wget_SOURCES=mordor/examples/wget.cpp
mordor_examples_wget_LDADD=mordor/libmordor.la $(BOOST_PROGRAM_OPTIONS_LIB)