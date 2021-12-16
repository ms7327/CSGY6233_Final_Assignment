#!/bin/bash
# Script to run the 5th part, using 1 byte
# Usage: ./run5.sh <filename>
for ((i = 1; i <= 1024*1024; i*=2));
do
    ./run $1 -r 1 $i
    echo "file_size: $i"
    echo ""
done