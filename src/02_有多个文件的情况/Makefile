#VPATH = ./single:
OBJECT = main.o cal.o single.o

main: $(OBJECT)
	gcc -o main $(OBJECT)

main.o: cal.h
	gcc -c main.c

cal.o:
	gcc -c cal.c

single.o: 
	gcc -c single/single.c

#single.o: 
#	gcc -c single.c

.PHONY:
	clean


clean:
	rm -rf *.o
	rm -rf main 

