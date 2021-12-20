#!/bin/bash


files="mat.cpp matrix.cpp"
exe=mat.out

if [ -e $exe ]; then
  rm $exe
fi

for fl in $files; do
  g++ -c $fl
done

#obj=$(find -name '*.o')
obj=`ls *.o`
g++ $obj -o $exe
./$exe
a=`ls`
echo $a
rm $obj
b=`ls`
echo $b
