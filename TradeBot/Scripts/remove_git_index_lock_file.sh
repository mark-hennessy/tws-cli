#!/bin/sh

# This script deletes the .git/index.lock file if it exists.

# Delete the executable
rm -f ../../.git/index.lock

# Prevent the terminal from auto-closing
#read -rsp $'Press any key to continue...\n' -n1
