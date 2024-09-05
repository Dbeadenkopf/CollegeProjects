FLAGS = -Wall

all: AVLNode.o Driver.o AVLTreeBase.o AVLTree.o AVLForest.o 
	g++ $(FLAGS) AVLNode.o Driver.o AVLTreeBase.o AVLForest.o AVLTree.o -o output.out


AVLNode.o: AVLNode.cpp
	g++ $(FLAGS) AVLNode.cpp -c



AVLTreeBase.o: AVLTreeBase.cpp
	g++ $(FLAGS) AVLTreeBase.cpp -c


AVLTree.o: AVLTree.cpp
	g++ $(FLAGS) AVLTree.cpp -c

AVLForest.o: AVLForest.cpp 
	g++ $(FLAGS) AVLForest.cpp -c


Driver.o: Driver.cpp AVLForest.cpp AVLTreeBase.cpp AVLTreeBase.h AVLTree.cpp AVLTree.h AVLNode.h AVLNode.cpp
	g++ $(FLAGS) Driver.cpp -c


run:
	./output.out

clean:	
	rm -rf *.o
	rm -f *.out
	rm -f *~ *.h.gch *#
