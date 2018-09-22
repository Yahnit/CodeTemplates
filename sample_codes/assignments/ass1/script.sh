echo "Enter Directory name:"
read inp

find $inp -type f -name "*.c" | wc -l
