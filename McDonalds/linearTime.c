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
 */
#include<stdio.h>
#include<stdlib.h>
long mod(long a, long b){
	long temp = a%b;
	if(temp < 0){
		temp += b;
	}
	return temp;
}
int main(){
	long a = 101009;
	long b = 103967;
	long* array = (long*)malloc(sizeof(long) * (b+1));
	for(int i = 0; i < b+1; i++){
		array[i] = 0;
	}	
	int streak = 0;
	long index = a;
	while(streak < a){
	
		if(index == a){
			array[mod(index,b+1)] = 1;
		}else if(index == b){
			array[mod(index,b+1)] = 1;
		}else{
			if(array[mod(index - a,b+1)] == 1){;	
				array[mod(index,b+1)] = 1;
				streak++;
			}else if(array[mod(index-b,b+1)] == 1){
				array[mod(index,b+1)] = 1;
				streak++;
			}else{
				array[mod(index,b+1)] = 0;
				streak = 0;
			}
		}
		
		index++;
	}	
	printf("%d is the largest that can't be made\n", index - streak -1);
	free(array);
}

