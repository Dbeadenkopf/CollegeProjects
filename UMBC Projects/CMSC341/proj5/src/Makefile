FLAGS = -Wall -g


all: Driver.o Pinball.o
	g++ $(FLAGS) Driver.o Pinball.o -o output.out

Pinball.o: Pinball.cpp
	g++ $(FLAGS) Pinball.cpp -c

Driver.o: Driver.cpp Pinball.h Pinball.cpp
	g++ $(FLAGS) Driver.cpp -c  

run:
	./output.out 

clean:
	rm -rf *.o
	rm -f *.out
	rm -f *~ *.h.gch *#



