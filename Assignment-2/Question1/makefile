output: main.o
	g++ main.o -o output

main.o : main.cpp
	g++ -c main.cpp

num_comp.o : num_comp.h num_comp.cpp
	g++ -c num_comp.cpp

clean:
	rm *.o output