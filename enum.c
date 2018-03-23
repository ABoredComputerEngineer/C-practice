#include <stdio.h>
#define SUBJECT_COUNT  3

enum subjects {physics,C,math} subject;

struct student {
	char name[100];
	int roll;
	char address[100];
	int age;
	float marks[SUBJECT_COUNT];
};

float average(float *); // Calculate the average of given array

int main(){
	struct student records[3];
	int i,j;
	subject = physics;
	printf("Enter the student Records\n");
	for ( i = 0; i<3; i++){
		printf("Enter name : ");
		scanf("%s",records[i].name);
		printf("Enter roll : ");
		scanf("%d",&records[i].roll);
		printf("Enter Address ");
		scanf("%s",records[i].address);
		printf("Enter Age : ");
		scanf("%d",&records[i].age);
		printf("Enter the marks in physics, C and math\n");
		for ( j = 0; j<SUBJECT_COUNT; j++) {
			scanf("%f",&records[i].marks[j]);
		}
	}
	
	for ( i =0; i<3; i++ ){
		printf("Name: %s\n",records[i].name );
		printf("Address: %s\n", records[i].address );
		printf("Roll: %d\n",records[i].roll);
		printf("Age: %d\n",records[i].age);
		for ( j = 0; j < 3; j++ ){
			printf("Marks in %s : %.2f\n", ( j==0)?"Physics":((j==1)?"C":"Math"), records[i].marks[j] );
		}
		printf("%.2f\n",average(records[i].marks));
	}

	return 0;
}

float average( float *x ){
	int i;
	float sum=0;
	for ( i = 0; i<SUBJECT_COUNT; i++){
		sum+=x[i];
	}
	return sum/SUBJECT_COUNT;
}
