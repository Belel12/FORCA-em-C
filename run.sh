mkdir -p ./bin
mkdir -p ./logs
gcc ./src/main.c -o ./bin/main &> ./logs/debug_info
./bin/main