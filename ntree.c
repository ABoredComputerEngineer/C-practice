#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define MAX_CHILD 5 // The max number of child nodes a  node will have

int Depth = 2;
int randomValue = 0;
typedef struct node {
	int value; 
	struct node *child[MAX_CHILD];
	struct node *parent;
} node;

int getValue(void){
	return (randomValue+=1);
}

int checkChildren( node *root ){
	int i;
	for ( i = 0; i<MAX_CHILD ; i++ )
		if ( root->child[i] == NULL )
			return i;
	return -1;
}

node *newNode( int value ){
	node *p;
	int i;
	p = malloc( sizeof(node) );
	p->value = value;
	for ( i = 0; i<MAX_CHILD ; i++ )
		p->child[i] = NULL;
	p->parent = NULL;
	return p;
}

void generateTree( node *root , int depth ){
	// static int depth = 0;//,nodeCount = 0;
	// int n = 1,childIndex = 0,d = 0;
	// node *p = root;
	// while ( checkChildren(root) ) {
	// 		p->child[childIndex] = newNode( 3 );
	// 		n++;
	// 		p->child[childIndex]->parent = p;
	// 		p = p->child[childIndex];
	// 		d++;
	// 		if ( d == depth ){
	// 			p = p->parent;
	// 			d--;
	// 			childIndex = (childIndex+1) % 3;
	// 		}
	// 	printf("%d\t",n);
	// }
	int i;
	i = checkChildren(root);
		// printf("%d\t%d\n",i,nodeCount);
	if ( depth < Depth && i!=-1){ // if we have not reached the maximum depth and we can still add a node
		// if ( i == -1 )
		// 	return;
		root->child[i] = newNode(getValue());
		root->child[i]->parent = root;
		// nodeCount++;
		// depth++;
		generateTree(root->child[i],depth+1);
	} else if ( depth == Depth ) {		// if we have reached the maximum depth 
		// depth--;
		generateTree( root -> parent, depth+1 ); // move to the parent
	} else if ( i == - 1 && checkChildren(root->parent) != -1 ){
		// depth--;
		generateTree( root -> parent,depth+1 );
	}


}

void printTree(node *root);

int main(){
	node *root;
	root = newNode( 4 );
	// addNode(root,0,newNode(3));
	// addNode(root,1,newNode(3));
	// addNode(root,2,newNode(3));
	// addNode(root->child[0],0,newNode(3));
	generateTree( root );
	printf("%d\n",checkChildren(root));
	//printf("%d\t%d\t%d\n",checkChildren(root->child[0]), root->child[0]->child[0]->child[0]->value,checkChildren(root));
	printTree(root);	
	// printf("\n%d\t%d\t%d\t%d\n",checkChildren(root),root->child[0]->value,root->child[0]->child[0]->value,root->child[0]->child[1]->value);
	// printf("\n%d\t%d\t%d\t\n",root->child[0]->child[2]->value,root->child[1]->child[2]->value,root->child[2]->child[2]->value);
	// printf("%d\t\n",checkChildren(root));
	// generateTree( root );
	// printf("%d\t%d\n",checkChildren(root),checkChildren(root->child[2]) );
	// printf("%d\n",root->child[2]->value);
	putchar('\n');
	return 0;
}

void printTree( node *root ){
	int i;
	if ( root != NULL ){
		for ( i = 0; i<MAX_CHILD; i++ ){
			
			printTree( root->child[i] );
		}
		// printTree( root->child[1] );
		// printTree( root->child[2] );
		// printTree( root->child[3] );
		// printTree( root->child[4] );
		printf("%d\t",root->value);
		// printf( "%d\t",root->value);
	}
}

