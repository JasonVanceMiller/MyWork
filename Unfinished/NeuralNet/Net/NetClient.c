/*
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
#include"Net.h"
#include"Matrix.h"
#include<stdlib.h>
#include<stdio.h>
int main(){
        srand(time(NULL));

	int * layers = malloc(sizeof(int)*4);
	layers[0] = 4;
	layers[1] = 5;
	layers[2] = 6;
	layers[3] = 2;
	Net * N = create_net(layers, 3);	
	randomize(N);
	Matrix * inputs = create_matrix(4,1);
	change_data(inputs, 0, 0, 1);
        change_data(inputs, 1, 0, 0);
        change_data(inputs, 2, 0, 0.5);
        change_data(inputs, 3, 0, 1);
	Matrix * results = eval(N, inputs);
	for(int i = 0; i < 10; i++){
		printf("%lf\n",get_data(results,0,0));
		printf("%lf\n",get_data(results,1,0));
		randomize(N);
		printf("\n");
	}


}
