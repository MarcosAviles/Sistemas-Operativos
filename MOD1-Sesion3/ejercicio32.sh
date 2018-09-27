#!/bin/bash

if [ $# != 1 ]; then
	echo "Error. Introduzca el número de iteracciones"
	exit 1
fi

variable=0

for (( CONTADOR=0; CONTADOR<$1; CONTADOR++ )) ; 
	do
		variable=$[ $variable*2/2 ]
		variable=$[ $variable + 1 ]
		sleep 1
	done

printf "El valor de la variable es:%d\n" $variable
