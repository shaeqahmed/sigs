sig: sig.c
	gcc sig.c -o sig

run: sig
	./sig

clean: 
	rm *~
	rm sig