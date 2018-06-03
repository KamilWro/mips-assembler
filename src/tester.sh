#!/bin/bash

IN="./tests/in"
OUT="./tests/out"

make

for fileName in ` ls $IN |sed "s/.in//g" `; do
	./mipsasm < $IN/${fileName}.in > tmp.iout
	result=$(diff -b -B $OUT/${fileName}.iout tmp.iout)
	if [ "$result" == "" ]; then
	    printf 'Test: %-10s %10s \n' "$fileName" "OK"
	else
	    printf 'Test: %-10s %10s \n' "$fileName" "FAIL"
	fi
done

rm ./tmp.out
