#!/bin/bash

# This script deletes the .git/index.lock file if it exists.

# This will change to the directory where the script is stored no matter how the script is run.
DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
cd "${DIR}"

# Delete the executable
rm -f ../../.git/index.lock

# Prevent the terminal from auto-closing
#read -rsp $'Press any key to continue...\n' -n1
