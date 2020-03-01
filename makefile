.PHONY: clean all

all: main.exe
clean:
	rm main.exe


CC=g++
flags=-std=c++14 -O2 -Wall

main.exe: main.cpp toolbox.hpp blocks.hpp property.hpp
	$(CC) $(flags) main.cpp -o main.exe 
