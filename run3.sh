#!/bin/bash
for ((i = 1; i <= 1024*4; i*=2));
do
    ./run $1 -w $i $2
    ./run $1 -r $i $2
    echo "block_count: $i"
    echo ""
done