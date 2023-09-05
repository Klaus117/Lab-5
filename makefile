default:
	gcc -std=c99 -o tictac.out tictac.c

debug:
	gcc -std=c99 -g -o tictac-debug.out tictac.c

run:
	./tictac.out

run-debug:
	gdb ./tictac-debug.out

clean:
	rm -f tictac.out
	rm -f tictac-debug.out

makecleanrun: clean default run


makecleanrundebug: clean debug run-debug
	
