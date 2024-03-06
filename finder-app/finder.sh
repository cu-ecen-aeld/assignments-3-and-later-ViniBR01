#!/bin/bash

# Precess the two input arguments filesdir and searchstr (strings). They must be both specified.
if [ $# -ne 2 ]
then
    echo "usage: $0 <filesdir> <searchstr>"
    exit 1
fi

# Check that filesdir represent a directory on the filesystem
if [ ! -d $1 ]
then
    echo "$1 (filesdir) is not a directory"
    exit 1
fi

# Count how many files are in filesdir and subdirectories
numfiles=$( find $1/ -type f | wc -l )

# Count the number of occurances of searchstr in list of files above
numoccurences=$( grep -ros $2 $1/ | wc -l )

# Print output message
echo "The number of files are $numfiles and the number of matching lines are $numoccurences"
