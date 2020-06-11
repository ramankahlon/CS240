dotmag.exe: read_vectors.o calc_dotmag.o calc_diff.o main.o libmymath.a
	ar rcs libmymath.a read_vectors.o
	ar rcs libmymath.a calc_dotmag.o
	ar rcs libmymath.a calc_diff.o
	gcc -o mymain main.o -static -L . -l mymath -lm
