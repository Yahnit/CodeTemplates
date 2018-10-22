#!/bin/bash

echo "Enter directory"
read inp

find $inp -type f -name "*.c" | wc -l
echo " the directory $inp conatains files"

