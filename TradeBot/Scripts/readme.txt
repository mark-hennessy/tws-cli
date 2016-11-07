Windows Setup Instructions
==
1. Install the NuGet package manager and add it to your PATH
2. Run the following command to install the latest C# compiler:
   nuget install Microsoft.Net.Compilers
3. Add the folder containing csc.exe to your PATH

Mac/Unix Setup Instructions
==
1. Install MonoDevelop. This should install the mcs and mono commands
2. Give the script execute permission
   chmod +x script_name

Notes
==
Windows and Mac/Unix use parallel but different commands to compile
and executable a C# application. This script will always run both versions
of the commands for robustness and simplicity. The "Command not found"
warnings can be ignored.
