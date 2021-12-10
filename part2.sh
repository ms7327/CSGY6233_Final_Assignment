#!/bin/bash
max=20
i=1
./final_proj $1 -w $2 $i
./final_proj $1 -r $2 $i
for i in `seq 2 $max`
do
    ((i*=2))
    ./final_proj $1 -w $2 $i
    ./final_proj $1 -r $2 $i
    echo "block_count: $i"
    echo ""
done
