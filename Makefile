CFLAGS=-Wall -g

#all: ex1 ex3 ex4

%: src/%.c
	cc $(CFLAGS) $< -o bin/$@ 

#ex1: ex1.c
#	cc $(CFLAGS) ex1.c -o bin/ex1

#ex3: ex3.c
#	cc $(CFLAGS) ex3.c -o bin/ex3

#ex4: ex4.c
#	cc $(CFLAGS) ex4.c -o bin/ex4

clean:
	rm -f bin/ex*
