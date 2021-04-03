#!/bin/bash

# chmod +x run.sh

dir="bin"

[ ! -d "$dir" ] && mkdir -p "$dir"

# gcc main.c -o bin/main
g++ main.cpp -o bin/main

bin/main
