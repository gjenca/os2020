#!/bin/bash

echo pocet argumentov je "$#"

echo 1.."$1"
echo 2.."$2"

echo Vsetky argumenty $*

for ARG in "$@"
do
	echo argument "$ARG"
done

# Iny sposob spracovania vsetkych argumentov

while [ "$#" != 0 ]
do
	echo argument "$1"
	shift
done
