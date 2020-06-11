CC = gcc
OBJ = main.o read_vectors_complex.o calc_dotprod_complex.o 
OBJ2 = read_vectors_complex.o calc_dotprod_complex.o
CFLAGS = -Wall -o
CFLAGS2 = -c -fPIC

all: mymain
	export LD_LIBRARY_PATH=.

libmymathlib.so: $(OBJ2) 
	$(CC) -shared -o libmymathlib.so $(OBJ2)

mymain: $(OBJ) libmymathlib.so
	$(CC) -shared -o libmymathlib.so $(OBJ2)
	$(CC) $(CFLAGS) mymain main.o -L/homes/kahlonr/CS240/lab7/v10 -lmymathlib -lm 

main.o: main.c
	$(CC) $(CFLAGS2) main.c

read_vectors_complex.o: read_vectors_complex.c
	$(CC) $(CFLAGS2) read_vectors_complex.c

calc_dotprod_complex.o: calc_dotprod_complex.c
	$(CC) $(CFLAGS2) calc_dotprod_complex.c

