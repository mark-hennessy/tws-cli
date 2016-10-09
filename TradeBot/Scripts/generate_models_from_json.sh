#!/bin/bash

# This script generates C# models classes from json.

# Windows Setup Instructions
# ==
# 1. Install the NuGet package manager and add it to your PATH
# 2. Run the following command to install the latest C# compiler:
#    nuget install Microsoft.Net.Compilers
# 3. Add the folder containing csc.exe to your PATH

# Mac/Unix Setup Instructions
# ==
# 1. Install MonoDevelop. This should install the mcs and mono commands

# Notes
# ==
# Windows and Mac/Unix use parallel but different commands to compile
# and executable a C# application. This script will always run both versions
# of the commands for robustness and simplicity. The "Command not found"
# warnings can be ignored.

# This will change to the directory where the script is stored
# no matter how the script is run.
DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
cd "${DIR}"

# Important: The exe and dll's must be in the same directory!
ASSEMBLY_DIR="../References/JsonClassGenerator/"
EXE="${ASSEMBLY_DIR}model_generator.exe"
RES_DIR="../Resources/"
GEN_DIR="../Gen/"
NAMESPACE="TradeBot.Gen"

{
  ## Compile the files needed to output the executable

  # For Windows
  csc /main:TradeBot.FileIO.CustomJsonClassGenerator /out:$EXE /reference:"${ASSEMBLY_DIR}Xamasoft.JsonClassGenerator.dll" /reference:"${ASSEMBLY_DIR}Newtonsoft.Json.dll" /reference:"${ASSEMBLY_DIR}System.Data.Entity.Design.PluralizationServices.dll" /recurse:../FileIO/*.cs

  # For Mac/Unix
  mcs -main:TradeBot.FileIO.CustomJsonClassGenerator -out:$EXE -reference:"${ASSEMBLY_DIR}Xamasoft.JsonClassGenerator.dll" -reference:"${ASSEMBLY_DIR}Newtonsoft.Json.dll" -reference:"${ASSEMBLY_DIR}System.Data.Entity.Design.PluralizationServices.dll" -recurse:../FileIO/*.cs

  ## Use the executable to generate files

  # For Windows
  ./$EXE "${RES_DIR}state.json" "${GEN_DIR}StateProperties.cs" ${NAMESPACE} true
  ./$EXE "${RES_DIR}messages.json" "${GEN_DIR}MessageProperties.cs" ${NAMESPACE}
  ./$EXE "${RES_DIR}preferences.json" "${GEN_DIR}PreferenceProperties.cs" ${NAMESPACE}

  # For Mac/Unix
  mono ./$EXE "${RES_DIR}state.json" "${GEN_DIR}StateProperties.cs" ${NAMESPACE} true
  mono ./$EXE "${RES_DIR}messages.json" "${GEN_DIR}MessageProperties.cs" ${NAMESPACE}
  mono ./$EXE "${RES_DIR}preferences.json" "${GEN_DIR}PreferenceProperties.cs" ${NAMESPACE}

# Hide "Command not found" warnings and all other output
} &> /dev/null

# Delete the executable
rm -f $EXE

# Prevent the terminal from auto-closing on Windows.
# Comment out if debugging the script.
#read -rsp $'Press any key to continue...\n' -n1
