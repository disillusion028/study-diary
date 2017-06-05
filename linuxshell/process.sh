#!/bin/sh
#  解释位置变量参数的含义
echo "the number of parameter is $#"
echo "the return code of last command is $?"
echo "the script name is $0"
echo "the parameters are $*"
echo "\$1=$1;\$2=$2"
