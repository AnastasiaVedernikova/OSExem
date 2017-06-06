
all : OSExam

OSExam: main.o
	g++ main.o -o OSExam

main.o: main.cpp
	g++ -c main.cpp
