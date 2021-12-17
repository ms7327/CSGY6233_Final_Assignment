#!/bin/bash
# Script to compile all files in the project
# Usage: ./build.sh

echo
echo "======= Compiling ======="

echo
gcc run.c -o run
echo "DONE - run.c"

gcc run_lseek.c -o run_lseek
echo "DONE - run_lseek.c"

gcc fast.c -o fast
echo "DONE - fast.c"

echo
echo "========================="
echo