tree : main.o BinarySearchTree.o 
	clang++ main.o BinarySearchTree.o -o tree

main.o : main.cpp BinarySearchTree.h 
	clang++ -c main.cpp 

BinarySearchTree.o : BinarySearchTree.cpp BinarySearchTree.h
	clang++ -c BinarySearchTree.cpp 

clean : 
	rm -f *.o tree