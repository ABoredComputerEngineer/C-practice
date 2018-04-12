#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node {
	int value;
    	struct node *left;
	struct node *right;
} node;


// Function definitions
node *newNode(int data);
node *insertNode(node *head, int data);
node *fillTree(node *head);
void breadthOrder(node *head);
void inOrder(node *);

int main(){
     node *head;
     srand(time(NULL));
     head = fillTree(NULL);    
     printf("\nThe in order traversal is ::: \n"); 
     inOrder(head);
     printf("\nThe breadth order traversal  is ::: \n");
     breadthOrder(head);
     putchar('\n');
     return 0;
}

node *newNode(int data){
     node *new = malloc(sizeof(node));
     new->value = data;
     new->left = NULL;
     new->right = NULL;
     return new;
}

node *insertNode(node *head, int data){
     if ( head == NULL )
          head = newNode(data);
     else if ( data < head->value ){
          if ( head->left == NULL)
               head->left = newNode(data);
          else
               insertNode(head->left,data);
     } else { 
          if ( head->right == NULL )
               head->right = newNode(data);
          else 
               insertNode(head->right,data);
     }
     return head;
}

node *fillTree(node *head){
     int i,value = 0;;
     for ( i = 0; i<8; i++ ){
          value = rand()%40;
          printf("%d\t",value);
          head = insertNode(head,value);
     }
     return head;
}

void inOrder(node *head){
     if ( head == NULL )
          return;
     else {
          inOrder(head->left);
          printf("%d\t",head->value);
          inOrder(head->right);
     }
}

void breadthOrder(node *head){
     node *queue[1000];
     int seek = 0,deque = 0;
     while ( head != NULL ) {
          printf("%d\t",head->value);
          if ( head->left != NULL )
               queue[seek++] = head->left;
          if ( head->right != NULL )
               queue[seek++] = head->right;
          if ( deque != seek)
               head = queue[deque++];
          else
               head = NULL;
    }
}
          
