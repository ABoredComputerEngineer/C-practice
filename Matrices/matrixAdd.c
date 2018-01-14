#include <stdio.h>
#define MAXCOL 10
#define MAXROW 10

void matIn(int [MAXROW][MAXCOL],int,int);
void matOut(int [MAXROW][MAXCOL],int,int);

void main(){
	int matA[MAXROW][MAXCOL], matB[MAXROW][MAXCOL],matC[MAXROW][MAXCOL], i,j;
	int rowA,colA,rowB,colB;

	printf("Enter the dimension of matrix A \n"); 
	scanf("%d%d",&rowA,&colA);
	printf("\nEnter the dimension of matrix B \n");
	scanf("%d%d",&rowB,&colB);
	printf("\n");

	printf("Enter the data for matrix A::\n");
	matIn(matA,rowA,colA);
	printf("\nEnter the data for matrix B:: \n");
	matIn(matB,rowB,colB);

	printf("\nThe matrix A is :::: \n");
	matOut(matA,rowA,colA);
	printf("\nThe matrix B is ::: \n");
	matOut(matB,rowB,colB);

	if ( rowA == rowB && colB == colA){
		for( i = 0; i<rowA; i++)
			for( j = 0; j<colA; j++)
				matC[i][j] = matA[i][j] + matB[i][j];
		printf("The sum of your matrices is \n");
		matOut(matC,rowA,colA);
	} else {
		printf("Dimension mismatch");
	}

}

void matIn(int a[MAXROW][MAXCOL], int row,int col){
	int i,j;
	for ( i = 0; i<row; i++){
		printf("\nRow %d:\t",i+1);
		for ( j = 0; j<col; j++)
			scanf("%d",&a[i][j]);
	}
		
}

void matOut(int a[MAXROW][MAXCOL],int row, int col){
	int i,j;
	for ( i = 0; i<row; i++){
		for ( j  = 0 ; j<col; j++)
			printf("%d\t",a[i][j]);
		printf("\n");
	}
}