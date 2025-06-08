@echo off
setlocal

:: This batch file helps compile, build, and run your C++ or C project using GNU Make.
:: It assumes this script is located in a root folder, and your project
:: is in a subdirectory specified by the first argument.
::
:: Make sure you have GNU Make installed and added to your system's PATH.
:: You can get Make as part of MinGW, MSYS2, or Chocolatey.

:: --- Configuration ---
:: The first command-line argument is now the relative path to the project directory.
:: Example usage: build.bat a\my_project build [c|cpp]
set PROJECT_RELATIVE_PATH=%1

:: Default compiler command line override is empty (Makefile's default CXX will be used)
set COMPILER_CMD_LINE=

:: --- Main Logic ---
:: Check if PROJECT_RELATIVE_PATH was provided
if "%PROJECT_RELATIVE_PATH%"=="" (
    echo Error: Project relative path not specified.
    echo Usage: build.bat ^<RELATIVE_PROJECT_PATH^> [command] [c^|cpp]
    echo Example: build.bat a\a_2 build cpp
    goto :eof
)

:: Construct the full path to the project directory
:: %~dp0 gives the drive and path of the batch file itself.
set "FULL_PROJECT_DIR=%~dp0%PROJECT_RELATIVE_PATH%"

:: Remove trailing slash if present, for consistent path handling
if "%FULL_PROJECT_DIR:~-1%"=="\" set "FULL_PROJECT_DIR=%FULL_PROJECT_DIR:~0,-1%"

:: Check if the Makefile exists in the specified project directory
if not exist "%FULL_PROJECT_DIR%\Makefile" (
    echo Error: Makefile not found in "%FULL_PROJECT_DIR%".
    echo Please make sure the specified RELATIVE_PROJECT_PATH leads to a directory containing your Makefile.
    goto :eof
)

:: Navigate to the project directory
pushd "%FULL_PROJECT_DIR%"

echo.
echo Currently operating in: %FULL_PROJECT_DIR%
echo.
echo Available commands:
echo   build [c or cpp] (Compiles and links the project)
echo   run [c or cpp]   (Compiles, links, and runs the executable)
echo   clean            (Removes compiled object files and the executable)
echo.
echo Optional language argument: 'c' for C compiler (gcc), 'cpp' for C++ compiler (g++).
echo If no language specified, the Makefile's default (g++) is used for build/run commands.
echo.

:: Argument parsing is now adjusted:
:: %1 is PROJECT_RELATIVE_PATH (already consumed)
:: %2 is COMMAND (build, run, clean)
:: %3 is COMPILER_CHOICE (c, cpp)

:: Check for the main command (build, run, clean) - now %2
if "%2"=="" (
    echo No command specified. Using 'build' by default.
    set COMMAND=build
) else (
    set COMMAND=%2
)

:: Determine the compiler based on the third argument (now %3)
if not "%3"=="" (
    if /i "%3"=="c" (
        set COMPILER_CMD_LINE=CXX=gcc
    ) else if /i "%3"=="cpp" (
        set COMPILER_CMD_LINE=CXX=g++
    ) else (
        echo Invalid language argument: %3
        echo Please use 'c' or 'cpp'.
        goto :eof
    )
)

:: Process the command
if /i "%COMMAND%"=="build" (
    goto :build_command
) else if /i "%COMMAND%"=="run" (
    goto :run_command
) else if /i "%COMMAND%"=="clean" (
    goto :clean_command
) else (
    echo Invalid command: %COMMAND%
    echo Please use 'build', 'run', or 'clean'.
    goto :eof
)

:build_command
echo --- Building Project ---
:: Pass FULL_PROJECT_DIR as a make variable if needed by Makefile, and compiler choice
mingw32-make all PROJECT_DIR="%FULL_PROJECT_DIR%" %COMPILER_CMD_LINE%
goto :end

:run_command
echo --- Running Project ---
:: Pass FULL_PROJECT_DIR as a make variable if needed by Makefile, and compiler choice
mingw32-make run PROJECT_DIR="%FULL_PROJECT_DIR%" %COMPILER_CMD_LINE%
goto :end

:clean_command
echo --- Cleaning Project ---
:: Language argument and PROJECT_DIR are not typically relevant for 'clean' in the Makefile.
mingw32-make clean
goto :end

:end
:: Return to the original directory
popd

echo.
echo Done.
