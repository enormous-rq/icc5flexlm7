@echo off
if %PROCESSOR_ARCHITECTURE%.== x86.        goto x86Env
if %PROCESSOR_ARCHITECTURE%.== MIPS.       goto mipsEnv
if %PROCESSOR_ARCHITECTURE%.== ALPHA.      goto alphaEnv
if %PROCESSOR_ARCHITECTURE%.== PPC.        goto ppcEnv
goto error

:x86Env
REM *** Available command-line options:
REM ***     /Q option runs the install without dialogs (Quiet Mode).
REM ***     /P{Full path to SENTINEL.SYS} to specify the path if the current
REM ***        directory is not the directory SETUPX86.EXE resides
REM ***	    /O to unconditionally overwrite the existing driver files.
REM ***	       Without /O, the existing driver will be preserved if it
REM ***        is newer then the one to be installed.
REM ***     /U to uninstall the existing driver.
REM e.g.    SETUPX86.EXE /Q /O /PD:\PROUDCT\DRIVERS\WIN_NT\I386
REM         SETUPX86.EXE /Q /U to un-install the driver
SETUPX86.EXE %1 %2 %3
goto end

:mipsEnv
REM *** Available command-line options:
REM ***     /Q option runs the install without dialogs (Quiet Mode).
REM ***     /P{Full path to SENTINEL.SYS} to specify the path if the current
REM ***        directory is not the directory SETUPMPS.EXE resides
REM ***	    /O to unconditionally overwrite the existing driver files.
REM ***	       Without /O, the existing driver will be preserved if it
REM ***        is newer then the one to be installed.
REM ***     /U to uninstall the existing driver.
REM e.g.    SETUPMPS.EXE /Q /O /PD:\PROUDCT\DRIVERS\WIN_NT\MIPS
REM         SETUPMPS.EXE /Q /U to un-install the driver
SETUPMPS.EXE %1 %2 %3
goto end

:alphaEnv
REM *** Available command-line options:
REM ***     /Q option runs the install without dialogs (Quiet Mode).
REM ***     /P{Full path to SENTINEL.SYS} to specify the path if the current
REM ***        directory is not the directory SETUPAXP.EXE resides
REM ***	    /O to unconditionally overwrite the existing driver files.
REM ***	       Without /O, the existing driver will be preserved if it
REM ***        is newer then the one to be installed.
REM ***     /U to uninstall the existing driver.
REM e.g.    SETUPAXP.EXE /Q /O /PD:\PROUDCT\DRIVERS\WIN_NT\ALPHA
REM         SETUPAXP.EXE /Q /U to un-install the driver
SETUPAXP.EXE %1 %2 %3
goto end

:ppcEnv
REM *** Available command-line options:
REM ***     /Q option runs the install without dialogs (Quiet Mode).
REM ***     /P{Full path to SENTINEL.SYS} to specify the path if the current
REM ***        directory is not the directory SETUPPPC.EXE resides
REM ***	    /O to unconditionally overwrite the existing driver files.
REM ***	       Without /O, the existing driver will be preserved if it
REM ***        is newer then the one to be installed.
REM ***     /U to uninstall the existing driver.
REM e.g.    SETUPPPC.EXE /Q /O /PD:\PROUDCT\DRIVERS\WIN_NT\PPC
REM         SETUPPPC.EXE /Q /U to un-install the driver
SETUPPPC.EXE %1 %2 %3
goto end

:error
ECHO.
ECHO Error PROCESSOR_ARCHITECTURE not defined!!  Automatic processor
ECHO    detection failed.  To install the Sentinel Driver, please
ECHO    do the following:
ECHO.
ECHO    1. If you are running NT on Intel platform (Most IBM compatible
ECHO         machines are intel or intel compatible), please run the file
ECHO         SETUPX86.EXE.
ECHO    2. If you are running NT on DEC Alpha platform, please run the
ECHO         file SETUPAXP.EXE.
ECHO    3. If you are running NT on MIPS or MIPS compatible platform,
ECHO         please run the file SETUPMPS.EXE.
ECHO    4. If you are running NT on PowerPC or PowerPC compatible platform,
ECHO         please run the file SETUPPPC.EXE.
ECHO.

:end
