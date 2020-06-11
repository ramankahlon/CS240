CC = gcc
OBJ = main.o read_vectors.o calc_dotmag.o calc_diff.o calc_power.o 
OBJ2 = read_vectors.o calc_dotmag.o calc_diff.o calc_power.o
CFLAGS = -Wall -o
CFLAGS2 = -c -fPIC

all: mymain
	export LD_LIBRARY_PATH=.

mymain: $(OBJ) libmymathlib.so
	$(CC) -shared -o libmymathlib.so $(OBJ2)
	$(CC) $(CFLAGS) mymain main.o -L/homes/kahlonr/CS240/lab6/v10 -lmymathlib -lm 

main.o: main.c
	$(CC) $(CFLAGS2) main.c

read_vectors.o: read_vectors.c
	$(CC) $(CFLAGS2) read_vectors.c

calc_dotmag.o: calc_dotmag.c
	$(CC) $(CFLAGS2) calc_dotmag.c

calc_diff.o: calc_diff.c
	$(CC) $(CFLAGS2) calc_diff.c

calc_power.o: calc_power.c
	$(CC) $(CFLAGS2) calc_power.c
