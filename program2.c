#include <stdio.h>
int greatestCommonDivisor(int,int);
void main(){
	int hcf  = greatestCommonDivisor(0,6);
	printf("The gcd of 0 and 6 is %d\n",hcf);
}

int greatestCommonDivisor(int m,int n){
	if ( n == 0 )
		return m;
	else 
		return greatestCommonDivisor(n,m%n);
}