/*
 *Net.c
 *
 *
 *
 *
 */
#include "Net.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
/*
 *Goes and create a new net with the heights of the lay ers being defined by the params.
 *Note:
 *
 *This is a basic net and there are things like circular nets or branching nets that this does not do.
 */
void randomize_matrix(Matrix * M);
Net * create_net(int * layerHeights, int layerNum){
	//other bad cases
	if(layerNum < 1){
		return NULL;
		fprintf(stderr,"layerNum of %d is invalid.\n",layerNum);
	}


	//assuming good cases
	Net * N = (Net*)malloc(sizeof(Net));
	N->layerNum = layerNum;
	N->layers = (Matrix**)malloc(sizeof(Matrix*)*(layerNum));
	for(int i = 0; i < layerNum; i++){
		N->layers[i] = create_matrix(layerHeights[i+1],layerHeights[i]);
	}
	return N;
}
/*
 *Goes through and randomizes all of the data in the N.
 *
 *
 *
 *
 */
void randomize(Net * N){
	for(int i = 0; i < N->layerNum; i++){
		randomize_matrix(N->layers[i]);
	}
}
/*
 *sub function for randomize.
 */
void randomize_matrix(Matrix * M){
	
	double rand_val;
	for(int i = 0; i < M-> rowNum; i++){
		for(int j = 0; j < M->colNum; j++){
			rand_val = ((double)rand())/RAND_MAX;
			rand_val = rand_val*10 - 5;
			change_data(M,i,j,rand_val);
		}
	}

}
/*
 *Preforms the sigmoid or other appropriate function on the input.
 *
 *
 */
double squish(double x){
	x = exp(-x);
	x = 1/(1+x);
	return x;
}
/*
 *Squishes the inputs then preforms eval layer on all layers and returns the final matrix. 
 *
 *
 */
Matrix * eval(Net * N, Matrix * I){
	Matrix * temp = I;
	for(int i = 0; i < I->rowNum;i++){
		change_data(I, i, 0, squish(get_data(I, i, 0));
	}
	for(int i = 0; i < N->layerNum; i++){
		temp = eval_layer(N->layers[i],temp);
	}
	return temp;
}
Matrix * eval_layer(Matrix * N, Matrix * I){
	Matrix * temp = matrix_multi(N, I);
	for(int i = 0; i < temp->rowNum; i++){
		change_data(temp, i, 0, squish(get_data(temp, i, 0)));
	}
	return temp;

}
void learn(Net* N){


}
double grad(double w, double i){



}
void backProp(Net* N, Matrix* I, Matrix* O){


}
