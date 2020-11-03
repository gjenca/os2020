#!/bin/bash

SUM=0
while read LINE
do
	let SUM=SUM+LINE
done
echo "$SUM"

