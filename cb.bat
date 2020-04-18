@echo off
clang --driver-mode=cl -D_HAS_EXCEPTIONS=0 /GR- main.cpp solution.cpp common.cpp -o output.exe >nul
echo "compile success, please excute output.exe!!!!!"
