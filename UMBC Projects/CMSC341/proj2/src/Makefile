FLAGS = -Wall

all: Driver.o Commodity.o Objective.o CommodityStore.o Card.o Player.o Game.o
	g++ $(FLAGS) Driver.o Card.o Commodity.o Objective.o CommodityStore.o Game.o -o output.out

Commodity.o: Commodity.cpp
	g++ $(FLAGS) Commodity.cpp -c


Objective.o: Objective.cpp
	g++ $(FLAGS) Objective.cpp -c


CommodityStore.o: CommodityStore.cpp
	g++ $(FLAGS) CommodityStore.cpp -c


Player.o: Player.cpp
	g++ $(FLAGS) Player.cpp -c


Card.o: Card.cpp
	g++ $(FLAGS) Card.cpp -c

Game.o: Game.cpp 
	g++ $(FLAGS) Game.cpp -c

Driver.o: Driver.cpp Commodity.h Objective.h CommodityStore.h Card.h Player.h Game.h
	g++ $(FLAGS) Driver.cpp -c


run: 
	./output.out $(CARDS) $(COMMODITIES) $(PLAYERS) $(STRATEGY) 

clean:
	rm -rf *.o
	rm -f *.out
	rm -f *~ *.h.gch *#

