#!/bin/bash
for ((i = 1; i <= 1024*1024; i*=2));
do
    ./run $1 -r $2 $i
    echo "block_count: $i"
    echo ""
done
