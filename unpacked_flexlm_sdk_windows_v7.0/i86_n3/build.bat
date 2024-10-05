echo off
echo ***************************************************************************
echo Build.bat can be used in 3 ways                                           *
echo build MT     - This builds all of the files using the /MT compiler flag   *
echo               ( Multi-threaded C Runtime as a static library )            *
echo build MD     - This builds all of the files using the /MD compiler flag   *
echo               ( Multi-threaded C Runtime as a static library )            *
echo build DLL     - This build all of the files to use the flexlm dll         *
echo ***************************************************************************                                           

if "%1" =="MD" goto md
if "%1" =="DLL" goto dll

echo Building using the /MT flag
nmake 
goto end1

:md
echo Building using the /MD flag
nmake /f makefile_md
goto end1


:dll
echo Building , linking to the FLEXlm dll
nmake /f makefile_dll


:end1

