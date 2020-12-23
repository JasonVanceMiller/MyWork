/*
 *Jason Miller
 *advancedSolution.c
 *
 *This solution gets a bit complex so bare with me. 
 *
 *The problem with the basic solution was that it couldn't solve a single number quickly. To solve for n, you had to solve for all numbers less than n. This solution gets its optomization from being able to solve a single number in isolation. 

 * 
 *If we can find out how to make 1 by combining negative amounts of a or b, then we can check a single number very quickly by exchaning a quantities of b and b quantities of a. Then if we land on positive quantiites of both we know that that number can be made. 
 *
 *This calculation for a single number can be done in CONSTANT TIME. which means we can be very sparse about the numbers we check. 
 *
 *This program will first do some initial calculations, followed by exponentially jumping around the natural numbers until we get a sequence of 'a' numbers that can all be constructed. This means we are now ahead of the largest nonconstructable number, and we can count down until we find true number. 
 *
 */
#include<stdlib.h>
#include<stdio.h>

long	gcf(long a, long b);
void	gcfMulti(long * a, long * b);

int check(long a, long b, long val);
int checkFast(long a, long b, long val, long aMulti, long bMulti);
int main(int argc, char* argv[]){
	if(argc != 3){
		printf("Invalid parameters. Expected 3, got %d\n", argc);
		return -1; 
	}
	

	long a = (long)atoi(argv[1]);
	long b = (long)atoi(argv[2]);
	if(a > b){
		long temp  = a;
		a = b;
		b = temp;
	}
	if(gcf(a,b) != 1){
		printf("Infinity\n");
		return -1;
	}
 	long exp = a;
	long incrament = 0;
	long streak = 0;
	//aMulti and bMulti are the quantities that make 1. 
	long aMulti = a;
	long bMulti = b;
	gcfMulti(&aMulti, &bMulti);
	while(streak < a){
		if(checkFast(a,b,exp-incrament,aMulti,bMulti) == 1){
			incrament++;
			streak++;
			//printf("%d",streak);
		}else{
			incrament = 0;
			streak = 0;
			exp = exp + a/5 + 1;
			//printf("%dD",exp);
		}	
	}
	
	while(checkFast(a,b,exp-incrament,aMulti,bMulti) != 0){
		incrament++;
	}
	
	printf("%ld is the largest order that can't be made\n", exp-incrament);
}

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
//b will be the negative of the two values. 
//find the combination of a and b to get the least common multiple.
//Assume gcf(a,b) is 1. 
void	gcfMulti(long * a, long * b){
	long temp = 0;
	long aMulti = 0;
	long bMulti = 0;
	while(temp != 1){
		if(temp < 1){
			temp += *a;
			aMulti++;
		}else{
			temp -= *b;
			bMulti--;
		}

	}
	*a = aMulti;
	*b = bMulti;
}
//This is not used
int check(long a, long b, long val){
	long aMulti = a;
	long bMulti = b;
	long GCF = gcf(a,b);
	gcfMulti(&aMulti, &bMulti);
	aMulti = (aMulti * val) / GCF;
	bMulti = (bMulti * val) / GCF;
	while(bMulti < 0){
		bMulti += a;
		aMulti -= b;
	}
	if(aMulti < 0){
		return 0;
	}
	return 1;

}
int checkFast(long a,long b, long val, long aMulti, long bMulti){
	aMulti = (aMulti * val);
        bMulti = (bMulti * val);
	//aMulti > 0 bMulti < 0
	bMulti += a*(aMulti/b);
        if(bMulti < 0){
                return 0;
        }
        return 1;
}



















