FLAGS = -Wall

all: test.o Llama.o LlamaNode.o 
	g++ $(FLAGS) test.o Llama.o LlamaNode.o -o output.out

Country.o: LlamaNode.cpp
	g++ $(FLAGS) LlamaNode.cpp -c


Continent.o: Llama.cpp
	g++ $(FLAGS) Llama.cpp -c

Driver.o: test.cpp Llama.h LlamaNode.h
	g++ $(FLAGS) test.cpp -c

run:
	./output.out

clean:
	rm -rf *.o
	rm -f *.out
	rm -f *~ *.h.gch *#

