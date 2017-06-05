#! /bin/sh
path=$PATH
while true
do
    if [ -z $path ]
    then 
        break
    fi
    ls -ld ${path%%:*}
    path=${path#*:}
done