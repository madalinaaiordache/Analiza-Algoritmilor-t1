CC = g++
CFLAGS = -Wall -Wextra -O2
LDLIBS = -lm

build: algo.o algo_bellman_ford.o algo_djikstra.o algo_floyd_warshall.o

algo.o: algo.cpp
	g++ algo.cpp -c $(CFLAGS)


run-p1: algo_bellman_ford.cpp tester.cpp
	g++ algo_bellman_ford.cpp tester.cpp $(CFLAGS) -o bellman_ford
	for number in 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 ; do \
		./bellman_ford test$$number test$$number ; \
	done

run-best: algo_djikstra.cpp tester.cpp
	g++ algo_djikstra.cpp tester.cpp $(CFLAGS) -o djikstra
	for number in 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 ; do \
		./djikstra test$$number test$$number ; \
	done

run-p2: algo_floyd_warshall.cpp tester.cpp
	g++ algo_floyd_warshall.cpp tester.cpp $(CFLAGS) -o floyd_warshall
	for number in 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 ; do \
		./floyd_warshall test$$number test$$number ; \
	done

generator: generator.cpp
	g++ generator.cpp $(CFLAGS) -o generator
	./generator

.PHONY: clean
clean:
	rm -rf *.o bellman_ford floyd_warshall djikstra best_implem