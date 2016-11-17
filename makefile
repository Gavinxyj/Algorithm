target:algorithm.o test.o
	g++ -o algorithm algorithm.o test.o
algorihm.o:algorithm.cpp algorithm.h
	g++ -c algorithm.cpp
test.o:algorithm.h
	g++ -c test.cpp
clean:
	rm -rf *.o algorithm
