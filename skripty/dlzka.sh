#!/bin/bash
for F in *
do
	stat -c '%s' "$F"
done | paste -s -d+ | bc
