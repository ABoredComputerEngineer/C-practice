#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define parent(x) ( ( (x) == 0 )?-1:( ((x) - 1) / 2 ) )
#define lchild(x) ( 2 * (x) + 1 )

typedef struct {
     int *arr;
     int length;
} priorityQueue;


int *fillArray(int *, int length);
int *displayArray(int *, int length);

void buildMaxHeap(priorityQueue *);
void maxHeapify(priorityQueue *, int);
void heapSort(priorityQueue *);
int extractMax(priorityQueue *);
int *displayTree(int *, int); // displays an array as a binary tree
void swap(int *, int *);
int loga2(int); // calculates the integer part of log2
int power(int, int);
int main(void){
     priorityQueue q1;
     int i;
     q1.arr = (int *)malloc(sizeof(int)*10);
     q1.length = 10;
     for ( i = 0; i < q1.length ; i++ )
         q1.arr[i] =  i ;
     for(i = 0; i < q1.length; i++ )
         printf("%d ",q1.arr[i] );

     buildMaxHeap(&q1);
     putchar('\n'); 
     for(i = 0; i < q1.length; i++ )
         printf("%d ",q1.arr[i] );
     putchar('\n');

     displayTree(q1.arr, q1.length);
     heapSort(&q1);
     for(i = 0; i < q1.length; i++ )
         printf("%d ",q1.arr[i] );
     putchar('\n');
     q1.length = 10;
     return 0; 
}


void buildMaxHeap(priorityQueue *new){
     int i;
     for ( i = new->length/2; i >= 0 ; i-- )
          maxHeapify(new,i );
     return;
}

void maxHeapify(priorityQueue *new, int parent){
     int swpIndex = parent, i;

     for ( i = 0; i < 2 && (lchild(parent)+i) < new->length ; i++ )
          if ( new->arr[swpIndex] < new->arr[lchild(parent) + i ] )
               swpIndex = lchild(parent) + i;

     if ( swpIndex != parent ){
          swap(&new->arr[parent], &new->arr[swpIndex] );
          maxHeapify(new,swpIndex);
     }
}

int extractMax(priorityQueue *new){
     int rv = new->arr[0];
     swap(&new->arr[0],&new->arr[new->length-1] );
     new->length--;
     maxHeapify(new,0);
     return rv;     

}

void heapSort(priorityQueue *new ){
     
     while ( new->length > 0 )
          printf("%d\t",extractMax(new) );

     
     return;
}

void swap(int *x, int  *y){
     int temp = *y;
     *y = *x;
     *x = temp;
}
     
     
int *displayTree(int *arr, int length){
     int i,j,temp = loga2( length ), k = 0, space,l;
     int height = ( power(2,temp) == length )?temp:(temp+1);

     for ( i = 0; i < length ; ){
          for ( space = height; space >= 0; space--)
               putchar(' ');
          temp = power(2,k);
          for ( j = 0; j < temp  && i < length; j++ ){
               printf("%d ",arr[i++]);
          }
          putchar('\n');

          height--;

          k++;
     }


     return arr;

}

int loga2(int x){
     if ( x == 1 )
          return 0;
     else 
          return 1 + loga2(x/2);

}
     
int power(int base, int exp){
     if ( exp == 0 )
          return 1;
     else
          return base*power(base,exp-1);
}






