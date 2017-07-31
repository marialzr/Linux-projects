#Write a shell script that receives a director name and a number n. Prints the name of n biggest files from the given directory and his 
#subdirectories sorted by dimension in decreasing order and the number of words for each file.
#!/bin/bash
i=0
find $1 -type f | while read f; do
	var1=`du -b $ | awk '{print $1}'`
	var2=`wc -l $f`
	echo $var1 $var2>> anotherfile
	i=$(($i+1))
	if [ $i -eq $2 ]; then
		break
	fi
done
cat anotherfile | sort -r