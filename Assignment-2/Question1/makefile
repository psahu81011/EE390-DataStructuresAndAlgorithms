output: main.o num_comp.o
	g++ main.o -o output

main.o : main.cpp
	g++ -c main.cpp

num_comp.o : num_comp.h
	g++ -c num_comp.h

clean:
	rm *.o output *.gch