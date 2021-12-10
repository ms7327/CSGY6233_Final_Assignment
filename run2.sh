#!/bin/bash
max=10
i=1
#for i in `seq 2 $max`
for ((i = 1; i < 40; i*=2));
do
    ./final_proj $1 -w $2 $i
    ./final_proj $1 -r $2 $i
    echo "block_count: $i"
    echo ""
done
