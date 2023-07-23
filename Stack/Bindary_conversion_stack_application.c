#include <stdio.h>
#include <stdlib.h>
#define EXCEPTION 404;

/*
stacks operation needed:
push()	pop()	delS()	isFull()	isEmpty()
*/

//ADT stacks - dynamic array stack
typedef struct stack
{
	int top;
	int limit;
	int *a;
}stack;

//creStack: create a stack, allocate memory for the stack and for the a pointer inside it
stack* creS()
{
	stack *s = malloc(sizeof(stack));
	if (!s)
		return NULL;
	s->limit = 1;
	s->top = -1;
	s->a = malloc(s->limit * sizeof(int));
	if (!s->a)
		return NULL;
	return s;
}

void doubleS(stack *s)
{
	s->limit *= 2;
	s->a = realloc(s->a, s->limit * sizeof(int));
}

int isFull(stack *s)
{
	return (s->top == s->limit - 1);
}

int isEmpty(stack *s)
{
	return (s->top == -1);
}

void push(stack *s, int data)
{
	if(isFull(s))
		doubleS(s);
	s->a[++s->top] = data;
}

int pop(stack *s)
{
	if (isEmpty(s))
	{
		printf("\nStack underflow\n"); //stack lowkey
		printf(" ,adPPYba, 8b,dPPYba, 8b,dPPYba,  ,adPPYba,  8b,dPPYba,  \n");
		printf("a8P_____88 88P'   \"Y8 88P'   \"Y8 a8\"     \"8a 88P'   \"Y8  \n");
		printf("8PP\"\"\"\"\"\"\" 88         88         8b       d8 88          \n");
		printf("\"8b,   ,aa 88         88         \"8a,   ,a8\" 88          \n");
		printf(" `\"Ybbd8\"' 88         88          `\"YbbdP\"'  88          \n");
		return EXCEPTION;
	}
	return (s->a[s->top--]);	
}

void deleteS(stack *s)
{
	if(s)
	{
		if (s->a)
			free(s->a);
		free(s);
		printf("\nStack deleted.");
		return;
	}
	printf("\nNo stack to delete.");
}



int main()
{
	stack *s = creS();
	push(s,1);
	push(s,2);
	printf("\n%d",pop(s));
	push(s,3);
	push(s,4);
	push(s,5);
	push(s,6);
	printf("\n%d",pop(s));
	printf("\n%d",pop(s));
	printf("\n%d",pop(s));
	printf("\n%d",pop(s));
	printf("\n%d",pop(s));
	printf("\n%d",pop(s));	
	return 0;
}
