
#include <stdio.h>
#define HEADING_TEXT "::::   A TABLE OF POWERS   ::::"
unsigned long int power(float,int);
void main(){
	unsigned long int i,j,k;
	printf(HEADING_TEXT "\n");
	printf("%9s%13s%13s%13s%13s\n","Integer","Square","3rd power","4th power","5th power");
	printf("%s%4c%s%4c%s%4c%s%4c%s\n","---------",' ',"---------",' ',"---------",' ',"---------",' ',"---------");
	for( i = 1; i<=5;i++){
		for ( j = 1;j<=5;j++){
			// printf("%7d\t%6d\t%9d\t%9d\t%9d\n",power(i,j));
			printf("%*d",(j==1)?9:13,power(i,j));
		}
		printf("\n");
	}
}

unsigned long int power(float x,int y){
	unsigned long int i=1;
	for (;y>=1;y--)
		i *= x;
	return i;
}