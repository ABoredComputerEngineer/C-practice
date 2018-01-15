#include <stdio.h>
#define LENGTH 10
#define AM(a,b) ( ( (a)+(b) )/2 )

void bubbleSort(int *);
int binarySearch(int *,int,int,int);
void swap(int *,int *);

void main(){
	int b[10],i,searchValue;
	int *a = b;

	printf("Enter ten numbers... \n");
	for ( i = 0; i<10; i++)
		scanf("%d",a+i);
	bubbleSort(b);
	for ( i = 0 ; i<10 ; i++)
		printf("%d\t",*(b+i));

	printf("\nEnter a value to be searched....\n");
	scanf("%d",&searchValue);

	if ( (i = binarySearch(b,searchValue,0,LENGTH-1)) == -1)
		printf("\nThe value was not found\n");
	else 
		printf("\n The value you searched for is in the index %d\n",i);



}


void bubbleSort(int a[]){
	int i,j,temp;
	
	for ( i=0; i<LENGTH-1;i++){
		for ( j = 0; j<LENGTH-1-i; j++){
			if ( a[j]>a[j+1]){
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
				}
		}
	}
}

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int binarySearch(int x[LENGTH],int searchValue,int left, int right){
	int index;
	if ( right - left < 0 )
		return -1;
	index = AM(left,right);
	if ( searchValue < x[index] )
		return binarySearch(x,searchValue,left,index-1);
	else if ( searchValue > x[index] )
		return binarySearch(x,searchValue,index+1,right);
	else if ( searchValue == x[index])
		return index;
}


