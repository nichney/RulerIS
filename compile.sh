#!/bin/bash

LOGFILE="compilationLogs/log.txt"
#Define compillers
qmakeWindows32="i686-w64-mingw32.static-qmake-qt5"
qmakeWindows64="x86_64-w64-mingw32.static-qmake-qt5"


if [ "$1" = "linux" ]
    then
    qmake 
    make 

    rm *.o 
    rm moc_predefs.h 
    rm moc_mainwindow.cpp 
    rm Makefile 
    rm .qmake.stash
 

    elif [ "$1" = "win32" ]
        then
        qmakeWindows32 
        make 
        cp -r img release
        cp -r data release
	cp -r font release
        cp icon.ico release
        cp LICENSE.txt release
	cp README.txt release
        cd release
        rm *.o *.h *.cpp
        cd ../

    elif [ "$1" = "win64" ]
	then
	qmakeWindows64
	make
	cp -r img release
	cp -r data release
	cp -r font release
	cp icon.ico release
	cp LICENSE.txt release
	cp README.txt release
	cd release 
	rm *.o *.h *.cpp
	cd ../

    else
        then
        echo "1) './compile.sh linux' to run compilation for Linux"
        echo "2) './compile.sh win32' to run compilation for 32 bit Windows"
	echo "3) ./compile.sh win64 to run compilation for 64 bit Windows"
fi
