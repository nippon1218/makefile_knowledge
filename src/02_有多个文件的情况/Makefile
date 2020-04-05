OBJECT = main.o cal.o

main: $(OBJECT)
	gcc -o main $(OBJECT)

main.o: main.c cal.h
	gcc -c main.c

cal.o: cal.c
	gcc -c cal.c

.PHONY:
	clean

clean:
	rm -rf *.o
	rm -rf main 

