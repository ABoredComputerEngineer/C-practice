#include <stdio.h>
#include <stdlib.h>
#define MAX 50
typedef struct {
	char *name;
	unsigned int id;
	char grade;
} student;

typedef struct {
	char grade;
	char sec;
	student stdList[5];
	int stdNum;
	char *cr;
} Class;

void getString(char *);

void main(){
	Class c1;
	int i;
	printf("Class Number:: ");
	scanf("%c",&c1.grade);
	getchar();
	printf("\nSection:: ");
	scanf("%c",&c1.sec);
	getchar();

	printf("\nEnter the information about the students\n");
	for ( i = 0 ; i< 5; i++ ){
		printf("\nStudent %d\n",i+1);
		printf("Name: ");
		c1.stdList[i].name = malloc(sizeof(char) * MAX );
		getString(c1.stdList[i].name);
		printf("\nStudent Id: ");
		scanf("%d",&c1.stdList[i].id);
		getchar();
		printf("\nClass: ");
		scanf("%c",&c1.stdList[i].grade);
		getchar();
	}
	c1.stdNum = 5; 
	printf("\nEnter the name of the Class Rep.: ");
	c1.cr = malloc(sizeof(char) * MAX);
	getString(c1.cr);


	for ( i = 0 ; i<5 ; i++ )
		free(c1.stdList[i].name);
	free(c1.cr);
}


void getString(char *x){
	int i = 0, c;
	while ( (c = getchar())!= '\n' )
		x[i++] = c;
	x[i] = '\0';
}


