#!/bin/bash

mkdir build
g++ listen_input.cpp -o build/listen_input
g++ read_process_memory.cpp -o build/read_process_memory
g++ read_target.cpp -o build/read_target
