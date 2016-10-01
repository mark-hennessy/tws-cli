#!/bin/sh

# This script generates C# constants for property keys.

# Setup/Troubleshooting
# ==
# 1. Install the NuGet package manager and add it to your PATH
# 2. Run the following command to install the latest C# compiler:
#    nuget install Microsoft.Net.Compilers
# 3. Add the folder containing csc.exe to your PATH

RES_DIR="../res/"
GEN_DIR="../Core/Resources/"

# Only compile the files needed to output the executable
csc /main:TradeBot.Core.FileIO.ResourceKeyClassGenerator /out:resource_key_class_generator.exe /recurse:../Core/FileIO/*.cs

# Use the executable to generate files
./resource_key_class_generator.exe StateKeys "${RES_DIR}state" > "${GEN_DIR}StateKeys.cs"
#./resource_key_class_generator.exe PrefKeys "${RES_DIR}default.prefs" > "${GEN_DIR}PrefKeys.cs"
#./resource_key_class_generator.exe MessageKeys "${RES_DIR}messages" > "${GEN_DIR}MessageKeys.cs"

# Delete the executable
rm -f resource_key_class_generator.exe

# Prevent the terminal from auto-closing
#read -rsp $'Press any key to continue...\n' -n1
