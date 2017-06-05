#!/bin/sh
if [ $# -ne 2 ];
then
	echo "Usage:$0 string file";
	exit 1;
fi
grep $1 $2;
if [ $? -ne 0 ];
then echo "Not Found \"$1\" in $2";
exit 1;
fi
echo "found \"$1\" in $2";
