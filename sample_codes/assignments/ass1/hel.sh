#!/bin/bash
echo "Enter file extension:"
read inp

for file in *.txt
do
	mv "$file" "${file/.txt/.${inp}}" 
done
