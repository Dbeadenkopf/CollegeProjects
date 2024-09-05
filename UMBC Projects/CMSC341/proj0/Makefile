FLAGS = -Wall

all: Driver.o Country.o Continent.o
	g++ $(FLAGS) Driver.o Country.o Continent.o -o output.out

Country.o: Country.cpp
	g++ $(FLAGS) Country.cpp -c


Continent.o: Continent.cpp
	g++ $(FLAGS) Continent.cpp -c

Driver.o: Driver.cpp Country.h Coninent.h
	g++ $(FLAGS) Driver.cpp -c

run:
	./output.out

clean:
	rm -rf *.o
	rm -f *.out
	rm -f *~ *.h.gch *#
