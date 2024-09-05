FLAGS = -Wall -g


all: Heap.o Driver.o PinHit.o MinValueHeap.o MaxValueHeap.o 
	g++ $(FLAGS) Driver.o PinHit.o MinValueHeap.o -o output.out


Heap.o: Heap.cpp
	g++ $(FLAGS) Heap.cpp -c


MinValueHeap.o: MinValueHeap.cpp
	g++ $(FLAGS) MinValueHeap.cpp -c

MaxValueHeap.o: MaxValueHeap.cpp
	g++ $(FLAGS) MaxValueHeap.cpp -c


PinHit.o: PinHit.cpp
	g++ $(FLAGS) PinHit.cpp -c

Driver.o: Driver.cpp PinHit.cpp Heap.cpp PinHit.h Heap.h MinValueHeap.cpp MinValueHeap.h MaxValueHeap.cpp MaxValueHeap.h
	g++ $(FLAGS) Driver.cpp -c


run:
	./output.out $(PINS) $(TYPE) 

clean:
	rm -rf *.o
	rm -f *.out
	rm -f *~ *.h.gch *#


-UU-:----F1  Makefile       All L1     (GNUmakefile)----