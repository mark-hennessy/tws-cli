#!/bin/sh

# This script generates C# models classes from json.

# Setup/Troubleshooting
# ==
# 1. Install the NuGet package manager and add it to your PATH
# 2. Run the following command to install the latest C# compiler:
#    nuget install Microsoft.Net.Compilers
# 3. Add the folder containing csc.exe to your PATH

# Important: The exe and dll's must be in the same directory!
ASSEMBLY_DIR="../References/JsonClassGenerator/"
EXE="${ASSEMBLY_DIR}model_generator.exe"
RES_DIR="../Resources/"
GEN_DIR="../Gen/"
NAMESPACE="TradeBot.Gen"

# Only compile the files needed to output the executable
csc /main:TradeBot.FileIO.CustomJsonClassGenerator /out:$EXE /reference:"${ASSEMBLY_DIR}Xamasoft.JsonClassGenerator.dll" /reference:"${ASSEMBLY_DIR}Newtonsoft.Json.dll" /reference:"${ASSEMBLY_DIR}System.Data.Entity.Design.PluralizationServices.dll" /recurse:../FileIO/*.cs

# Use the executable to generate files
./$EXE "${RES_DIR}state.json" "${GEN_DIR}StateProperties.cs" ${NAMESPACE}
./$EXE "${RES_DIR}messages.json" "${GEN_DIR}MessageProperties.cs" ${NAMESPACE}
./$EXE "${RES_DIR}preferences.json" "${GEN_DIR}PreferenceProperties.cs" ${NAMESPACE}

# Delete the executable
rm -f $EXE

# Prevent the terminal from auto-closing
#read -rsp $'Press any key to continue...\n' -n1
