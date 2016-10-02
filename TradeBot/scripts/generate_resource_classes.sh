#!/bin/sh

# This script generates C# classes for property values.

# Setup/Troubleshooting
# ==
# 1. Install the NuGet package manager and add it to your PATH
# 2. Run the following command to install the latest C# compiler:
#    nuget install Microsoft.Net.Compilers
# 3. Add the folder containing csc.exe to your PATH

RES_DIR="../res/"
GEN_DIR="../Core/Resources/"

# Only compile the files needed to output the executable
csc /main:TradeBot.Core.FileIO.ResourceClassGenerator /out:resource_class_generator.exe /recurse:../Core/FileIO/*.cs

# Use the executable to generate files
./resource_class_generator.exe Preferences true "${RES_DIR}default.prefs" "${RES_DIR}user.prefs" > "${GEN_DIR}Preferences.cs"
./resource_class_generator.exe Messages true "${RES_DIR}messages" > "${GEN_DIR}Messages.cs"
./resource_class_generator.exe AppState false "${RES_DIR}app.state" > "${GEN_DIR}AppState.cs"

# Delete the executable
rm -f resource_class_generator.exe

# Prevent the terminal from auto-closing
#read -rsp $'Press any key to continue...\n' -n1
