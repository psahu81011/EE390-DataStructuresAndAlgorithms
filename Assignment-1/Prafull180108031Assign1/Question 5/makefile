output: main.o account.o
	g++ main.o account.o -o output

main.o : main.cpp
	g++ -c main.cpp

account.o : account.cpp account.h
	g++ -c account.cpp

clean:
	rm *.o output