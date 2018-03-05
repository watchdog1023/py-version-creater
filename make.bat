@echo off
g++ -v -fpermissive -c pyversioncreater.cpp -o pyversioncreater.o -Wwrite-strings -Wdeprecated-declarations -Wfatal-errors
PAUSE
g++ -v -static -static-libgcc -static-libstdc++ -o pyversioncreater.exe pyversioncreater.o
rm -v *.o
