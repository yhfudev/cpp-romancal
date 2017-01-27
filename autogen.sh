#!/bin/sh

./autoclean.sh

rm -f configure

rm -f Makefile.in

rm -f config.guess
rm -f config.sub
rm -f install-sh
rm -f missing
rm -f depcomp

if [ 0 = 1 ]; then
autoscan
else

touch NEWS
touch README
touch AUTHORS
touch ChangeLog
touch config.h.in
touch install-sh

libtoolize --force --copy --install --automake
aclocal
automake -a -c
autoconf
# run twice to get rid of 'ltmain.sh not found'
autoreconf -f -i -Wall,no-obsolete
autoreconf -f -i -Wall,no-obsolete

#./configure

(cd ../check-0.11.0/; make clean ; ./configure --enable-shared=no --enable-static=yes; make clean; make; cd -)

if [ 1 = 1 ]; then
    LIBCOMPAT_CFLAGS="-I$(pwd)/../check-0.11.0/lib/" \
    LIBCOMPAT_LIBS="-L$(pwd)/../check-0.11.0/lib/" \
    LIBCHECK_CFLAGS="-I$(pwd)/../check-0.11.0/ -I$(pwd)/../check-0.11.0/src/" \
    LIBCHECK_LIBS="-L$(pwd)/../check-0.11.0/src/" \
        ./configure --enable-static --enable-debug
else
    #./configure --enable-static --enable-shared --disable-debug --with-libcheck=$(pwd)/../check-0.11.0/
    ./configure --enable-static --enable-debug --with-libcheck=$(pwd)/../check-0.11.0/
fi

#make clean
make ChangeLog

make
make check
#make -C doc/latex/
make dist-gzip

fi
