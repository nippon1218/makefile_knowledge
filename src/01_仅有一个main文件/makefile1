OBJECT = main.o

main: $(OBJECT)
	gcc -o main $(OBJECT)

main.o: main.c
	gcc -c main.c

.PHONY:
	clean

clean:
	rm -rf main
	rm -rf *.o
