main: main.o
	gcc -o main main.o
main_o: main.c
	gcc -c man.c
clean:
	rm main.o
	rm main
