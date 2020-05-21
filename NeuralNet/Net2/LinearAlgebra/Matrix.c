#include "Matrix.h"



matrix* matrix_create(int h, int w){
	matrix* M = (matrix*)malloc(sizeof(matrix));
	M->W = w;
	M->H = h;
	M->data = (float*)malloc(w*h*sizeof(float));
	
	float* temp = M->data;
	for(int i = 0; i < h*w; i++){
		*temp = i;
		temp += sizeof(float); 
	}

	return M;
}
//top right cornor is 0 0
// the data snakes right to left then top to bottom
float matrix_read_data(matrix* M, int w, int h){
	return *(M->data + sizeof(float)*((M->W)*h + w)); 
}

void matrix_change_data(matrix* M, int h, int w, float value){
	*(M->data + sizeof(float)*((M->W)*h + w)) = value; 	
}
matrix* matrix_multi(matrix* m1, matrix* m2){
	if(m1->W != m2->H){
		return NULL;
	}
	matrix * M = matrix_create(m1->H, m2->W); 
	float temp;
	for(int h = 0; h < M->H; h++){
		for(int w = 0; w < M->W; w++){
			temp = 0; 
			for(int i = 0; i < m1->W; i++){
				temp += matrix_read_data(m1, h, i) * matrix_read_data(m2, i, w); 
			}
			matrix_change_data(M, h, w, temp); 
		}
	}
	return M; 
}
void matrix_free(matrix* M){
	free(M->data);
	free(M);
}
matrix* matrix_load(FILE* in){

}

void matrix_save(FILE* out, matrix* M){
	float * temp = M->data;
	for(int h = 0; h < M->H; h++){
		for(int w = 0; w < M->W; w++){
			fprintf(out,"%f ", *temp);
			temp += sizeof(float);
		}
		fprintf(out,"\n");
	}
}                                          
