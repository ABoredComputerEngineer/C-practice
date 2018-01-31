#include <stdio.h>
#define MAXLENGTH 1000

int getString(char *);
void escape(char *, char *);
void unescape(char *, char*);

void main(){
	char str[MAXLENGTH],esc[MAXLENGTH],unesc[MAXLENGTH];
	char cpystr[100];
	int length;
	length = getString(str);

	escape(str,esc);
	printf("\nThe escape characters in literal form are::\n%s",esc);
	unescape(str,unesc);
	printf("\nThe literal escape characters in escaped form are: \n%s\n",unesc);

}


int getString(char *x ){
	int i = 0,c;
	while ( (c=getchar()) != EOF && (i<MAXLENGTH - 1) )
		*(x+(i++)) = c;
	*(x+(i++)) = '\0';
	return i;
}

void escape(char in[],char out[]){
	int i=0,j=0;

	while ( in[i] != '\0' ){
		switch (in[i]){
			case '\n':
				out[j++] = '\\';
				out[j++] = 'n';
				break;
			case '\b':
				out[j++] = '\\';
				out[j++] = 'b';
				break;
			case '\t':
				out[j++] = '\\';
				out[j++] = 't';
				break;
			case '\v':
				out[j++] = '\\';
				out[j++] = 'v';
				break;
			case '\r':
				out[j++] = '\\';
				out[j++] = 'r';
				break;
			case '\0':
				out[j++] = '\\';
				out[j++] = '0';
				break;
			default:
				out[j++] = in[i];
				break;		
		}
		i++;
	}
}

void unescape(char in[],char out[]){
	int i= 0, j=0;
	while ( in[i] != '\0') {
		if ( in[i] == '\\'){
			switch (in[++i]){
				case 'n':
					out[j++] = '\n';
					break;
				case 't':
					out[j++] = '\t';
					break;
				case 'v':
					out[j++] = '\v';
					break;
				case 'r':
					out[j++] = '\r';
					break;
				case '0':
					out[j++] = '0';
					break;
				default : 
					out[j++] = in[i];
					break;
			}
		} else 
			out[j++] = in[i];
		i++;

	}
}



