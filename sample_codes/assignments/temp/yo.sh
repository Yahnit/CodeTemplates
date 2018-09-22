#!/bin/bash

echo "Input?"
read inp

for file in *.cpp
do
	mv "$file" "${file/.cpp/.${inp}}"
done
