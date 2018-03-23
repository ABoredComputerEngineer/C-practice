#include <stdio.h>
#include <ctype.h>
void getString(char* );
long int strInt(char *);
double strFloat(char *);
void main(){
	char str[100];
	long int x;
	float y;
	printf("Enter a number\n");
	getString(str);
	y = strFloat(str);
	printf("The number is %lf\n",y);
}

long int strInt(char *str){
	long int num=0;
	int i=0,sign=1;
	if ( str[0] == '-' ){
		sign = -1;
		i++;
	}else if ( str[0] == '+'){
		i++;
	}
	for ( ; str[i]!=0; i++){
		num*=10;	
		num += (str[i] - '0' );
	}
	num *= sign;
	return num;
}

void getString(char *x){
	int i = 0;
	char c;
	while ( (c = getchar()) != '\n' )
		x[i++] = c;
	x[i] = '\0';
}

double strFloat(char *str){
	double num = 0,precision=1.0;
	int sign,i = 0;
	for ( i = 0; str[i]==' '; i++);
	sign = (str[i]=='-')?-1:1;
	printf("%d\n",i);
	if ( str[i] == '-' || str[i] == '+' )
		i++;
	for(; isdigit(str[i]); i++){
		num *= 10.0;
		num += (str[i] - '0');
	}
	if ( str[i] == '.')
		i++;
	for ( ; isdigit(str[i]); i++ ){
		num*=10.0;
		num+=(str[i]-'0');
		precision *= 10.0;
	}
	return sign*num/precision;	
}
