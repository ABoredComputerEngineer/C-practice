#include <stdio.h>
#define MAXCOL 10
#define MAXROW 10
typedef int matrix[MAXROW][MAXCOL];

void matIn(matrix,int ,int);
void matOut(matrix,int ,int);


void matIn( matrix a,int row,int col){
	int i,j;
	//printf("\nEnter the data in the matrix::::::\n");
	for ( i = 0; i<row ; i++ ){
		printf("Row %d:: ",i+1);
		for ( j = 0; j<col; j++)
			scanf("%d",&a[i][j]);
		printf("\n");
	}
}

void matOut( matrix a,int row, int col){
	int i,j;
	for ( i = 0; i<row ; i++){
		for ( j = 0; j<col; j++)
			printf("%5d",a[i][j]);
		printf("\n");
	}	
}
