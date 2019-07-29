#!/bin/bash

test_serialize() {
for val in $@
do
	echo "./serialize"
	./serialize;
	echo -e "\n";
done
};

test_serialize
test_serialize
test_serialize
test_serialize
test_serialize
