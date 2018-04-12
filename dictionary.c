#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXENTRIES 10*10*10*10*10*2
#define TRUE 1
#define FALSE 0

typedef struct dictionary {
	int hasValue;
	char key[50];
	char value[100];
	struct dictionary *next;
} dictionary;

dictionary phonebook[MAXENTRIES];
void addEntry(dictionary *,char*,char *);
void addCollision(dictionary *current,char *x,char *y){
	if ( current->next == NULL ){
		dictionary *new = malloc(sizeof(dictionary));
		addEntry(new,x,y);
		current->next = new;
	} else 
		addCollision(current->next,x,y);
}

unsigned long int hash(char *word){
//	int sum = 0; int i;
// 	for ( i = 0;x[i]!=0 ;i++ )
//		sum += x[i];
//	sum += i;
//	return sum;
	long int hashAddress = 5381;
	int counter;
for (counter = 0; word[counter]!='\0'; counter++){
    hashAddress = ((hashAddress << 5) + hashAddress) + word[counter];
}
	return hashAddress%102329;
}
int main(){
	char key[100],value[100];
	long int entries,i;
	unsigned long int hashVal;
	int found ;
	unsigned long long collision = 0;
	dictionary *current;
	scanf("%ld",&entries);
	for ( i = 0; i<entries ; i++ ){
		scanf("%s%s",key,value);
		hashVal = hash(key);
		if ( phonebook[hashVal].hasValue == FALSE )
			addEntry(&phonebook[hashVal],key,value);
		else{
			addCollision(&phonebook[hashVal],key,value);
			collision++;
		}
	}
 	while ( scanf("%s",key) == 1 ) {
		hashVal = hash(key);
		found = FALSE;
		if ( phonebook[hashVal].hasValue == TRUE ) {
			current = &phonebook[hashVal];
			while ( current != NULL ){
				if ( strcmp(current->key,key) == 0 ){
					printf("%s=%s\n",current->key,current->value);
					found = TRUE;			
				}
				current = current->next;
			}	
	 	} 
		if ( found  == FALSE ){
			printf("Not found\n");
		}
	}
	printf("No of collisions::: %Lu\n",collision);
    return 0;
}


void addEntry(dictionary *new, char *s1, char *s2){
	strcpy(new->key,s1);
    strcpy(new->value,s2);
	new->hasValue = TRUE;
}


