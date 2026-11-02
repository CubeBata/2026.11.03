@echo off
setlocal enabledelayedexpansion

:: for color text
for /F %%A in ('echo prompt $E ^| cmd') do set "ESC=%%A"

set "CLEAR_SCREEN=false"
set "FROM_SCRATCH=false"

:parse_arguments
if "%~1" == "" goto end_arguments

if "%~1" == "-c" (
    set "CLEAR_SCREEN=true"
) else if "%~1" == "--clear" (
    set "CLEAR_SCREEN=true"
) else if "%~1" == "-fs" (
    set "FROM_SCRATCH=true"
) else if "%~1" == "--from-scratch" (
    set "FROM_SCRATCH=true"
) else (
    call :output "Error: unknown flag: %~1" 41
    goto to_exit
)

shift
goto parse_arguments

:end_arguments

if "%CLEAR_SCREEN%" == "true" cls

if "%FROM_SCRATCH%" == "true" (
    if exist build rmdir /s /q build
    mkdir build
)

:to_main

if not exist build mkdir build
cd build
call :output %cd%"> cmake .." 44
cmake ..
call :output "==========[ ECHO: DONE ]=========" 42
call :output %cd%"> cmake --build ." 44
cmake --build .
call :output "==========[ ECHO: DONE ]=========" 42
cd ..
goto to_exit

:output 
if "%~2" == "" (
    echo %~1
) else (
    echo !ESC![%~2m%~1!ESC![0m
)
exit /b


:to_exit
exit /b 0
