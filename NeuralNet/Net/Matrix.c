/*
 *Jason Miller
 *18 November 2018
 *
 *Matrix.c
 *
 *This is the implimentations of the functions in Matrix.h
 *
 *The functions are:
 *matrix_multi
 *get_data
 *change_data
 *
 *
 *
 */
#include "Matrix.h"
#include <stdlib.h>
#include <stdio.h>
/*
 *Creates a row x col matrix on the heap
 *All the values are not zeroed
 *
 *if row or col <= 0 then NULL is returned.
 */
Matrix * create_matrix(int row, int col){
	if(row > 0 && col > 0){
		Matrix * M	= (Matrix*)malloc(sizeof(Matrix));
		M->rowNum 	= row;
		M->colNum 	= col;
		M->data		= (double **)malloc(row * sizeof(double*));
		for(int i = 0; i < row; i++){
			(M->data)[i] = (double *)malloc(col * sizeof(double));
		}
		return M;
	}
	return NULL;
}
/*
 *Does matrix multiplication and returns the matrix. 
 *
 *if col of a != row of b then NULL is returned.
 *if a or b is NULL then NULL is returned.
 */
Matrix * matrix_multi(Matrix * a, Matrix * b){
	if(a != NULL && b != NULL){
		if(a->colNum == b->rowNum){
			Matrix *M = create_matrix(a->rowNum, b->colNum);
			M->rowNum = a -> rowNum;
			M->colNum = b -> colNum;
			zero_matrix(M);
			for(int i = 0; i < a->rowNum; i++){
				for(int j = 0; j < b->colNum; j++){
					for(int k = 0; k < a-> colNum; k++){
						change_data(M, i, j, get_data(M, i, j) +
						get_data(a, i, k)*get_data(b, k, j));
					}
				}
			}
			return M;
		} 
	}
	return NULL;
}
/*
 *Goes through and zeroes out all of the elements of the matrix.
 *
 *if M is NULL then nothing is done
 */
void zero_matrix(Matrix * M){
	if(M != NULL){
		for(int i = 0; i < M->rowNum; i++){
			for(int j = 0; j < M->colNum; j++){
				change_data(M,i,j,0);
			}
		}
	}
}
/*
 *Goes through and prints the matrix. 
 *
 *Nothing is printed if that matrix is NULL;
 *
 */
void print_matrix(Matrix * M){
	if(M != NULL){
		for(int i = 0; i < M->rowNum; i++){
			printf("|");
			for(int j = 0; j < M->colNum; j++){
				double data = get_data(M,i,j);
				if(data > 0){
				printf(" ");
				}
				printf("%f ",data);
			}
			printf("|\n");
		}
		printf("\n");
	}
}
/*
 *returns the data at the point r,c (counting from 0)
 *
 *0 is returned if M is NULL or if r or c is out of bounds.
 *
 *
 *
 *
 */
double get_data(Matrix * M, int r, int c){
	if(M != NULL){
		if(M->rowNum > r && M->colNum > c){
			return (M->data)[r][c];
		}
	}
	return 0; 
}
/*
 *changes the data value at the point r,c (counting from 0)
 *
 *Nothing is done if M is null or r and c are invalid
 *
 */
void change_data(Matrix * M, int r, int c, double val){
	if(M != NULL){
		if(M->rowNum > r && M->colNum > c){
			(M->data)[r][c] = val;
		}
	}
}
