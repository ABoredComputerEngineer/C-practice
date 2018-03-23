// Program to match a pattern in a string
#include <stdio.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
void getString(char *x);
int matchPattern(char *, char *);
void main(){
	char pattern[] = "abc";
	char str[100];
	printf("Enter a string \n");
	getString(str);
	if( matchPattern(str,pattern))
		printf("Found the pattern\n");
}

void getString(char *x){
	int i = 0;
	char c;
	while ( (c=getchar()) != '\n' )
		x[i++] = c;
	x[i] = 0;
}

int matchPattern(char *str,char *pattern){
	int i,j,k;
	int slen = strlen(str);
	int plen = strlen(pattern);
	for ( i = 0; i<=(slen-plen) ; i++ ){
		for ( j = i,k=0; str[j] == pattern[k] && pattern[k]!='\0'; j++, k++);
		printf("%c\t%c\n",str[i],pattern[k]);
		if ( pattern[k] == '\0' )
			return TRUE;
	}
	return FALSE;
}
