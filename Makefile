FLAG = -Wall -O0 -g -std=c++14 -pedantic-errors

all: p1 Matrix

run: p1
	./p1

p1: main.o Matrix.o
	g++ -o p1 main.o Matrix.o

main.o: main.cpp
	g++ $(FLAG) -c main.cpp

Matrix: Matrix.cpp
	g++ $(FLAG) -c Matrix.cpp

clean:
	rm -f *.o
	rm -f *~
	rm -f p1
#hellomake: main.cpp Matrix.cpp
#	g++ -o hellomake main.cpp Matrix.cpp -I.
