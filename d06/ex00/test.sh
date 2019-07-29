#!/bin/bash

test_conversion() {
for val in $@
do
	echo "./convert $val"
	./convert $val ;
	echo -e "\n";
done
};

test_conversion 2147483647 4294967294.0 9223372036854775806.0 z % ! 0 nan 42.0f -42 42 0.0f -4.2f 4.2f 0.0 -4.2 4.2 -inff +inff nanf -inf +inf nan 185384 -41654351 agzedsn ééééé P -111111111111111111111111111111111111 422222222222222222222222222222222222222222222222


