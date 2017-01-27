
AM_LDFLAGS=
AM_CFLAGS=

if DEBUG
# use "valgrind --tool=memcheck --leak-check=yes" to check memory leak, MemWatch will drag the program.
#DEFS+=-DMEMWATCH=1
DEFS+=-DDEBUG=1
AM_CFLAGS+=-g  -Werror# -Wall

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

EXTRA_DIST=romancal.h

bin_PROGRAMS=romancal

romancal_SOURCES= \
    romancal.c \
    main.c \
    $(NULL)

#romancal_LDADD = -lm

romancal_CFLAGS = $(AM_CFLAGS)
romancal_LDFLAGS = $(AM_LDFLAGS)
