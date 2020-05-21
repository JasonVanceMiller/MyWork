MatrixTest : MatrixTest.o Matrix.o
	gcc -o MatrixTest MatrixTest.o Matrix.o

MatrixTest.o : MatrixTest.c Matrix.h
	gcc -c MatrixTest.c

Matrix.o : Matrix.c Matrix.h
	gcc -c Matrix.c
clean :
	rm Matrix.o MatrixTest.o
