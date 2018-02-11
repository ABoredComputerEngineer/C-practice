
// Linked list implementation using recursion

#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

typedef struct node {
    int value ;
    struct node *next;
} node;



node *newNode( int value){
    node *p;
    p = malloc(sizeof(node));
    p->value = value;
    p->next = NULL;
    return p;
}

node *addHead( node *head, node *new ){
    new->next = head;
    return new;
}

node *addTail( node *head , node *new ){
    if ( head->next == NULL ){
        head->next = new;
        return head;
    }
    else
        return addTail(head->next,new);

}

node *previousNode( node *head, int x ){
    // if ( head->value == x )
    //     return head;
    if ( head->next == NULL )
        return NULL;
    if ( (head->next)->value == x )
        return head;
    else 
        return previousNode(head->next,x);
}


node *search( node *last, int value ){
    if ( last-> value == value )
        return last;
    else if ( last->next == NULL )
        return NULL;
    else 
        return search(last->next,value);
}   

void printList(node *head){
    if ( head == NULL )
        return;
    else {
        printf("%d\t",head->value);
        printList(head->next);
    }
}

node  *deleteNode(node *head, int x){
    node *p, *q,*next;
    q = search(head, x);
    if (q != NULL) { // As long as the node exists
        next = q->next;
        p = previousNode(head, x);
        if ( p == NULL ){
            printf("\nRunning\n");
            return next; // if q is the head node
        } else {
            p->next = next;
            return head;
        }
        free( q ); 
    } 
    
        printf("\nNode not Found ... Aborting\n");
        return head;
    
}

int main(){
    node *head;
    // node *p;
    int i;
    head = newNode(0);
    for ( i = 1; i<5; i++ ){
        addTail(head,newNode(i));
        // p = p->next;
    }
    head = addHead(head,newNode(278));
        printList(head);
        putchar('\n');

    if ( previousNode(head,4) == NULL )
        printf("Fuck you!!! \n");
    else 
        printf("No fuck you!!\n");

    head =  deleteNode(head,4);
    // putchar('a');
    printList(head);
    putchar('\n');
    
}