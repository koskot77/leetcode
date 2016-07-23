#!/bin/bash
# I've learned something from
# https://discuss.leetcode.com/topic/27687/solution-using-associative-array-transpose-file
# so the script below is just a copy of the solution 
# My original solution 'Exceeds memory' according to the OJ:
# n=1 && m=`head -1 file.txt | tr ' ' '\n' | wc | awk '{print $1}'` && while [ $n -le $m ] ; do cat file.txt | cut -d' ' -f$n | tr '\n' ' ' | sed -e 's| $||g' ; n=`expr $n + 1`; echo ; done

declare -A matrix

row=1

while read line ; do
    col=1
    for word in $line; do
        matrix[$col,$row]=$word
        ((col++))
    done
    ((row++))
done < file.txt

for ((i=1; i<col; i++)) ; do
    echo -n ${matrix[$i,1]}
    for ((j=2; j<row; j++)); do
        echo -n ' '${matrix[$i,$j]}
    done
    echo
done

