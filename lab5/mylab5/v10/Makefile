all: libmymathlib.so mymain 

mymain: read_vectors.o calc_dotmag.o calc_diff.o calc_power.o main.o libmymathlib.so
	gcc -Wall -o mymain main.o -L/homes/kahlonr/CS240/lab5/v10 -lmymathlib -lm 
