#include <stdio.h>
#define MAXCOL 10
#define MAXROW 10
void main(){
	int matA[MAXROW][MAXCOL];
	int row,col,i,j;

	printf("Enter the dimensions of the array::::::\n");
	scanf("%d%d",&row,&col);

	printf("\nEnter the data in the matrix::::::\n");
	for ( i = 0; i<row ; i++ ){
		printf("Row %d:: ",i+1);
		for ( j = 0; j<col; j++)
			scanf("%d",&matA[i][j]);
		printf("\n");
	}

	printf("\nThe matrix you entered is:::::: \n");
	for ( i = 0; i<row ; i++){
		for ( j = 0; j<col; j++)
			printf("%5d",matA[i][j]);
		printf("\n");
	}

}	