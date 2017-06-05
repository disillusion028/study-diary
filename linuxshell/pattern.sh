#! /bin/bash
#test pattern match
testpath=prince/desktop/long.file.name
echo "original"
echo $testpath

echo "test 1 #"
echo ${testpath#*\/}

echo "test 2 ##"
echo ${testpath##*\/}

echo "test 3 %"
echo ${testpath%.*}

echo "test 4 %%"
echo ${testpath%%.*}

echo "replace things matched"
echo -e  ${testpath/\./"\n"}
echo -e  ${testpath//\./"\n"}
