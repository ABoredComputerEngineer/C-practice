/*
	EXPLANATION:::::
		This program creates a dynamic array of words using the maloc function.
		**words is an 'array' of pointers with each of the pointer pointing to a 'word'.
		The storage for each 'word' is dynamically allocated (and so is the array 'words')
		The program auto exits if it fails to allocate required memory.


*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 100 // The maximum length of the word that the user can enter

int getString(char *);

int main(){
	char **words,word[MAXLEN]; // Described above
	int x,i,wordLength; 
	printf("How many words do you want to enter...\n");
	scanf("%d\n",&x);
	if ( (words = malloc( sizeof(*words) * x )) == NULL ){ // Allocates the memeory required for 'x' numbers of pointers to char
		printf("Not enough space for array. Bye!!! \n");
		return -1;
	}
	for ( i = 0; i<x; i++){
		wordLength = getString(word);
		if ( (*(words+i) = (char *)malloc( sizeof( char ) * (wordLength+1) ) ) == NULL ){ // Allocates the memory required to stored a word entered by the user
			printf("Can't allocate space.Bye!!! \n");
			return -1;
		}

		strcpy(*(words+i),word); // Copies the word entered by the user into the space allocated	
	}
	printf("\n");	
	for ( i = 0; i<x; i++ ){
		printf("%s\n",*(words+i));
	}
	free(words);
	return 0;
}

int getString(char *x){
	int i = 0;
	while ( (i<MAXLEN - 1) && ( x[i] = getchar() ) != '\n' )
		i++;
	x[i] = '\0';
	return i;
}