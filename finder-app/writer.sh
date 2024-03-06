#!/bin/bash

# Precess the two input arguments writefile and writestr (strings). They must be both specified.
if [ $# -ne 2 ]
then
    echo "usage: $0 <writefile> <writestr>"
    exit 1
fi

# Create a new file (or replace existing one) with name and path writefile and content wirtestr
mkdir -p $(dirname "$1")
if [ $? -ne 0 ]
then
    echo "Error creating directory"
    exit 1
fi

echo "$2" > $1
if [ $? -ne 0 ]
then
    echo "Error creating file"
    exit 1
fi
