default:
	gcc -o tictac.out tictac.c

debug:
	gcc -g -o tictac-debug.out tictac.c

run:
	./tictac.out

run-debug:
	gdb ./tictac-debug.out

clean:
	rm -f tictac.out
	rm -f tictac-debug.out