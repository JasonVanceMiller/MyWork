#include<stdio.h>



int main(){

	for(int i = -10; i < 11; i++){
		for(int j = -5; j < 6; j++){
			if(j != 0){
				printf("%d mod %d = %d\n",i,j,i%j);
			}
		}
	}
	








}
