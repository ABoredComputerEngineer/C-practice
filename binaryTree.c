#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

typedef struct node {
	int value;
	struct node *left;
	struct node *right;
} node ;

void printLine(void){
	int i;
	putchar('\n');
	for ( i = 0; i<100 ; i++)
		putchar('-');
	putchar('\n');
}
int getRand( void ){
	int x,y;
	x = rand(); y = rand();
	if ( x == y )
		return getRand();
	else 
		return x;
}
node *newNode( int value ){
	node *p;
	p = malloc(sizeof(node));
	p->value = value;
	p->left = NULL;
	p->right = NULL;
	return p;
}

node *addNode( node *root, node *new ){
	if ( new->value < root->value ){
		if ( root->left == NULL )
			return ( root->left = new );
		else 
			return addNode( root->left, new);
	} else {
		if ( root->right == NULL )
			return ( root->right = new );
		else 
			return addNode( root->right, new );
	}
}

int search( node *root, int value );
node *findMin( node *root );
node *findMax( node *root );
void preOrderTree( node *root );
void postOrderTree( node *root );
void inOrderTree( node *root );
int findDepth( node *root, int value);
void printLeafNode( node *root );
int leafList( node *root, node *leafNodeList[], int leafNumber);

int main(){
	node *root,*leafNodeList[10];
	int i,temp ,searchValue,treeValues[11],leafNumber = 0;
	root = newNode( 50 );
	treeValues[0] = 50;
	srand(time(NULL));
	for ( i = 1; i<11; i++ ){
		temp = getRand() % 100;
		treeValues[i] = temp;
		addNode( root, newNode( temp ));
		printf("%d\n",temp);
	}
	printLine();
	printf( "\nEnter a value to search \n");
	scanf( "%d" , &searchValue );
	if ( search(root, searchValue) )
		printf("Match Found");
	else 
		printf("Match Not found");
	printLine();
	printf("Max:%d\tMin:%d",findMax(root)->value,findMin(root)->value);
	printLine();
	printf("Pre Order Tree is \n");
	// printLine();
	preOrderTree( root );
	printLine();
	printf("In order tree is\n");
	inOrderTree( root );
	printLine();
	printf("Post Order tree is \n");
	postOrderTree(root);
	printLine();
	printf( "\n" );
	for ( i = 0; i<11; i++)
		printf("The depth of %d is %d\n",treeValues[i], findDepth(root,treeValues[i]));
	printLine( );
	printf("The leaf nodes are ::::\n");
	printLeafNode(root);
	printLine();
	leafNumber = leafList( root, leafNodeList , leafNumber );
	printf("%d\n\n",leafNumber);
	return 0;
}

int search( node *root, int value ){
	if ( root == NULL )
		return FALSE;
	else if ( value == root->value )
		return TRUE;
	else if ( value < root->value )
		return search( root->left , value );
	else 
		return search( root->right, value );
}

node *findMin( node *root ){
	if  ( root->left == NULL )
		return root;
	else 
		return findMin( root->left );
}

node *findMax( node *root ){
	if ( root->right == NULL )
		return root;
	else 
		return findMax( root->right );
}

void postOrderTree( node *root ){
	if ( root != NULL ){
		postOrderTree( root->left );
		preOrderTree( root->right );
		printf( "%d\t",root->value );
	}
}

void preOrderTree( node *root ){
	if ( root != NULL ){
		printf( "%d\t",root->value );
		preOrderTree( root->left );
		preOrderTree( root->right );
	}
}

void inOrderTree( node *root ){
	if ( root != NULL ){
		inOrderTree( root->left );
		printf( "%d\t",root->value );
		inOrderTree( root->right );
	}
}


int findDepth( node *root, int value ){
	if ( root->value == value )
		return 0;
	else if ( value < root->value )
		return findDepth( root->left, value) + 1;
	else 
		return findDepth( root->right, value) + 1;
}

void printLeafNode( node *root  ){
	if ( root->left == NULL && root->right == NULL )
		printf("%d\t",root->value);
	else{
		if ( root->left != NULL )
			printLeafNode( root->left ); 
		if ( root->right != NULL )
			printLeafNode( root->right );
	}
}

int leafList( node *root, node *leafNodeList[], int leafNumber){
	if ( root->left == NULL && root->right == NULL ){
		leafNodeList[leafNumber++] = root;
		return leafNumber;
	}
	else {
		if ( root->left != NULL )
			leafNumber = leafList( root->left, leafNodeList , leafNumber );
		if ( root->right != NULL )
			leafNumber = leafList( root->right, leafNodeList, leafNumber );
	}
	return leafNumber;
}