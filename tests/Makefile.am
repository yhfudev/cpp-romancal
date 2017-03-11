
AM_LDFLAGS=
AM_CFLAGS=
AM_CPPFLAGS=

if DEBUG
# use "valgrind --tool=memcheck --leak-check=yes" to check memory leak, MemWatch will drag the program.
#DEFS+=-DMEMWATCH=1
DEFS+=-DDEBUG=1
AM_CFLAGS+=-g -Werror# -Wall

else
AM_CFLAGS+=-O3 -Werror# -Wall
endif

AM_CFLAGS+= \
    -I$(top_srcdir)/src \
    -I$(top_srcdir)/include/ \
    -I$(top_builddir)/include/ \
    $(NULL)

AM_CPPFLAGS+= $(AM_CFLAGS)

AM_LDFLAGS += \
    -L$(top_builddir)/src/ \
    $(NULL)


if USE_CI_CHECK
#AM_CFLAGS += `pkg-config --cflags libcheck`
#AM_LDFLAGS += `pkg-config --libs libcheck`
AM_CFLAGS += $(LIBCHECK_CFLAGS)
AM_LDFLAGS += $(LIBCHECK_LDFLAGS)

AM_CFLAGS += $(LIBCOMPAT_CFLAGS)
AM_LDFLAGS += $(LIBCOMPAT_LDFLAGS)

DEFS+= -DUSE_CI_CHECK=1

else
# use cache.hpp as Unit Test lib
DEFS+= -DUSE_CI_CHECK=0

endif


TESTS=testromancal

check_PROGRAMS=testromancal

testromancal_SOURCES= \
    ../src/romancal.c \
    $(NULL)

if USE_CI_CHECK
testromancal_SOURCES+= \
    testmain4check.c \
    testromancal.c \
    $(NULL)
else
testromancal_SOURCES+= testmain4catch.cpp
endif

#testromancal_LDADD = -lm

testromancal_CFLAGS = $(AM_CFLAGS)
testromancal_LDFLAGS = $(AM_LDFLAGS) $(LIBS)
testromancal_LDADD = $(LIBCHECK_LIBS) $(LIBCOMPAT_LIBS) $(LIBS)
