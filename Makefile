all: main

main: main.cpp
	g++ main.cpp -Wall -o main

clean:
	rm -f main
