#!/bin/bash

if [ "$#" -lt 3 ]
then
	echo 'aspon 3 argumenty: koncovka1 koncovka2 meno_suboru'
	exit 1
fi

FROM_SUFF="$1"
TO_SUFF="$2"
shift 2

while [ "$#" != "0" ]
do
	NOVE_MENO=$(echo "$1" | sed "s/$FROM_SUFF\$/$TO_SUFF/")
	echo mv "$1" "$NOVE_MENO"
	shift
done
