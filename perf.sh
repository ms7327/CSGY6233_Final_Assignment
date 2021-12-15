#!/bin/bash
for ((i = 1; i <= 32768; i*=2));
do
    ./run $1 -r $i $2
    echo "block_count: $i"
    echo ""
done

# 1048576
