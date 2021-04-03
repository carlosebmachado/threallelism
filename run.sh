#!/bin/bash

# chmod +x run.sh

dir="bin"

[ ! -d "$dir" ] && mkdir -p "$dir"

#gcc main.c -o bin/main
#g++ src/main.cpp -o bin/main
g++ -o bin/main src/main.cpp -g -fopenmp

bin/main
