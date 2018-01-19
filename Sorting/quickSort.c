// CHANGE THE RANGE OF THE NUMBERS IN THE ARRAY BY CHANGING THE VALUE OF RANGE
// CHANGE THE LENGTH OF THE ARRAY BY CHANGING THE VALUE OF LENGTH

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LENGTH 8
#define TRUE 1
#define FALSE 0
#define RANGE 100

void printArray(int *,int);
void swap(int *, int *); 
void fillArray(int *);  //fills the array of LENGTH with random number which are then sorted
int split(int *, int, int);
void quickSort(int *, int, int);
int checkSort(int *,int); // returns TRUE if the array is sorted FALSE if it is not


void main(){
	int x[LENGTH],left=0,right=LENGTH-1,l,t;
	int i,j;
	srand(time(NULL));		//Required to generate random numbers

	fillArray(x);

	printf("The initial array is \n");
	printArray(x,LENGTH);
	printf("---------------------SORTING BEGINS HERE-----------------------\n");
	quickSort(x,0,LENGTH-1);
	
	printf("\nThe sorted Array is \n");
	printArray(x,LENGTH);

	

}

void quickSort(int x[],int left, int right ){
	int i ;
	if ( right - left < 1 || checkSort(x,LENGTH) )
		return ;

	i = split(x,left,right);
	quickSort(x,left,i-1);		// sorts the elements to the left of the splitter
	quickSort(x,i+1,right);		//sorts the elemets to the right of the splitter
}


int split(int x[],int left, int right){
	static int count = 1; // counts the number of times the array is splitted
	printf("\n\nCall %d of the sort \n",count);
	int i,j,t,l;
	i = left; // The index where the splitter resides in the sorted array
	l = rand()%(right-left)+left;	//Gets a random number ( the index for splitter ) between left and right
	t = x[l];
	swap(&x[l],&x[right]); // The splitting element is now in the rightmost part of the array
	printf("\tThe splitter is %d\n",t);
	for ( j = left; j < right ; j++ ){  // We only check from the leftmost element to the (right-1) element since the rightmost element holds the splitter element
		if ( x[j] < t ){
			printArray(x,LENGTH);
			swap(&x[j],&x[i++]);
		}
	}
	swap(&x[right],&x[i]); // Swaps the splitter from the rightmost position to it's real position in the sorted array
	printArray(x,LENGTH);
	count++;
	return i;  // Returns the index of the splitter element
}



void swap(int *a, int *b ){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void printArray(int *ip, int length){
	int i;
	for ( i = 0; i<length; i++ )
		printf("%d\t",*(ip+i));
	printf("\n");
}

void fillArray(int *x){
	for ( int i = 0; i<LENGTH; i++ )
		*(x+i) = rand()%RANGE;
}

int checkSort(int x[],int length){
	int i = 0;
	for ( i = 0; i<length-1;i++){
		if (x[i]>x[i+1])
			return FALSE; 
	}
	return TRUE;
}