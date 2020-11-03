#!/bin/bash
for N in $(seq 0 9)
do

    N_SQUARE=$(echo "$N*$N" | bc)
    echo "$N*$N=$N_SQUARE"
done
