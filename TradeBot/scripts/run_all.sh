#!/bin/sh

# This script runs all other scripts.

# Setup/Troubleshooting
# ==
# 1. Install the NuGet package manager and add it to your PATH
# 2. Run the following command to install the latest C# compiler:
#    nuget install Microsoft.Net.Compilers
# 3. Add the folder containing csc.exe to your PATH

./sort_resource_properties.sh
./generate_resource_classes.sh

# Prevent the terminal from auto-closing
#read -rsp $'Press any key to continue...\n' -n1
