#!/bin/bash

# This script generates C# models classes from json

# Change to the directory where the script is stored no matter how the script is run
SCRIPT_DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
cd "${SCRIPT_DIR}"

# Important: The exe and dll's must be in the same directory!
ASSEMBLY_DIR="../Libs/JsonClassGenerator/"
EXE="${ASSEMBLY_DIR}model_generator.exe"
RES_DIR="../Resources/"
GEN_DIR="../Generated/"
NAMESPACE="TradeBot.Generated"

{
  ## Compile the files needed to output the executable

  # For Windows
  csc /main:TradeBot.FileIO.CustomJsonClassGenerator /out:$EXE /reference:"${ASSEMBLY_DIR}Xamasoft.JsonClassGenerator.dll" /reference:"${ASSEMBLY_DIR}Newtonsoft.Json.dll" /reference:"${ASSEMBLY_DIR}System.Data.Entity.Design.PluralizationServices.dll" /recurse:../FileIO/*.cs

  # For Mac/Unix
  mcs -main:TradeBot.FileIO.CustomJsonClassGenerator -out:$EXE -reference:"${ASSEMBLY_DIR}Xamasoft.JsonClassGenerator.dll" -reference:"${ASSEMBLY_DIR}Newtonsoft.Json.dll" -reference:"${ASSEMBLY_DIR}System.Data.Entity.Design.PluralizationServices.dll" -recurse:../FileIO/*.cs

  ## Use the executable to generate files

  # For Windows
  ./$EXE "${RES_DIR}state.json" "${GEN_DIR}AppState.cs" ${NAMESPACE} true
  ./$EXE "${RES_DIR}messages.json" "${GEN_DIR}AppMessages.cs" ${NAMESPACE}
  ./$EXE "${RES_DIR}preferences.json" "${GEN_DIR}AppPreferences.cs" ${NAMESPACE}

  # For Mac/Unix
  mono ./$EXE "${RES_DIR}state.json" "${GEN_DIR}AppState.cs" ${NAMESPACE} true
  mono ./$EXE "${RES_DIR}messages.json" "${GEN_DIR}AppMessages.cs" ${NAMESPACE}
  mono ./$EXE "${RES_DIR}preferences.json" "${GEN_DIR}AppPreferences.cs" ${NAMESPACE}

# Hide "Command not found" warnings and all other output
} &> /dev/null

# Delete the executable
rm -f $EXE

# Prevent the terminal from auto-closing on Windows
#read -rsp $'Press any key to continue...\n' -n1
