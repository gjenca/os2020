#!/bin/bash
STEP=1
OPER=+

while true
do
	if [ "$1" == "-s" ]
	then
		STEP="$2"
		shift 2
	elif [ "$1" == "-p" ]
	then
		OPER='*'
		shift
	else
		break
	fi
done


if [ "$#" != 2 ]
then
	echo 'Musia byt dva argumenty'
	exit 1
fi

FROM="$1"
TO="$2"

seq "$FROM" "$STEP" "$TO" | paste -s -d "$OPER" | bc
