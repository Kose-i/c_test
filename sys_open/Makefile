all: mouse_auto
mouse_auto: mouse_auto.o
	gcc -o mouse_auto mouse_auto.o
mouse_auto.o: mouse_auto.c
	gcc -c mouse_auto.c
clean:
	rm mouse_auto
	rm mouse_auto.o
