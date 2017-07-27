#!/bin/bash
#Write a shell script that will monitor all the folders given in the command 
#and notify the user if a certain file will be created inside them (the name of the file will be read from keyboard).
if [ ! -d $1 ]; then
	echo "$1 is not a directory"
	exit 0
fi
contor=`ls $1 | wc -l`
while true; do
	cfolder=`ls $1 | wc -l`
	if [ $contor -ne $cfolder ]; then
		echo "The content of this directory was modified!"
		exit 1
	fi
	sleep 1
done