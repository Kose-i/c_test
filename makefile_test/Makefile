all: main.o test.o
		g++ -o main main.o test.o
main.o: src/main.cpp
		g++ -c src/main.cpp
test.o: src/test.cpp
		g++ -c src/test.cpp
clean:
		rm main.o test.o
