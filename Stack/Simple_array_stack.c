#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10	
#define EXCEPTION -6996420

//create ADT of Stack
typedef struct stack
{
	int top;
	int capacity;
	int *arr;
}stack;

//function for creating an stack
stack* creStack()
{
	stack *stk = malloc(sizeof(stack));
	if(!stk) //"stk==NULL" same logic?
		return NULL;
	stk->capacity = MAXSIZE;
	stk->top = -1;
	stk->arr = malloc(sizeof(int));
	if(!stk->arr)
		return NULL;
	return stk;
}

//fuction to check if stack is empty, full. If true return 1, false return 0.
int isEmpty(stack *s)
{
	return (s->top == -1);
}

int isFull(stack *s)
{
	return (s->top == s->capacity - 1); 
	//stack is basicly an array so need to -1 there
}

//insert element to stack
void push(stack *s,int data)
{
	if(isFull(s))
	{
		printf("Stack overflow.");
		return;
	}
	s->arr[++s->top] = data;
}

//delete element from stack
int pop(stack *s)
{
	if(isEmpty(s))
	{
		printf("Stack underflow you sussybaka.\n");
		return EXCEPTION; //have to return something not void so ...
	}
	return(s->arr[s->top--]);	
}

//delete stack
void delStack(stack *s)
{
	if(s)
	{
		if(s->arr)
			free(s->arr);
		free(s); //free an null pointer may cause error
		printf("Stack deleted.\n");
		return;
	}
	printf("\nNo stack to delete!\n");
}

int main()
{
	stack *a = creStack();
	printf("%d\n",pop(a));
//	delStack(a);
//	printf("%d\n",pop(a));
	push(a,10); //1
	push(a,11); //2
	push(a,2); //3
	push(a,3); //4
	push(a,4); //5
	push(a,5); //6
	push(a,6); //7
	push(a,7); //8
	push(a,9); //9
	push(a,9); //10 - stack should be full
	printf("%d\n",isFull(a));
	push(a,11);
	return 0;
}
