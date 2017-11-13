#!/bin/bash

## made the build command dump whats in tests to src and the delete the files
## it is a workaround cause i suck at make
## -valgrind wont do this until it is edited

if [ "$1" = "-build" ]; then
	cd ./src
	clear
	clear
	cd ../build
	make remove
	make
	cd ../src
elif [ "$1" = "-run" ]; then
	clear
	clear
	cd bin
	./test
	cd ../
elif [ "$1" = "-clean" ]; then
	clear
	clear
	cd build
	make remove
	cd ../
elif [ "$1" = "-valgrind" ]; then
	cd build
	make remove
	make
	clear
	clear
	cd ../bin
	valgrind --leak-check=full ./test
elif [ "$1" = "-debuggui" ]; then
	cd bin
	ddd ./test
	cd ../
elif [ "$1" = "-debug" ]; then
	cd bin
	gdb -q ./test
	cd ../
elif [ $# -eq 0 ]; then
    cd build
	make remove
	make
	clear
	clear
	cd ../bin
	./test
else
	cd bin
	./test
fi
