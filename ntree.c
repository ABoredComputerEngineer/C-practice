#include <stdio.h>
#include <stdlib.h>
#define MAX_NODES 3
#define TRUE 1
#define FALSE 0

int NODE_NUMBER = 3;
typedef struct node {
	int value;
	struct node *parent;
	struct node *child[MAX_NODES];
} node;

node *newNode( int value ){
	node *p;
	int i ;
	p = malloc( sizeof( node ) );
	p->value = value;
	for ( i = 0 ; i<NODE_NUMBER ; i++ )
		p->child[i] = NULL;
	p->parent = NULL;
	return p;
}

int checkChildList( node *head ){
	int i;
	for ( i = 0; i<NODE_NUMBER; i++ )
		if ( head->child[i] == NULL )
			return i;
	return -1;
}

node *addNode ( node *head, node *new ){
	static int pos=0;
	int freeNode  = checkChildList( head );
	if ( freeNode == -1 ){
		return addNode( head->child[(pos++) % MAX_NODES], new);
	} else {
		new->parent = head;
		return ( head->child[freeNode] = new );
	}
}

int main(){
	node *root;
	root = newNode( 0 );
	addNode( root, newNode(3));
	addNode( root, newNode(4));
	addNode( root, newNode(5));
		addNode( root, newNode(5));
		addNode( root, newNode(5));
		addNode( root, newNode(5));
		addNode( root, newNode(5));
		addNode( root, newNode(5));
		addNode( root, newNode(5));
		addNode( root, newNode(5));
		addNode( root, newNode(5));
		addNode( root, newNode(5));
	printf("\n%d\t%d\t%d\t%d\n",root->value,root->child[0]->value,root->child[1]->value,root->child[2]->value);
	printf("\n%d\t%d\t%d\n",root->child[0]->child[0]->value,root->child[0]->child[1]->value, root->child[0]->child[2]->value);
	return 0;
}