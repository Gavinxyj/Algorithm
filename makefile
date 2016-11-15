target:algorihm.o test.o
	g++ -o algorithm algorihm.o test.o
algorihm.o:algorihm.cpp algorihm.h
	g++ -c algorihm.cpp
test.o:algorihm.h
	g++ -c test.cpp
clean:
	rm -rf *.o algorithm
