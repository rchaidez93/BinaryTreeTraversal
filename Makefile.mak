all: funProject

funProject: btmain.o buildTree.o traversals.o 
	gcc btmain.o buildTree.o traversals.o -o funProject
	
btmain.o: btmain.c
	gcc -c btmain.c
	
buildTree.o: buildTree.c
	gcc -c buildTree.c
	
traversals.o: traversals.c
	gcc -c traversals.c
	
clean:
	rm -rf *.o funProject