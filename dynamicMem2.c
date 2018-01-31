#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 20
#define MAXVAL  300

float getRandom(void);
float average(float *, int );
void quickSort(float *, int, int);
int split(float *, int, int);
void swap(float *,float *);

void main(){
	float *a;
	int x,length,i;
	// float average,max,min;

	srand(time(NULL));
	length = rand() % (MAX+1);
	a = malloc(sizeof(float) * length);

	for ( i = 0; i<length; i++ )
		a[i] = getRandom();
	quickSort(a,0,length-1);

	printf("\n*************ARRAY ANALYSIS******************\n");
	printf("The sorted array is... \n");
	for ( i = 0; i<length; i++ )
		printf("%.2f\t",a[i]);
	printf("\n");
	printf("The average of the numbers in the array is.. %.2f\n",average(a,length));
	free(a);

}


int split( float *x, int left, int right){
	int L, i,j = left;
	float T;
	L = rand() % (right-left) + left;
	T = x[L];
	swap(&x[right],&x[L]); // splitter is now the rightmost element
	for ( i = left; i<right; i++ ){
		if ( x[i] < T ){
			swap(&x[i],&x[j++]);
		}
	}
	swap(&x[right],&x[j]);
	return j;
}

void quickSort(float *x, int left, int right ){
	int i;
	if ( right - left > 0 ){
		i = split(x,left,right);
		quickSort(x,left,i-1);
		quickSort(x,i+1,right);
	}
}

float average(float *x, int length ){
	float avg=0;
	int i;
	for ( i = 1; i<length+1 ; i++ )
		avg += (x[i-1] - avg )/i;
	return avg;
}

void swap(float *x,float *y){
	float temp  = *x;
	*x = *y;
	*y = temp;
}

float getRandom( void ){
	return (rand() % MAXVAL) * 91.0 / 53 ;
}