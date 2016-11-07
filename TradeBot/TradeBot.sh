#!/bin/bash

# This script launches the TradeBot application on Mac/Unix operating systems
# This script must be placed in the same directory as the exe

# Change to the directory where the script is stored no matter how the script is run
SCRIPT_DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
cd "${SCRIPT_DIR}"

mono ./TradeBot.exe