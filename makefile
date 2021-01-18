

all: frequency

frequency: frequency.o treelib.a
	gcc -Wall -g frequency.o treelib.a -o frequency


frequency.o: frequency.c
	gcc -Wall -g -c frequency.c 


treelib.a: treeFunction.o
	ar -rcs treelib.a treeFunction.o

treeFunction.o: tree.h treeFunction.c
	gcc -Wall -g -c treeFunction.c

clean:
	rm *.o *.a frequency
