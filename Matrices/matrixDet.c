#include <stdio.h>
#define MAXCOL 10
#define MAXROW 10

void matIn(int [MAXROW][MAXCOL],int,int);
void matOut(int [MAXROW][MAXCOL],int,int);
int matDet(int [MAXROW][MAXCOL],int);
int cofactor(int [MAXROW][MAXCOL], int [MAXROW][MAXCOL],int row,int col, int dimension);
// Co factor of row,col element of 1st matrix and stores in 2nd matrix and return the dimension of the cofactor matrix

void main(){
	int a[MAXROW][MAXCOL] = {{1,2,3},{4,5,6},{7,8,9}};
	int rowA,colA;

	printf("Enter the dimensions of the array:::: \n");
	scanf("%d%d",&rowA,&colA);

	printf("\n Enter the contents of the matrix::: \n");
	matIn(a,rowA,colA);
	printf("\nThe matrix you entered is ::: \n");
	matOut(a,rowA,colA);

	if ( rowA == colA )
		printf("The determinant of your matrix is:::: %d\n",matDet(a,rowA));
	else 
		printf("Dimension Mismatch\n");

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



int matDet(int a[MAXROW][MAXCOL],int dimension){
	int cofactorDim;
	int x[MAXROW][MAXCOL];
	int det = 0,i;
	if ( dimension == 1)
		return a[0][0];
	for ( i = 0; i<dimension; i++){
		cofactorDim = cofactor(a,x,0,i,dimension);
		det += ((i%2)?-1:1)*a[0][i] * matDet(x,cofactorDim);
	}
	return det;
}

int cofactor(int matRead[MAXROW][MAXCOL],int matWrite[MAXROW][MAXCOL],int row,int col, int dimension ){
	int i,j,k=0;
	int temp[50];
	for ( i = 0; i< dimension ; i++){
		if ( i == row )
			continue;  // Discards the entire row if the row is one in which the element whose cofactor matrix is needed to be found
		for ( j  = 0; j<dimension; j++){
			if ( j != col ){
				temp[k++] = matRead[i][j];
			}
		}
	}
	for( i = 0,k=0 ; i < dimension - 1 ; i++ ){
		for ( j = 0 ; j<dimension-1; j++)
			matWrite[i][j] = temp[k++];
	}

	return dimension-1;

}



