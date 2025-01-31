@ECHO off

echo Hello, this script assumes that your C++ file is called test.cpp, if it is not, change it now and restart the script
pause
echo This script also assumes the cl is on path/you are running the Developer Command Prompt for VS 20XX
echo This script will generate a *input file name*.exe and a *input file name*.obj
pause

echo Building now

@REM Chage the file here
cl /EHsc test.cpp

echo Done Building
