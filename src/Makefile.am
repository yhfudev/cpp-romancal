
AM_LDFLAGS=
AM_CFLAGS=
EXTRA_DIST=

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

DEFS+= \
    `getconf LFS_CFLAGS` \
    `getconf LFS64_CFLAGS` \
    -D_GNU_SOURCE \
    -D_FILE_OFFSET_BITS=64 \
    -DHAVE_MMAP64=1 \
    $(NULL)

libromancal_la_LDFLAGS=
libromancal_la_CPPFLAGS=

include_HEADERS = \
    $(top_srcdir)/src/romancal.h \
    $(NULL)

EXTRA_DIST += libromancal.pc.in

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = libromancal.pc

#BUILT_SOURCES = $(top_builddir)/src/xmllex.c
#CLEANFILES = $(top_builddir)/src/xmllex.c
#nodist_program_SOURCES = $(top_builddir)/src/xmllex.c
#$(top_builddir)/src/xmllex.c: $(top_srcdir)/src/xmllex.l $(top_srcdir)/src/xmldecl.h
#	$(LEX) -o $@ $(top_srcdir)/src/xmllex.l


lib_LTLIBRARIES=libromancal.la
libromancal_la_SOURCES= \
    romancal.c \
    $(NULL)

bin_PROGRAMS=romancal

romancal_SOURCES= \
    main.c \
    $(NULL)

romancal_LDADD = -lm -lromancal

romancal_CFLAGS = $(AM_CFLAGS)
romancal_LDFLAGS = $(AM_LDFLAGS)


EXT_FLAGS=
#@MK@GITNUMTMP=$(shell cd "$(top_srcdir)"; echo $$(git describe --tags|sed -r 's|v?(.+)|\1|'|sed 's|-|+|g'); cd - > /dev/null )
@MK@GITNUMTMP=$(shell cd "$(top_srcdir)"; A=$$(git show | head -n 1 | awk '{print $$2}'); echo $${A:0:7}; cd - > /dev/null )
#@MK@SVNNUMTMP=$(shell cd "$(top_srcdir)"; LC_ALL=C svn info | grep -i Revision | awk '{print $$2}'; cd - > /dev/null )
#@MK@ifeq ($(SVNNUMTMP),)
#EXT_FLAGS+= -DSVN_VERSION='"${GITNUMTMP}"'
#@MK@else
#EXT_FLAGS+= -DSVN_VERSION='"${SVNNUMTMP}"'
#@MK@endif
@MK@ifeq ($(GITNUMTMP),)
@MK@else
EXT_FLAGS+= -DSVN_VERSION='"${GITNUMTMP}"'
@MK@endif
DEFS+=$(EXT_FLAGS)


