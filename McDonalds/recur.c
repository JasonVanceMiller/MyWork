/*
 *
 *
 *
 *
 */
#include<stdio.h>

int recur(long val, int sub, int subLast);
int main(){

	for(int i = 0; i < 10000; i++){
		if(recur(i,0,0) == 0){
			printf("%d is not makeable\n", i);
		}

	}


}
int recur(long val, int sub, int subLast){
	if(sub < subLast){
		return 0;
	}
	val -= sub;
	if(val <= 0){
		return 0;
	}
	if(val == 5|| val == 12|| val == 20){
		return 1;
	}
	if(recur(val, 5, sub) == 1){
		return 1;
	}
	if(recur(val, 12, sub) == 1){
		return 1;
	}
	if(recur(val, 20, sub) == 1){
		return 1;
	}
	return 0;
}
