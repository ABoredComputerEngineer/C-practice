// PROTIP: IF YOU DONT UNDERSTAND IT DO SOME HAND CALCULATIONS FIRST
// THE ONLY PART YOU NEED IS THE TRIPLE FOR LOOP AFTER PRINTING THE TWO MATRICES

#include <stdio.h>
#define MAXCOL 10
#define MAXROW 10

void matIn(int [MAXROW][MAXCOL],int,int);
void matOut(int [MAXROW][MAXCOL],int,int);

void main(){
	// INITIALIZES ALL THE MATRICES TO HAVE THE VALUE ZERO FOR ALL ITS ELEMENTS. VERY IMPORTANT AS WE DON'T HAVE TO USE A LOOP TO INITIALIZE THEIR VALUE
	int matA[MAXROW][MAXCOL]={}, matB[MAXROW][MAXCOL] = {},matC[MAXROW][MAXCOL]={};
	
	int i,j,k; //  COUNTERS FOR THE LOOPS
	int rowA,colA,rowB,colB,rowC,colC; // SELF EXPLANATORY

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


	// THE MULTIPLICATION BEGINS HERE
	if ( rowA == colB && colA == rowB){
		rowC = colC = rowA;
		for( i = 0; i<rowC; i++)
			for( j = 0; j<colC; j++)
				for( k = 0; k<rowB; k++)     	//The first 'new' part
					matC[i][j] += matA[i][k] * matB[k][j]; // the second 'new' part and the one you need to memorize
		printf("The product of your matrices is \n");
		matOut(matC,rowC,colC);
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