#!/bin/sh
# timetable - print the multiplication table
for i in 1 2 3
do
 for j in 1 2 3
 do
 value=`expr $i \* $j`
 echo -n "$value "
 done
 echo
done
