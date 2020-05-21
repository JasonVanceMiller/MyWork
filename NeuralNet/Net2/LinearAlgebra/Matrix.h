/*
 *matrix.h
 *Created Sep 16 2019 
 *Last changed Sep 16 2019
 *by Jason Miller
 *
 *This is the .h file matrix.c
 */


//the convintion is that a 3x4 is a 3 row 4 column matrix and the 1,2 entry is in the first row second column. 
#include <stdlib.h>
#include <stdio.h>
typedef struct matrix{
	int H;
	int W;
	float * data;
}matrix;

matrix* matrix_create(int h, int w);

float matrix_read_data(matrix* M, int h, int w);

void matrix_change_data(matrix* M,int h, int w, float value);

matrix* matrix_multi(matrix* m1, matrix* m2);

void matrix_free(matrix* M);

matrix* matrix_load(FILE* in);

void matrix_save(FILE* out, matrix* M);
