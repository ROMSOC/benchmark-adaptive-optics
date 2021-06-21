echo "Run MVM benchmark test"
cd source
cmake .
make release
benchmark.exe