#include <stdio.h>
int greatestCommonDivisor(int,int);
void main(){
	int hcf  = greatestCommonDivisor(6,8);
	printf("The gcd of 6 and 8 is %d\n",hcf);
}

int greatestCommonDivisor(int m,int n){
	if ( n == 0 )
		return m;
	else 
		return greatestCommonDivisor(n,m%n);
}