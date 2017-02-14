#Simple makefile for task 1
tagremover_main: tagremover.o tagremover_main.o
	g++ -o tagremover_main tagremover.o tagremover_main.o

tagremover.o: tagremover.cc tagremover.h
	g++ tagremover.cc -c -std=c++11

tagremover_main.o: tagremover_main.cc tagremover.h
	g++ tagremover_main.cc -c -std=c++11
