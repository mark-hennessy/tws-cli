#!/bin/bash

# This script launches the TradeBot application on Mac/Unix operating systems

# Change to the directory where the exe is stored no matter how the script is run
SCRIPT_DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
cd "${SCRIPT_DIR}"/..

mono ./TradeBot.exe