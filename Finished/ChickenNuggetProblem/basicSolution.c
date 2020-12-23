/*
 *Jason Miller
 *basicSolution.c
 *
 *The basic solution that I made was to have a modular array. If a or b neighboring orders can be tested and all of them are make-able, then that means that the solution has already been found, because all other numbers can be generated from that set by adding a or b to each number. 
 *
 *Thus we keep an array storing the previous b (b>a) orders to check new orders against. When the streak hits a, then we have found our solution.  
 *
 *The runtime for this is O(solution) with the space complexity being O(b).
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//We need this because the way c defines mods are really annoying. 
long gcf(long a, long b){
	if(a == 0){
		return b;
	}
	if(b == 0){
		return a; 
	}
	if(a > b){
		return gcf(a - b * (a/b), b);
	}else{
		return gcf(a, b - a * (b / a));
	}
}	
long mod(long a, long b){
        long temp = a%b;
        if(temp < 0){
                temp += b;
        }
        return temp;
}
int main(int argc, char* argv[]){
	if(argc != 3){
		printf("Invalid parameters. Expected 3, got %d\n", argc);
		return -1;
	}	
	
	int a = atoi(argv[1]);
	int b = atoi(argv[2]);
	if(gcf(a,b) != 1){
		printf("Infinity\n");
		return -1;
	}
	if(a > b){
		int temp = a;
		a = b;
		b = temp;
	}
	long* array = (long*)malloc(sizeof(long) * (b+1));
	for(int i = 0; i < b+1; i++){
		array[i] = 0;
	}	
	int streak = 0;
	long index = a;
	while(streak < a){
	
		if(index == a){
			array[mod(index,b+1)] = 1;
		}
		else if(index == b){
			array[mod(index,b+1)] = 1;
		}
		else if(array[mod(index - a,b+1)] == 1){;	
			array[mod(index,b+1)] = 1;
			streak++;
		}
		else if(array[mod(index-b,b+1)] == 1){
			array[mod(index,b+1)] = 1;
			streak++;
		}
		else{
			array[mod(index,b+1)] = 0;
			streak = 0;
		}
		index++;
	}	
	printf("%ld is the largest order that can't be made\n", index - streak -1);
	free(array);
}

