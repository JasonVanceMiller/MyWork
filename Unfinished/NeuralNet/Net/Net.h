/*
 *Net.h
 *
 *
 *
 *
 *
 *
 */
#ifndef NETH
#define NETH
#include"Matrix.h"
typedef struct Net{
        int layerNum;
        Matrix** layers;
	Matrix** layer_changes;
}Net;


/*
 *Goes and creates a new net with the heights of the layers being defined by the params.
 *Note:
 *
 *This is a basic net and there are things like circular nets or ragged nets that this does not do.
 */
Net * create_net(int * layerHeights, int layerNum);
/*
 *Goes through and randomizes all of the inputs.
 *
 */
void randomize(Net * N);
/*
 *N is the net Layer and I is the input.
 *
 *does evaluation on one layer
 */
Matrix * eval_layer(Matrix * N, Matrix * I);
/*
 *goes through and calls layer eval on all layers in the Net.
 *
 */
Matrix * eval(Net * N, Matrix * I);
/*
 *Preforms the sigmoid or other appropriate function on the input.
 *
 */
double squish(double x);
//add back prop
void learn(Net * N);

double grad(double w, double i);

void backProp(Net * N, Matrix * I, Matrix * O);

#endif


/*
 *	FIND OUT HOW TO FREE MATRIX
 *	The error function is (ideal - actual)^2
 *	and actual is squish of a bunch of values 
 *	we are chaning the weights as independent vars
 *	this makes the grad for all of the weights to be
 *	2(ideal-actual)*(squish)(1-squish)*(weight on connection)
 */







