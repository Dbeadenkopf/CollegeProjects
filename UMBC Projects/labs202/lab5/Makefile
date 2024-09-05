CPPFLAGS = -ansi -Wall

lab5: Complex.o lab5.o
	g++ -Wall lab5.cpp Complex.h Complex.cpp -o lab5 

lab5.o: lab5.cpp Complex.h
	g++ -c lab5.cpp  -o lab

Complex.o: Complex.cpp
	g++ -c Complex.cpp Complex.h -o lab5