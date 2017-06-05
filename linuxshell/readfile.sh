#! /bin/sh
case $1 in
    *.jpg) echo $1: is picture;;
    *.txt) echo $1: is text;;
    *.avi | *.wmv) echo $1: is video;;
    *.pdf) echo $1: is book;;
    *) echo $1: Don\'t know how to read this file;;
esac