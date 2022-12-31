#include<stdio.h>
#include<stdlib.h>
 struct queue
 {
 	 int front ;
 	  int rear ;
 	   int *arr;
 	   int size;
 };
 ///////////////////////maker
  void maker( struct queue *sp, int value )
  { sp->arr=(int*)malloc(value);
  sp->size=value ;
  sp->front=-1;
  sp->rear=-1; }
////////////////////////enque 
 void enqueue( struct queue *sp, int value  )
 { 
 if(sp->front==(sp->rear+1)%sp->size)
 {
 	 printf( "overflow condition \n ");
 	 return;
 }
 if( sp->rear==-1)
 { 
 sp->front=0;
 }
 sp->rear=(sp->rear+1)%(sp->size);
 
 sp->arr[sp->rear]=value;
 return ;
 }
 ////////////////////////dequeue
 void dequeue( struct queue *sp)
 { if( sp->front==-1)
 { 
 printf( "underflow situation \n");
 return;
 }
 if( sp->front==sp->rear)
 { 
 sp->front=-1;
 sp->rear=-1;
 return ;
 }
 	 sp->front=(sp->front+1)%sp->size;
 	 
 	 return;
 }
 ////////////////////////// peeek 
  int peek (struct queue *sp , int index)
  { 
 
  index=(index)%sp->size;
  
  	 return sp->arr[index] ;
  
  }
  
