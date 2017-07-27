#!/bin/bash
#Write a shell script that will monitor the content of a folder (given in the command line) and notify if files or folders are created or deleted from it.
read -p "Enter the filename:" file
while true; do
	for x in $@; do
		if [ ! -d $x ]; then
			echo "$x is not a directory"
			exit 0
		fi
		cd $x
		if [ -e $file ]; then
			echo "The file $file was created"
			exit 1
		fi
		cd ..
		sleep 1
	done
done