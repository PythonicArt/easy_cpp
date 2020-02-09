@echo off
clang++ main.cpp solution.cpp -o output.exe >nul
echo "compile success, please excute output.exe!!!!!"

clang++ a.cpp b.cpp -o output.exe
