#!/bin/bash

MXEPATH="/home/$whoami/mxe/usr/bin"
echo "Creating log file in compilationLogs/$LOGFILE"
mkdir compilationLogs
touch compilationLogs/$LOGFILE

if [ "$1" = "linux" ]
    then
    echo "Run compilation for linux"
    qmake > "compilationLogs/log.txt"
    make > "compilationLogs/log.txt"
    echo "End compilation, run removing obj files"
    rm *.o > "compilationLogs/log.txt"
    rm moc_predefs.h > "compilationLogs/log.txt"
    rm moc_mainwindow.cpp > "compilationLogs/log.txt"
    rm Makefile > "compilationLogs/log.txt"
    echo "End removing obj files"

    elif [ "$1" = "windows" ]
        then
        echo "Run static compilation for windows 32-bit"
        $MXEPATH/qmake-qt5 > "compilationLogs/log.txt"
        make > "compilationLogs/log.txt"
        echo "End compilation, run removing obj files"
        rm *.o > "compilationLogs/log.txt"
        rm moc_predefs.h > "compilationLogs/log.txt"
        rm moc_mainwindow.cpp > "compilationLogs/log.txt"
        echo "End removing obj files"
    else
        echo "No input options!!! Please, enter 'linux' or 'windows' as param "
fi
