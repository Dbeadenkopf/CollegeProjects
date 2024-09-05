FLAGS = -Wall -g


all: proj2.o Pokemon.o MyPokemon.o
	g++ $(FLAGS) proj2.o Pokemon.o MyPokemon.o -o output.out

Pokemon.o: Pokemon.cpp
	g++ $(FLAGS) Pokemon.cpp -c

MyPokemon.o: MyPokemon.cpp
	g++ $(FlAGS) MyPokemon.cpp -c


proj2.o: proj2.cpp MyPokemon.h MyPokemon.cpp Pokemon.cpp Pokemon.h
	g++ $(FLAGS) proj2.cpp -c

run:
	./output.out

clean:
	rm -rf *.o
	rm -f *.out
	rm -f *~ *.h.gch *#


