@echo off
cd "C:\Users\Cameron\Desktop\code projects\C Programming\Done\C++\pyversioncreater"
g++ -v -fpermissive -c pyversioncreater.cpp -o pyversioncreater.o -Wwrite-strings -Wdeprecated-declarations -Wfatal-errors
PAUSE
g++ -v -static -static-libgcc -static-libstdc++ -o pyversioncreater.exe pyversioncreater.o
rm -v *.o
cd "C:\Users\Cameron\Desktop\code projects\C Programming\Done\C++\pyversioncreater"
