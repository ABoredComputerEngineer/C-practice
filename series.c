#include <stdio.h>
double sine(float);
double cosine(float);
double exponential(float);
double absolute(double);
double pi(int); // int is the number of terms upto which the series is to be evaluated
void main(){
	float deg,rad,x;
	printf("Enter angle in degrees and the value of x ");
	scanf("%f%f",&deg,&x);
	rad = deg*3.1415/180;
	printf("The sine is %4.3lf and the cosine is %4.3lf\n",sine(rad),cosine(rad));
	printf("The exponential of x = %3.2f is %4.6lf\n",x,exponential(x));
	printf("The value of pi upto 25 terms is %3.6lf\n",pi(25));
}

double sine(float x){
	double term = x,sum = 0;
	int i = 2;
	while ( absolute(term) >  0.00001 ){
		sum += term;
		term *= (-x*x/(i*(i+1)));	
		i += 2;
	}
	return sum;
}

double cosine(float x){
	double term = 1, sum = 0;
	int i = 1;
	while ( absolute(term) > 0.00001 ){
		sum+=term;
		term*=(-x*x/(i*(i+1)));
		i+=2;
	}
	return sum;
}

double absolute(double x){
	if ( x < 0.0 )
		return -x;
	else 
		return x;
}

double exponential(float x){
	double term = 1,sum = 0;
	int i = 0;
	while ( absolute(term) > 0.0001 ){
		sum+=term;
		term*=x/(i+1);
		i++;
	}
	return sum;
}

double pi(int n){
	int i = 0;
	double sum=0,term = 1;
	while ( i <= n ) {
		sum += term;
		i++;
		term = (double)((i%2)?-1:1) / ( 2*i+1);
	}
	return sum*4.0;
}
	
