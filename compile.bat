@ECHO off

echo Hello, this script assumes that your C++ file is called test.cpp, if it is not, change it now and restart the script
pause
echo This script also assumes the cl is on path/you are running the Developer Command Prompt for VS 20XX
echo This script will generate a *input file name*.exe and a *input file name*.obj
pause

echo Building now

@REM Chage the file here

cl /EHsc test.cpp

if %ERRORLEVEL% == 0 (
    echo Done Building
    set ERRORLEVEL=0
) else if %ERRORLEVEL% == 9009 (
    echo ERROR: CL is not on path or you are not running the Developer Command Prompt for VS 20XX
    set ERRORLEVEL=1
) else (
    echo UNKNOWN ERROR HAS OCCURED WHILE BUILDING!
    set ERRORLEVEL=-1
)