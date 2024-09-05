CPPFLAGS = -ansi -Wall -gstabs+


main:  node.o linked.o p5main1.o 
	g++ linked.o node.o p5main1.o

linked.o: linked.h linked.cpp
	g++ linked.cpp -c 

node.o: node.h node.cpp
	g++ node.cpp -c

p5main1.o: p5main1.cpp
	g++ p5main1.cpp -c

clean: 
	rm -f *.o *.out *~ *.gch main

run:
	./p5main1.cpp
