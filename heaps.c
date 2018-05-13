#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define PQ_LENGTH 1000 // the maximum length of the queue
#define LIMIT 100 // the maximum number of characters for input
#define TABLE_SIZE 100 // the max index of the hash table
#define parent(x) ( ((x) - 1) / 2 ) 
#define lchild(x) ( 2 * (x) + 1 )

typedef struct {
     int *arr;
     int length;
} priorityQueue;

enum command { add = 9, extract = 91, show = 65, fill = 39 , quit = 67, sort = 72 , build = 48};

/* ..... . ARRAY RELATED FUNCTIONS ........
 *   fillArray fills the array with random numbers. it takes in array and its length
 *   displayArray prints the array.it takes in array and its length. */
int *fillArray(int *, int length);
int *displayArray(int *, int length);

/*... QUEUE RELATED FUCNTIONS .... */
void enqueue(priorityQueue*, int); // adds an item in the priority queue
void dequeue(priorityQueue*);

/*.....   HEAP RELATED FUNCTIONS ..... */
void buildMaxHeap(priorityQueue *);
void maxHeapify(priorityQueue *, int);
void heapSort(priorityQueue );
int extractMax(priorityQueue *);
void insertHeap(priorityQueue *, int value);

/* ... DICTIONARY / HASH TABLE RELATED FUNCTIONS .. */
int hash(char *); // takes a string and produces a hash


/*.... MISCALLENEOUS FUNCTIONS .... */
void swap(int *, int *);
int getString(char *);
int readInput(char *, priorityQueue *);
int strToInt(char *);
int isDigit(char);

int main(void){
     priorityQueue q1;
     int i,exit;
     char *command = (char *)malloc(sizeof(char) * LIMIT );
     srand(time(NULL));

     q1.arr = (int *)malloc(sizeof(int)*PQ_LENGTH);
     q1.length = 0;
  
     do {
          getString(command);
          exit = readInput(command, &q1);
     } while ( exit != true );     

     free(q1.arr);
     free(command);
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

void insertHeap(priorityQueue *new, int child){
     if  ( child == 0 )
          return;
     
     if ( new->arr[child] > new->arr[parent(child)] ){
          swap(&new->arr[child],&new->arr[parent(child)]);
          insertHeap(new,parent(child));
     } 

     return;
}

void heapSort(priorityQueue new ){
     buildMaxHeap(&new);
     while ( new.length > 0 )
          extractMax(&new); 
     return;
}

void enqueue(priorityQueue *new, int value){
     new->arr[new->length] = value;
     new->length++;
     insertHeap(new,(new->length-1));
     return;
}

void dequeue(priorityQueue *new){
     extractMax(new);
     return;
}


int getString(char *x){
     unsigned int i = 0;
     unsigned char c;
     while ( ( c = getchar() ) != '\n' && i < LIMIT )
          x[i++] = c;
     x[i] = 0;
     if ( c !=  '\n')
          while( ( c = getchar() != '\n') );      
     return i;
}

int strToInt(char *x){
     int i = 0;
     int multiplier = 1, num = 0, sign = 1, rev = 0;

     // removing preceding blanks
     while ( x[i] == ' ' )
          i++;

     // reading the sign( -ve or +ve ) of the number
     if ( x[i] == '-' ){
          sign = -1;
          i++;
     }

     while ( x[i] == '0' )  // remove preceding zeros 
          i++;

     while ( ( x[i] != 0 ) && isDigit(x[i] ) ){
          num = num * multiplier + ( x[i] - '0' ) ;
          multiplier*=10; 
          i++;
     } 
     
     return sign*num;

}

int readInput(char *x, priorityQueue *new){
     char command[10], value[LIMIT]; 
     int i = 0,j,info;
     
     while ( x[i] == ' ') i++;
     for ( j = 0; x[i] != 0 &&  x[i] != ' ' ; i++ )
          command[j++] = x[i];
     command[j] = 0;
     
     for ( j = 0; x[i] != 0 ; i++ )
          value[j++] = x[i];
     value[j] = 0;

     info = strToInt(value);

     switch ( hash(command) ){
          case add:
               enqueue(new,info);          
               break;
          case extract:
               dequeue(new);
               break;
          case sort:
               heapSort(*new);
               break;
          case fill:
               fillArray(new->arr,new->length);
               break;
          case show:
               displayArray(new->arr,new->length);
               break;
          case build:
               buildMaxHeap(new);
               break;
          case quit:
               return true;
               break;
          default:
               break;
     }

     return false;
}

int hash(char *x){
     int sum = 0, i = 0;
     while ( x[i] != 0 )
          sum += ( x[i++] - 'a' + 1);
     return sum;
}

void swap(int *x, int  *y){
     int temp = *y;
     *y = *x;
     *x = temp;
}
     
int *fillArray(int *x, int length){
     int i;
     for ( i = 0; i < length ; i++ )
          x[i] = rand()%301 ;
     return x;
}     


int *displayArray(int *x, int length){
     int i;
     for ( i = 0; i < length; i++ )
          printf("%d ",x[i]);
     putchar('\n');
     return x;
}

int isDigit( char x ){
     return ( x >= '0' && x <= '9' )?true:false;
}
