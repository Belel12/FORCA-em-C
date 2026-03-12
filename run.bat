mkdir .\bin
mkdir .\logs
gcc src\main.c -o bin\main.exe > logs\debug_info 2>&1
bin\main.exe