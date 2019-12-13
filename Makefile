all: main

main: main.o
	g++ -lm -o main main.o

main.o: main.cpp
	g++ -O -c main.cpp

clean:
	rm -f main *.o
