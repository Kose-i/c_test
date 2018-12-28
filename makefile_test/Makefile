all: main.o test.o
		g++ main.o test.o
main.o: src/main.c
		g++ -c src/main.c
test.o: src/test.c
		g++ -c src/test.c
clean:
		rm main.o test.o
