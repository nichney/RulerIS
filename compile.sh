#!/bin/bash

LOGFILE="compilationLogs/log.txt"
#Define compillers
qmakeWindows32="i686-w64-mingw32.static-qmake-qt5"

# Creating log files
test -e compilationLogs/log.txt
if [ $? -ne 0 ]
    then
    echo "Creating log file in $LOGFILE"
    mkdir compilationLogs 2> $LOGFILE
    touch compilationLogs/log.txt 2> $LOGFILE
fi

if [ "$1" = "linux" ]
    then
    echo "Run compilation for linux"
    qmake >> $LOGFILE 2> $LOGFILE
    if [ $? -ne 0 ]
        then
        echo "qmake error, please read log.txt" 
        exit
    fi
    make >> $LOGFILE 2> $LOGFILE
    if [ $? -ne 0 ]
        then
        echo "make error, please read log.txt" 
        exit
    fi
    echo "End compilation, run removing obj files"
    rm *.o >> $LOGFILE
    rm moc_predefs.h >> $LOGFILE
    rm moc_mainwindow.cpp >> $LOGFILE
    rm Makefile >> $LOGFILE
    rm .qmake.stash >> $LOGFILE
    echo "End removing obj files"
    echo "Compilation succsessfully finished. Check './RulerIS'"

    elif [ "$1" = "win32" ]
        then
        echo "Run static compilation for windows 32-bit"
        qmakeWindows32 >> $LOGFILE 2> $LOGFILE
        if [ $? -ne 0 ]
            then
            echo "qmake error, please read log.txt" 
            exit
        fi
        make >> $LOGFILE 2> $LOGFILE
        if [ $? -ne 0 ]
            then
            echo "make error, please read log.txt" 
            exit
        fi
        echo "Moving some files to release.."
        cp -r img release
        cp -r data release
        cp icon.ico release
        cp License.txt release
        cd release
        rm *.o *.h *.cpp
        cd ../
        echo "End moving."
        echo "Compilation succsessfully finished. Check 'release' folder"

    elif [ "$1" = "-h" ]
        then
        echo "1) './compile.sh linux' to shared compile for linux;"
        echo "2) './compile.sh win32' to static compile for Windows 32 bit (with MXE, you must add path to MXE to PATH.)"
    else
        echo "No input options!!! Please, enter -h for help"
fi
