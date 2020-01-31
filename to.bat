@echo off

set filename=%1
if "%filename%"=="" (
echo error: no file name input) else (
echo "target name is" %filename%.cpp
copy solution.cpp .\pass\%filename%.cpp
)
