#include "Matrix.h"

int main(int argc, char* argv[]){
	printf(" ");
	matrix * M = matrix_create(2,2);
	matrix_save(stdout, M);
	matrix_save(stdout, matrix_multi(M,M));
	return 0;
}
