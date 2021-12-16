#!/bin/bash
for ((i = 1; i <= 1024*1024*8; i*=2));
do
    ./run $1 -w $2 $i
    ./run $1 -r $2 $i
    echo "block_count: $i"
    echo ""
done