#include <stdio.h>
#include <stdlib.h>
#define QUEUE_LIMIT 10

//Queue ADT
typedef struct queue
{
	int front;
	int rear;
	int size;
	int *arr;
}queue;

//allocate memory for queue and its array follow the queue's size that user input
queue* crequeue(int size)
{
	queue *q = malloc(sizeof(queue));
	if(!q)
		return NULL;
	q->size = size;	
	q->front = -1;
	q->rear = -1;
	q->arr = malloc(q->size * sizeof(int));
	if (!q->arr)
		return NULL;
	return q;
}

/*
enqueue: This operation adds an element to the end of the queue.
dequeue: This operation removes the first element from the queue and returns it.
front: This operation returns the first element in the queue without removing it.
back: This operation returns the last element in the queue without removing it.
isempty: This operation checks whether the queue is empty.
isfull: This operation checks whether the queue is full.
size: This operation returns the number of elements in the queue.
display: show the whole queue.
delqueue: just delete the queue
*/

int isempty(queue *q)
{
	//if the condition is true return 1, else return 0.
	return(q->front == -1);
}

int isfull(queue *q)
{
	/*because the array using is circular, so %q->size is to check if the rear is warpover or not*/
	return((q->rear + 1) % q->size == q->front);
}

int size(queue *q)
{
	if ( (q->size + q->rear + 1 - q->front) % q->size == 0)
		return q->size;
	return ((q->size + q->rear + 1 - q->front) % q->size);
}

void enqueue(queue *q, int data)
{
	if(isfull(q))
	{
		printf("\nQueue overflow\n");
		return;
	}
	q->rear = (q->rear + 1) % q->size;
	q->arr[q->rear] = data;
	if (q->front == -1)
		q->front = q->rear;
}

int dequeue(queue *q)
{
	int data = 0;
	if(isempty(q))
	{
		printf("\nQueue underflow\n");
		return 0;
	}
	data = q->arr[q->front];
	if(q->front == q->rear)
	{
		q->front = q->rear =-1;
	}
	else
	{
		q->front = (q->front + 1) % q->size;
	}
	
	return data;
}

void delqueue(queue *q)
{
	if(q)
	{
		if(q->arr)
			free(q->arr);
		free(q);
	}
}

void display(queue *q)
{
	if(!q)
	{
		printf("\nNo queue to uwu.");
		return;
	}
	int i = q->front;
	int r = 0;
	printf("\n[");
	while (r < size(q))
	{
		printf(" %d ",q->arr[i]);
		i = (i + 1) % q->size;
		r++;	
	}
	printf("]\n");
	printf("Current size of queue: %d\n", size(q));
}

int main()
{
	queue *q = crequeue(10);
	enqueue(q,1);
	display(q);
	
	enqueue(q,2);
	display(q);
	enqueue(q,3);
	display(q);
	enqueue(q,4);
	display(q);
	
	printf("\n %d \n",dequeue(q));//expect the 1 to be moved out!
	display(q);
	
	enqueue(q,5);
	display(q);
	enqueue(q,6);
	display(q);
	enqueue(q,7);
	display(q);
	enqueue(q,8);
	display(q);
	enqueue(q,9);
	display(q);
	enqueue(q,10);
	display(q);
	
	//expect queue to be overflow
	enqueue(q,11);
	display(q);
	printf("\n %d \n",size(q));//check if the size function is correct.
	
	enqueue(q,69);
	display(q);
	
	dequeue(q);
	display(q);
	return 0;
}
