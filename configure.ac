#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.60])
AC_INIT(romancal, 0.1, yhfudev@gmail.com)
AC_CONFIG_SRCDIR([src/main.c])
AC_CONFIG_HEADERS([config.h])
AM_INIT_AUTOMAKE(-Wall subdir-objects)

#magic for conditional check in Makefile:
MK=''; AC_SUBST(MK)
SED=sed

# Checks for programs.
AC_PROG_AWK
AC_PROG_CC
AC_PROG_CC_STDC
AC_PROG_CPP
AC_PROG_CXX
AC_PROG_INSTALL
AC_PROG_LN_S
AC_PROG_MAKE_SET
AC_PROG_RANLIB

# Checks for libraries.
LT_INIT([shared static])


app_link_all_option="-Wl,--whole-archive"
app_no_link_all_option="-Wl,--no-whole-archive"
app_platform_type="Unix"

AC_CACHE_CHECK([type of operating system we're going to host on],
               [app_os_type],
[case $host in
  *-*-aix*)
    app_os_type="AIX"
    ;;
  *-*-irix*)
    app_os_type="IRIX"
    ;;
  *-*-cygwin*)
    app_os_type="Cygwin"
    ;;
  *-*-darwin*)
    app_link_all_option="-Wl,-all_load"
    app_no_link_all_option="-Wl,-noall_load"
    app_os_type="Darwin"
    ;;
  *-*-minix*)
    app_link_all_option="-Wl,-all_load"
    app_no_link_all_option="-Wl,-noall_load"
    app_os_type="Minix"
    ;;
  *-*-freebsd*)
    app_os_type="FreeBSD"
    ;;
  *-*-kfreebsd-gnu)
    app_os_type="GNU/kFreeBSD"
    ;;
  *-*-openbsd*)
    app_os_type="OpenBSD"
    ;;
  *-*-netbsd*)
    app_os_type="NetBSD"
    ;;
  *-*-dragonfly*)
    app_os_type="DragonFly"
    ;;
  *-*-hpux*)
    app_os_type="HP-UX"
    ;;
  *-*-interix*)
    app_os_type="Interix"
    ;;
  *-*-linux*)
    app_os_type="Linux"
    ;;
  *-*-gnu*)
    app_os_type="GNU"
    ;;
  *-*-solaris*)
    app_link_all_option="-Wl,-z,allextract"
    app_no_link_all_option="-Wl,-z,defaultextract"
    app_os_type="SunOS"
    ;;
  *-*-auroraux*)
    app_link_all_option="-Wl,-z,allextract"
    app_link_all_option="-Wl,-z,defaultextract"
    app_os_type="AuroraUX"
    ;;
  *-*-win32*)
    app_os_type="Win32"
    app_platform_type="Win32"
    ;;
  *-*-mingw*)
    app_os_type="MingW"
    app_platform_type="Win32"
    ;;
  *-*-haiku*)
    app_os_type="Haiku"
    ;;
  *-unknown-eabi*)
    app_os_type="Freestanding"
    ;;
  *-unknown-elf*)
    app_os_type="Freestanding"
    ;;
  *)
    app_link_all_option=""
    app_no_link_all_option=""
    app_os_type="Unknown"
    app_platform_type="Unknown"
    ;;
esac])

AC_CACHE_CHECK([type of operating system we're going to target],
               [app_target_os_type],
[case $target in
  *-*-aix*)
    app_target_os_type="AIX" ;;
  *-*-irix*)
    app_target_os_type="IRIX" ;;
  *-*-cygwin*)
    app_target_os_type="Cygwin" ;;
  *-*-darwin*)
    app_target_os_type="Darwin" ;;
  *-*-minix*)
    app_target_os_type="Minix" ;;
  *-*-freebsd*)
    app_target_os_type="FreeBSD" ;;
  *-*-kfreebsd-gnu)
    app_target_os_type="GNU/kFreeBSD" ;;
  *-*-openbsd*)
    app_target_os_type="OpenBSD" ;;
  *-*-netbsd*)
    app_target_os_type="NetBSD" ;;
  *-*-dragonfly*)
    app_target_os_type="DragonFly" ;;
  *-*-hpux*)
    app_target_os_type="HP-UX" ;;
  *-*-interix*)
    app_target_os_type="Interix" ;;
  *-*-linux*)
    app_target_os_type="Linux" ;;
  *-*-gnu*)
    app_target_os_type="GNU" ;;
  *-*-solaris*)
    app_target_os_type="SunOS" ;;
  *-*-auroraux*)
    app_target_os_type="AuroraUX" ;;
  *-*-win32*)
    app_target_os_type="Win32" ;;
  *-*-mingw*)
    app_target_os_type="MingW" ;;
  *-*-haiku*)
    app_target_os_type="Haiku" ;;
  *-*-rtems*)
    app_target_os_type="RTEMS" ;;
  *-*-nacl*)
    app_target_os_type="NativeClient" ;;
  *-unknown-eabi*)
    app_target_os_type="Freestanding" ;;
  *)
    app_target_os_type="Unknown" ;;
esac])

if test "$app_os_type" = "MingW" ; then
  AC_CHECK_HEADERS([windows.h psapi.h])
  AC_CHECK_LIB(psapi, [GetProcessMemoryInfo], [LIBPSAPI=-lpsapi])
  AC_SUBST(LIBPSAPI)
  #AC_CHECK_LIB(shlwapi, PathIsDirectory, [LIBSHLWAPI=-lshlwapi])
  #AC_SUBST(LIBSHLWAPI)
fi

AC_CHECK_LIB([m], [main])

# FIXME: Replace `main' with a function in `-llibcompat':
#AC_CHECK_LIB([compat], [ck_do_nothing])
#AC_CHECK_LIB([check], [suite_create])
PKG_CHECK_MODULES([LIBCOMPAT], [compat], [have_libcompat=yes], [have_libcompat=no])
AM_CONDITIONAL([LIBCOMPAT],  [test "$have_libcompat" = "yes"])
PKG_CHECK_MODULES([LIBCHECK], [check], [have_libcheck=yes], [have_libcheck=no])
AM_CONDITIONAL([LIBCHECK],  [test "$have_libcheck" = "yes"])
if test "x$have_libcompat" = "xyes"; then
  LIBCOMPAT_LIBS+=" -lcompat"
fi
if test "x$have_libcheck" = "xyes"; then
  LIBCHECK_LIBS+=" -lcheck"
fi
AM_CONDITIONAL([USE_CI_CHECK], [test $have_libcheck = "yes"])

AC_ARG_WITH([libcheck],
    [AS_HELP_STRING([--with-libcheck=prefix],
        [try this for a non-standard install prefix of the Check library])],
    [LIBCHECKPATHSET=1],
    [LIBCHECKPATHSET=0])
AM_CONDITIONAL([USE_CI_CHECK], [test $LIBCHECKPATHSET = 1])
if test $LIBCHECKPATHSET = 1 ; then
  CFLAGS="$CFLAGS -I$with_libcheck/ -I$with_libcheck/src/ -I$with_libcheck/lib/"
  LDFLAGS="$LDFLAGS -L$with_libcheck/src/ -L$with_libcheck/lib/"
  LIBS="-lcheck -lcompat $LIBS"
fi
# distribute the changed variables among the Makefiles
AC_SUBST([LIBS])
AC_SUBST([CFLAGS])
AC_SUBST([LDFLAGS])

# debug
AC_ARG_ENABLE([debug],
	AS_HELP_STRING([--enable-debug],[Compile the debug version (default: disabled)]),
	[enable_debug=$enableval],
	[enable_debug=no])
AM_CONDITIONAL([DEBUG], [test $enable_debug = "yes"])
AM_COND_IF(DEBUG,
    AC_DEFINE(DEBUG, 1, [Define to 0 if this is a release build]),
    AC_DEFINE(DEBUG, 0, [Define to 1 or higher if this is a debug build]))
if test "x$enable_debug" = "xyes"; then
  changequote({,})
  CFLAGS=`echo "$CFLAGS" | $SED -e 's/-O[0-9s]*//g'`
  CXXFLAGS=`echo "$CXXFLAGS" | $SED -e 's/-O[0-9s]*//g'`
  changequote([,])
  dnl add -O0 only if GCC or ICC is used
  if test "$GCC" = "yes" || test "$ICC" = "yes"; then
    CFLAGS="$CFLAGS -O0"
    CXXFLAGS="$CXXFLAGS -O0"
  fi
else
  changequote({,})
  CFLAGS=`echo "$CFLAGS" | $SED -e 's/-g//g'`
  CXXFLAGS=`echo "$CXXFLAGS" | $SED -e 's/-g//g'`
  changequote([,])
fi

dnl Disable doc generation with doxygen option
AC_ARG_ENABLE(doxygen-doc,
              [AC_HELP_STRING([--disable-doxygen-doc],
                              [disable document generation with doxygen])],
              , enable_doxygen_doc="yes")
if test "x$enable_doxygen_doc" = "xyes"; then
  AC_CHECK_PROG(DOXYGEN,doxygen,doxygen,no)
  if test "x$DOXYGEN" = "xno"; then
    enable_doxygen_doc="no"
  fi
fi
dnl where to install the doxygen-generated HTML doc
AC_ARG_WITH(html-docdir,
            [AC_HELP_STRING([--with-html-docdir=DIR],
                            [where to install the doxyten-generated HTML doc [PREFIX/share/doc/libpf/html]])],
            [htmldocdir="$withval"], [htmldocdir=\$\{prefix\}/share/doc/libpf/html])
AC_SUBST(htmldocdir)
AM_CONDITIONAL(ENABLE_DOXYGEN_DOC,test "x$enable_doxygen_doc" = "xyes")

# Checks for header files.
AC_CHECK_HEADERS([stddef.h stdlib.h string.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_SIZE_T

# Checks for library functions.
AC_CHECK_FUNCS([memset])

AC_CONFIG_FILES([Makefile
                 doc/Makefile
                 doc/Doxyfile
                 src/Makefile
                 src/libromancal.pc
                 tests/Makefile])
AC_OUTPUT
