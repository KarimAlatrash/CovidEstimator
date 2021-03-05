# Makefile for Project 2
#


# List all the drivers
all: main


# list the test program all classes (cpp files)
#  cpp files must use #include , to include *.h or *.hpp files

main: main.cpp dataset.cpp queue.cpp linalg.cpp node.cpp COVID_new_cases.hpp
	g++ -std=c++11 -o main.o main.cpp dataset.cpp queue.cpp linalg.cpp node.cpp COVID_new_cases.hpp

# List all the executables under 'all:'
clean:
	rm main.o
