/*
 *Jason Miller
 *18 November 2018
 *
 *Matrix.h
 *
 *This is the interface for Matrix
 *
 *The functions are:
 *matrix_multi
 *get_data
 *chnage_data
 *
 *
 */
#ifndef MATRIXH
#define MATRIXH

typedef struct Matrix{
	double** data;
	int rowNum;
	int colNum;
}Matrix;
/*
 *Creates a row x col matrix on the heap
 *All the values are not zeroed
 *
 *if row or col <= 0 then NULL is returned.
 */
Matrix * create_matrix(int row, int col); 
/*
 *Does matrix multiplication adn returns the matrix.
 *
 *if col of a != row or b then NULL is returned.
 *if a or b is NULL then NULL is returned.
 */
Matrix * matrix_multi(Matrix * a, Matrix * b);
/*
 *returns the data at the point r,c counting from 0
 *
 *0 is returned if M si NULL or if r or c is out of bounds.
 *
 */
double get_data(Matrix * M, int r, int c);

void change_data(Matrix * M, int r, int c, double val);
/*
 *Goes through and zeroes out all of the elements of the matrix.
 *
 *if M is NULL then nothing is done.
 */
void zero_matrix(Matrix * M);
/*
 *Goes through and prints the matrix.
 *
 *Nothing is printed if that matrix is NULL.
 *
 */
void print_matrix(Matrix * M);
#endif











