klasy: main.o Classes.o
	g++ main.o Classes.o -o klasy

main.o: main.cpp
	g++ -c main.cpp

Classes.o: Classes.cpp Classes.h 
	g++ -c Classes.cpp

clean:
	rm *.o klasy
