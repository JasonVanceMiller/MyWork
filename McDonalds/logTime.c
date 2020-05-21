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
#include<stdlib.h>
#include<stdio.h>
long	gcf(long a, long b);
//pass by value;
void	gcfMulti(long * a, long * b);
int check(long a, long b, long val);
int checkFast(long a, long b, long val, long aMulti, long bMulti);
int main(){
	//a should be less than b
	long a = 101009;
	long b = 103967;

 	long exp = a;
	long incrament = 0;
	long streak = 0;
	long aMulti = a;
	long bMulti = b;
	gcfMulti(&aMulti, &bMulti);
	long GCF = gcf(a,b);
	//finds a streak of a-1 length;
	if(GCF != 1){
		printf("%d != 1 for gcf\n",GCF);
		return 1;
	}
	while(streak < a-1){
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
	printf("%d\n",exp-incrament);
}
long gcf(long a, long b){
	if(a < b){
		long temp = a;
		a = b;
		b = temp;	
	}		
	while(a >= b){
		a = a - b;
	}	
	if(a == 0){
		return b;
	}else{
		return gcf(b,a);
	}
}
//b is strictly negative
//find the combination of a and b to get the least common multiple. 
void	gcfMulti(long * a, long * b){
	long GCF = gcf(*a, *b);
	long temp = 0;
	long aMulti = 0;
	long bMulti = 0;
	while(temp != GCF){
		if(temp < GCF){
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










`








