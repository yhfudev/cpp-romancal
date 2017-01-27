
AM_LDFLAGS=
AM_CFLAGS=

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
    -I$(top_builddir)/include/ \
    $(NULL)

AM_LDFLAGS += \
    -L$(top_builddir)/src/ \
    $(NULL)

#AM_CFLAGS += `pkg-config --cflags libcheck`
#AM_LDFLAGS += `pkg-config --libs libcheck`
AM_CFLAGS += $(LIBCHECK_CFLAGS)
AM_LDFLAGS += $(LIBCHECK_LDFLAGS)

AM_CFLAGS += $(LIBCOMPAT_CFLAGS)
AM_LDFLAGS += $(LIBCOMPAT_LDFLAGS)

TESTS=testromancal

check_PROGRAMS=testromancal

testromancal_SOURCES= \
    ../src/romancal.c \
    testromancal.c \
    $(NULL)

#testromancal_LDADD = -lm

testromancal_CFLAGS = $(AM_CFLAGS)
testromancal_LDFLAGS = $(AM_LDFLAGS) $(LIBS)
testromancal_LDADD = $(LIBCHECK_LIBS) $(LIBCOMPAT_LIBS) $(LIBS)
