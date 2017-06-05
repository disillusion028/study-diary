#! /bin/sh
author=false
list=false
file=""

while [ $# -gt 0 ]
do
    case $1 in
    -f) file=$2
        shift
        ;;
    -l) list=true
        ;;
    -a) author=true
        ;;
    --) shift
        break
        ;;
    -*) echo $0: $1: unrecognized option
        ;;
    *)  break
        ;;
    esac
    shift
done