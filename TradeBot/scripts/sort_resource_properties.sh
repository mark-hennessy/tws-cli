#!/bin/sh

# This script sorts resource properties in ascending order.

# Setup/Troubleshooting
# ==
# 1. Install the NuGet package manager and add it to your PATH
# 2. Run the following command to install the latest C# compiler:
#    nuget install Microsoft.Net.Compilers
# 3. Add the folder containing csc.exe to your PATH

RES_DIR="../res/"
GEN_DIR="../Core/Resources/"

# Only compile the files needed to output the executable
csc /main:TradeBot.Core.FileIO.ResourcePropertySorter /out:sorter.exe /recurse:../Core/FileIO/*.cs

# Use the executable to sort properties in resource files by key in ascending order.
# Note that this will remove comments, empty lines, white-space formatting etc.
./sorter.exe "${RES_DIR}default.prefs"
./sorter.exe "${RES_DIR}user.prefs"
./sorter.exe "${RES_DIR}app.state"
./sorter.exe "${RES_DIR}messages"

# Delete the executable
rm -f sorter.exe

# Prevent the terminal from auto-closing
#read -rsp $'Press any key to continue...\n' -n1
