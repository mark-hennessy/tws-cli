#!/bin/bash

# This script deletes the .git/index.lock file if it exists

# Change to the directory where the script is stored no matter how the script is run
SCRIPT_DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
cd "${SCRIPT_DIR}"

# Delete the executable
rm -f ../../.git/index.lock

# Prevent the terminal from auto-closing on Windows
#read -rsp $'Press any key to continue...\n' -n1
