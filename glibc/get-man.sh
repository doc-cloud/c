#!/bin/sh

for i in $*
do
#	mkdir $i ;
#	cd $i ;
#	man 3 $i | unexpand -a --tabs=7 > $i.txt ;
	man 3 $i | col -b > $i.txt ;
	cd .. ;
done
