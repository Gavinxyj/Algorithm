target:algorithm.o test.o
	g++ -g -o algorithm algorithm.o test.o
algorihm.o:algorithm.cpp algorithm.h
	g++ -g -c algorithm.cpp
test.o:algorithm.h
	g++ -g -c test.cpp
clean:
	rm -rf *.o algorithm
